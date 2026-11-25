#include <adders/adders.h>

typedef struct {
  bit_t result;
  bit_t carry_out;
} ALUResult1Bit;

typedef struct {
  bus8_t result;
  bit_t zero;      // 1 if all result bit are 0
  bit_t carry_out; // final sum/sub Carry
  bit_t negative;  // reflects the MSB (bits[7])
} ALUResult8;

ALUResult1Bit alu_1bit(bit_t a, bit_t b, bit_t carry_in, bit_t op0, bit_t op1);
ALUResult8 alu_8bit(bus8_t a, bus8_t b, bit_t op0, bit_t op1, bit_t sub);
