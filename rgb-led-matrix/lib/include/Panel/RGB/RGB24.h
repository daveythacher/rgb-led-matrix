#ifndef FRAMEBUFFER_RGB24_H
#define FRAMEBUFFER_RGB24_H

#include <stdint.h>

namespace rgb_matrix {
    struct RGB24 {
        public:
            RGB24() : red(0), green(0), blue(0) {}
            
            uint8_t get_red() { return red; }
            uint8_t get_green() { return green; }
            uint8_t get_blue() { return blue; }
            void set_red(uint16_t v) { red = v & 0xFF; }
            void set_green(uint16_t v) { green = v & 0xFF; }
            void set_blue(uint16_t v) { blue = v & 0xFF; }

            static constexpr uint32_t red_lim = 8;
            static constexpr uint32_t green_lim = 8;
            static constexpr uint32_t blue_lim = 8;

            static constexpr float red_max = 255.0;
            static constexpr float green_max = 255.0;
            static constexpr float blue_max = 255.0;

        private:
            uint8_t red;
            uint8_t green;
            uint8_t blue;
    };
}

#endif