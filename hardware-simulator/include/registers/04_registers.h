#ifndef REGISTERS_H
#define REGISTERS_H

#include <busbar/00_bus.h>
#include <gates/01_gates.h>

typedef struct {
  bit_t q;        // current state
  bit_t prev_clk; // previous clock state for edge detection
} FlipFlopD;

// 8 bits register with Load (Write Enable)
typedef struct {
  FlipFlopD bits[8];
} Register8;

void ff_d_init(FlipFlopD *ff);
void reg8_init(Register8 *reg);

bit_t ff_d_tick(FlipFlopD *ff, bit_t d, bit_t clk);
bus8_t reg8_tick(Register8 *reg, bus8_t data_in, bit_t load, bit_t clk);

bus8_t reg8_read(const Register8 *reg);

#endif
