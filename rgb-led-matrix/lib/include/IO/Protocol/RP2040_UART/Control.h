#ifndef RP2040_UART_CONTROL_H
#define RP2040_UART_CONTROL_H

#include <IO/Protocol/Protocol.h>

namespace rgb_matrix {
    class Control {
        public:
            Control(Node *node, uint8_t magic = 0xAE);

            void signal(Protocol::Commands command);

        protected:
            Control();

            struct Control_Message {
                public:
                    Control_Message(Protocol::Commands command, uint8_t magic);

                    uint32_t header;
                    uint8_t cmd;
                    uint16_t len;
                    uint8_t id;
                    uint32_t checksum;
                    uint32_t delimiter;

                private:
                    uint32_t compute_checksum();
            };

            void write(uint32_t val, uint8_t bits);

            Node *node_;
            uint8_t magic_;
    };
}
#endif