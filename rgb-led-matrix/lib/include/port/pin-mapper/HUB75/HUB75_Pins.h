#ifndef HUB75_PIN_MAPPING_H
#define HUB75_PIN_MAPPING_H

#include "port/pin-mapper/PinMapping.h"

namespace rgb_matrix {
  struct HUB75_t {
    HUB75_t(gpio_bits_t r0, gpio_bits_t g0, gpio_bits_t b0, gpio_bits_t r1, gpio_bits_t g1, gpio_bits_t b1)
      : r0(1 << r0), g0(1 << g0), b0(1 << b0), r1(1 << r1), b1(1 << b1), g1(1 << g1) {}

    const gpio_bits_t r0;
    const gpio_bits_t g0;
    const gpio_bits_t b0;
    const gpio_bits_t r1;
    const gpio_bits_t g1;
    const gpio_bits_t b1;
  };

  struct HUB75_Pins : public PinMapping {
    public:
      HUB75_Pins(const char *name, gpio_bits_t clk, gpio_bits_t lat, HUB75_t p, gpio_bits_t flag, gpio_bits_t interrupt, gpio_bits_t reset)
        : PinMapping(name), clk(1 << clk), lat(1 << lat), num(1), p0(p), p1(p), p2(p), flag(1 << flag), interrupt(1 << interrupt), reset(1 << reset) {}

      HUB75_Pins(const char *name, gpio_bits_t clk, gpio_bits_t lat, HUB75_t p0, HUB75_t p1, gpio_bits_t flag, gpio_bits_t interrupt, gpio_bits_t reset)
        : PinMapping(name), clk(1 << clk), lat(1 << lat), num(2), p0(p0), p1(p1), p2(p0), flag(1 << flag), interrupt(1 << interrupt), reset(1 << reset) {}

      HUB75_Pins(const char *name, gpio_bits_t clk, gpio_bits_t lat, HUB75_t p0, HUB75_t p1, HUB75_t p2, gpio_bits_t flag, gpio_bits_t interrupt, gpio_bits_t reset)
        : PinMapping(name), clk(1 << clk), lat(1 << lat), num(3), p0(p0), p1(p1), p2(p2), flag(1 << flag), interrupt(1 << interrupt), reset(1 << reset) {}


      const gpio_bits_t clk;
      const gpio_bits_t lat;
      const gpio_bits_t flag;
      const gpio_bits_t interrupt;
      const gpio_bits_t reset;      // This not the actual reset
      const HUB75_t p0;
      const HUB75_t p1;
      const HUB75_t p2;
      const uint8_t num;
  };

  extern HUB75_Pins HUB75_pin_mappings[];
  extern const uint32_t HUB75_pin_mappings_size;
}

#endif
