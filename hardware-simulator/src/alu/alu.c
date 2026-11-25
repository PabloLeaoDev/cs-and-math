#include <alu/alu.h>

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

ALUResult8 alu_8bit(bus8_t a, bus8_t b, bit_t op0, bit_t op1, bit_t sub) {
  ALUResult8 out;
  bit_t current_carry = sub; // If sub == 1, sum +1 in LSB (2's complement)
  bit_t any_bit_set = 0;

  for (int i = 0; i < 8; i++) {
    // If sub == 1, invert the bit of B using XOR (b ^ 1 == ~b)
    bit_t b_mod = gate_xor(b.bits[i], sub);

    ALUResult1Bit bit_res = alu_1bit(a.bits[i], b_mod, current_carry, op0, op1);

    out.result.bits[i] = bit_res.result;
    current_carry = bit_res.carry_out;

    any_bit_set = gate_or(any_bit_set, bit_res.result);
  }

  out.carry_out = current_carry;
  out.zero = gate_not(any_bit_set);  // Zero is 1 if, and only if, not bit is 1
  out.negative = out.result.bits[7]; // Signal bit (2's complement)

  return out;
}
