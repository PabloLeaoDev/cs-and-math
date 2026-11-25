#ifndef BUS_H
#define BUS_H

#include <gates/gates.h>

typedef struct {
  bit_t bits[8]; // bits[0] = LSB, bits[7] = MSB
} bus8_t;

// converters
bus8_t uint8_to_bus(uint8_t val);
uint8_t bus_to_uint8(bus8_t bus);

#endif
