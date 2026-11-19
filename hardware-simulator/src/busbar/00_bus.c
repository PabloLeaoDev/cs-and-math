#include <busbar/00_bus.h>

bus8_t uint8_to_bus(uint8_t val) {
  bus8_t bus;
  for (int i = 0; i < 8; i++) {
    bus.bits[i] = (val >> i) & 1;
  }
  return bus;
}

uint8_t bus_to_uint8(bus8_t bus) {
  uint8_t val = 0;
  for (int i = 0; i < 8; i++) {
    val |= (bus.bits[i] << i);
  }
  return val;
}
