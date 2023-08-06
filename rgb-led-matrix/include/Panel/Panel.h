#ifndef PANEL_H
#define PANEL_H

#include <stdint.h>
#include "CFG/types.h"

namespace rgb_matrix {
  class Panel {
    public:
      virtual ~Panel() {}

      virtual void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) = 0;
      virtual void SetPixel(cord_t cord, pixel_t pixel) { SetPixel(cord.x, cord.y, pixel.red, pixel.green, pixel.blue); }
      virtual void show() = 0;
      virtual cord_t get_size() = 0;

      // Applies to SetPixel calls after set
      virtual void set_brightness(uint8_t brightness) = 0;
  };
}
#endif
