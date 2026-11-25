#include <adders/adders.h>

AdderResult half_adder(bit_t a, bit_t b) {
  AdderResult res;
  res.sum = gate_xor(a, b);
  res.carry = gate_and(a, b);
  return res;
}

AdderResult full_adder(bit_t a, bit_t b, bit_t carry_in) {
  AdderResult ha1 = half_adder(a, b);
  AdderResult ha2 = half_adder(ha1.sum, carry_in);

  AdderResult res;
  res.sum = ha2.sum;
  res.carry = gate_or(ha1.carry, ha2.carry);
  return res;
}

AdderResult8 ripple_adder_8bit(bus8_t a, bus8_t b, bit_t carry_in) {
  AdderResult8 res;
  bit_t current_carry = carry_in;

  for (int i = 0; i < 8; i++) {
    AdderResult step = full_adder(a.bits[i], b.bits[i], current_carry);
    res.sum.bits[i] = step.sum;
    current_carry = step.carry;
  }

  res.carry_out = current_carry;
  return res;
}
