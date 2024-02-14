#ifndef NODE_H
#define NODE_H

#include <stdint.h>
#include <IO/Protocol/Protocol.h>

namespace rgb_matrix {
    class Node {
        public:
            Node() : protocol_(nullptr) {}
            virtual ~Node() {}

            // For Protocol
            virtual void write(char *buf, uint32_t len) = 0;
            virtual int read(char **buf, uint32_t len, uint32_t timeout_us) = 0;

            // For Panel (Framebuffer)
            virtual void send(uint8_t *buf, uint32_t size) = 0;

            // For Scheduler
            virtual void set_protocol(Protocol *protocol) { protocol_ = protocol; }
            virtual void acknowledge(Protocol::Status) = 0;
            virtual Protocol::Status get_protocol_status() = 0;

        protected:
            Protocol *protocol_;
    };
}
#endif
