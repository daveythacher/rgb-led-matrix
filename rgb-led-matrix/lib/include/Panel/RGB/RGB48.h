#ifndef FRAMEBUFFER_RGB48_H
#define FRAMEBUFFER_RGB48_H

#include <stdint.h>

namespace rgb_matrix {
    struct RGB48 {
        public:
            RGB48() : red(0), green(0), blue(0) {}

            uint16_t get_red() { return red; }
            uint16_t get_green() { return green; }
            uint16_t get_blue() { return blue; }
            void set_red(uint16_t v) { red = v; }
            void set_green(uint16_t v) { green = v; }
            void set_blue(uint16_t v) { blue = v; }

            static constexpr uint32_t red_lim = 16;
            static constexpr uint32_t green_lim = 16;
            static constexpr uint32_t blue_lim = 16;

            static constexpr float red_max = 65535.0;
            static constexpr float green_max = 65535.0;
            static constexpr float blue_max = 65535.0;

        private:
            uint16_t red;
            uint16_t green;
            uint16_t blue;
    };
}

#endif