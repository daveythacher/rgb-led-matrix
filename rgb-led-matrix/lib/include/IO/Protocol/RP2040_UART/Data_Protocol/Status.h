#ifndef RP2040_UART_DATA_PROTOCOL_STATUS_H
#define RP2040_UART_DATA_PROTOCOL_STATUS_H

#include <stdint.h>
#include <thread>
#include <IO/Node/Node.h>

namespace rgb_matrix::Protocol::RP2040_UART {
    class Status {
        public:
            Status(Node *node, uint8_t magic);
            ~Status();

            enum class STATUS {
                IDLE_0,
                IDLE_1,
                ACTIVE_0,
                ACTIVE_1,
                READY
            };

            bool get_status(STATUS current, STATUS expected);
            STATUS get_status();
        
        protected:
            Status();

            static void worker(Status *obj);
            STATUS translate_id(uint32_t id);

            STATUS status_;
            std::thread *thread_;
            rgb_matrix::Node *node_;
            bool shutdown_;
            uint8_t magic_;
    };
}
#endif
