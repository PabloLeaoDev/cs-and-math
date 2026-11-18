#include <gates/01_gates.h>

bit_t gate_not(bit_t a) { return (~a); }
bit_t gate_and(bit_t a, bit_t b) { return (a & b); }
bit_t gate_or(bit_t a, bit_t b) { return (a | b); }
bit_t gate_xor(bit_t a, bit_t b) { return (a ^ b); }

bit_t mux_2to1(bit_t a, bit_t b, bit_t sel) {
  return gate_or(gate_and(a, gate_not(sel)), gate_and(b, sel));
}
