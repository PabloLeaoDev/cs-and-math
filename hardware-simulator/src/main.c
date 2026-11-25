#include <adders/adders.h>
#include <alu/alu.h>
#include <busbar/bus.h>
#include <registers/registers.h>
#include <stdio.h>

void ALUTester();
void RegisterTester();

int main() {
  int choice = 0;

  while (1) {
    printf("======OPTIONS======\n"
           "1. ALU Test\n"
           "2. Resgister Test\n"
           "===================\n"
           "Choose a test option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      ALUTester();
      break;
    case 2:
      RegisterTester();
      break;
    default:
      printf("Choose a valid option.\n");
    }

    if (choice == 1 || choice == 2) {
      break;
    }
  }

  return 0;
}

void ALUTester() {
  bus8_t a = uint8_to_bus(15);
  bus8_t b = uint8_to_bus(10);

  ALUResult8 sum = alu_8bit(a, b, 1, 1, 0);
  printf("15 + 10 = %d (Zero: %d)\n", bus_to_uint8(sum.result), sum.zero);

  ALUResult8 sub = alu_8bit(a, a, 1, 1, 1);
  printf("15 - 15 = %d (Zero: %d)\n", bus_to_uint8(sub.result), sub.zero);
}

void RegisterTester() {
  Register8 regA;
  reg8_init(&regA);

  bus8_t data1 = uint8_to_bus(42);
  bus8_t data2 = uint8_to_bus(99);

  // 1. Prepare data1 at the input with load = 1, but the clock is still at 0
  reg8_tick(&regA, data1, 1, 0);
  printf("Before clock (clk=0): %d\n",
         bus_to_uint8(reg8_read(&regA))); // Expected output: 0

  // 2. Clock rising edge (0 -> 1): records data1
  reg8_tick(&regA, data1, 1, 1);
  printf("Rising edge (clk=1, load=1): %d\n",
         bus_to_uint8(reg8_read(&regA))); // Expected output: 42

  // 3. Falling edge (1 -> 0)
  reg8_tick(&regA, data2, 1, 0);

  // 4. New clock pulse (0 -> 1), with load = 0 (ignore data2)
  reg8_tick(&regA, data2, 0, 1);
  printf("Rising edge (clk=1, load=0): %d\n",
         bus_to_uint8(reg8_read(&regA))); // Expected output: 42
}
