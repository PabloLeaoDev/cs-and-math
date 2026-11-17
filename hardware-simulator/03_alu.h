#include "02_adders.h"

typedef struct {
  bit_t result;
  bit_t carry_out;
} ALUResult1Bit;

ALUResult1Bit alu_1bit(bit_t a, bit_t b, bit_t carry_in, bit_t op0, bit_t op1);
