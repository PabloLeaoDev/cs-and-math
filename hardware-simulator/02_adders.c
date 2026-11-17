#include "02_adders.h"

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
