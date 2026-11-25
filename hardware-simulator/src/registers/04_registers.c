#include <registers/04_registers.h>

void ff_d_init(FlipFlopD *ff) {
  ff->q = 0;
  ff->prev_clk = 0;
}

bit_t ff_d_tick(FlipFlopD *ff, bit_t d, bit_t clk) {
  bit_t rising_edge = gate_and(gate_not(ff->prev_clk), clk);

  ff->q = mux_2to1(ff->q, d, rising_edge);
  ff->prev_clk = clk & 1;

  return ff->q;
}

void reg8_init(Register8 *reg) {
  for (int i = 0; i < 8; i++) {
    ff_d_init(&reg->bits[i]);
  }
}

bus8_t reg8_tick(Register8 *reg, bus8_t data_in, bit_t load, bit_t clk) {
  bus8_t out;

  for (int i = 0; i < 8; i++) {
    bit_t d_input = mux_2to1(reg->bits[i].q, data_in.bits[i], load);
    out.bits[i] = ff_d_tick(&reg->bits[i], d_input, clk);
  }

  return out;
}

bus8_t reg8_read(const Register8 *reg) {
  bus8_t out;
  for (int i = 0; i < 8; i++) {
    out.bits[i] = reg->bits[i].q;
  }
  return out;
}
