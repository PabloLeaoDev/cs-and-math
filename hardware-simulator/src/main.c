#include <adders/02_adders.h>
#include <alu/03_alu.h>
#include <busbar/00_bus.h>
#include <stdio.h>

int main() {
  bus8_t a = uint8_to_bus(15);
  bus8_t b = uint8_to_bus(10);

  ALUResult8 soma = alu_8bit(a, b, 1, 1, 0);
  printf("15 + 10 = %d (Zero: %d)\n", bus_to_uint8(soma.result), soma.zero);

  ALUResult8 sub = alu_8bit(a, a, 1, 1, 1);
  printf("15 - 15 = %d (Zero: %d)\n", bus_to_uint8(sub.result), sub.zero);

  return 0;
}
