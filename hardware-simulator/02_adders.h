#ifndef ADDERS_H
#define ADDERS_H

#include "01_gates.h"

typedef struct {
  bit_t sum;
  bit_t carry;
} AdderResult;

AdderResult half_adder(bit_t a, bit_t b);
AdderResult full_adder(bit_t a, bit_t b, bit_t carry_in);

#endif
