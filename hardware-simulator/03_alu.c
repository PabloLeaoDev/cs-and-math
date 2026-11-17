#include "03_alu.h"

ALUResult1Bit alu_1bit(bit_t a, bit_t b, bit_t carry_in, bit_t op0, bit_t op1) {
  bit_t res_and = gate_and(a, b);
  bit_t res_or = gate_or(a, b);
  bit_t res_xor = gate_xor(a, b);
  AdderResult res_add = full_adder(a, b, carry_in);

  bit_t mux_low = mux_2to1(res_and, res_or, op0);
  bit_t mux_high = mux_2to1(res_xor, res_add.sum, op0);

  ALUResult1Bit out;
  out.result = mux_2to1(mux_low, mux_high, op1);
  out.carry_out = res_add.carry;
  return out;
}
