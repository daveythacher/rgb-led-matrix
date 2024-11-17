#ifndef FRAMEBUFFER_RGB_232_H
#define FRAMEBUFFER_RGB_232_H

#include <stdint.h>

namespace rgb_matrix {
    struct RGB_222 {
        public:
            RGB_222() : val(0) {}

            uint8_t get_red() { return val & 0x3; }
            uint8_t get_green() { return (val >> 2) & 0x3; }
            uint8_t get_blue() { return (val >> 4) & 0x3; }

            void set_red(uint16_t v) { 
                val &= ~0x3;
                val |= v & 0x3; 
            }

            void set_green(uint16_t v) { 
                val &= ~(0x3 << 2);
                val |= (v & 0x3) << 2; 
            }

            void set_blue(uint16_t v) { 
                val &= ~(0x3 << 4);
                val |= (v & 0x3) << 4; 
            }

            static constexpr uint32_t red_lim = 2;
            static constexpr uint32_t green_lim = 2;
            static constexpr uint32_t blue_lim = 2;

            static constexpr float red_max = 3.0;
            static constexpr float green_max = 3.0;
            static constexpr float blue_max = 3.0;

        private:
            uint8_t val;
    };
}

#endif