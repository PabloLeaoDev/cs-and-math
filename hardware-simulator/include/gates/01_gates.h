#ifndef GATES_H
#define GATES_H

#include <stdint.h>

typedef uint8_t bit_t;

bit_t gate_not(bit_t a);
bit_t gate_and(bit_t a, bit_t b);
bit_t gate_or(bit_t a, bit_t b);
bit_t gate_xor(bit_t a, bit_t b);
bit_t mux_2to1(bit_t a, bit_t b, bit_t sel);

#endif
