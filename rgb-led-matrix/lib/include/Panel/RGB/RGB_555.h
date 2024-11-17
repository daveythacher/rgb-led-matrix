#ifndef FRAMEBUFFER_RGB_555_H
#define FRAMEBUFFER_RGB_555_H

#include <stdint.h>

namespace rgb_matrix {
    struct RGB_555 {
        public:
            RGB_555() : val(0) {}

            uint8_t get_red() { return val & 0x1F; }
            uint8_t get_green() { return (val >> 5) & 0x1F; }
            uint8_t get_blue() { return (val >> 10) & 0x1F; }

            void set_red(uint16_t v) { 
                val &= ~0x1F;
                val |= v & 0x1F; 
            }

            void set_green(uint16_t v) { 
                val &= ~(0x1F << 5);
                val |= (v & 0x1F) << 5; 
            }

            void set_blue(uint16_t v) { 
                val &= ~(0x1F << 10);
                val |= (v & 0x1F) << 10; 
            }

            static constexpr uint32_t red_lim = 5;
            static constexpr uint32_t green_lim = 5;
            static constexpr uint32_t blue_lim = 5;

            static constexpr float red_max = 31.0;
            static constexpr float green_max = 31.0;
            static constexpr float blue_max = 31.0;
        
        private:
            uint16_t val;
    };
}

#endif