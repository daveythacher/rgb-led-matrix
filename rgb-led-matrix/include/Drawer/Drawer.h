#ifndef DRAWER_H
#define DRAWER_H

#include <stdint.h>
#include "CFG/Types/types.h"

namespace rgb_matrix {
    // Pure interface for drawing
    class Drawer {
        public:
            virtual void SetPixel(cord_t cord, pixel_t pixel) = 0;
            virtual cord_t get_size() = 0;
            virtual void set_brightness(uint8_t brightness) = 0;
            virtual void map_wavelength(uint8_t color, Color index, uint16_t value) = 0;
            virtual void map_dot_correct(cord_t pos, uint8_t color, Color index, float value) = 0;
    };
}
#endif
