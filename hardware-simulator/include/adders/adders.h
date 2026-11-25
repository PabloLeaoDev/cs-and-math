#ifndef ADDERS_H
#define ADDERS_H

#include <busbar/bus.h>
#include <gates/gates.h>

typedef struct {
  bit_t sum;
  bit_t carry;
} AdderResult;

typedef struct {
  bus8_t sum;
  bit_t carry_out; // overflow
} AdderResult8;

AdderResult half_adder(bit_t a, bit_t b);
AdderResult full_adder(bit_t a, bit_t b, bit_t carry_in);
AdderResult8 ripple_adder_8bit(bus8_t a, bus8_t b, bit_t carry_in);

#endif
