#ifndef RP2040_UART_INTERNAL_H
#define RP2040_UART_INTERNAL_H

#include <stdint.h>

namespace rgb_matrix {
    class internal {
        public:
            static uint32_t generate_header(uint8_t magic);
            static uint32_t generate_delimiter(uint8_t magic);
    };
}
#endif