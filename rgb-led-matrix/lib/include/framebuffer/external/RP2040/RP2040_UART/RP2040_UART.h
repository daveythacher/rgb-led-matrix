#ifndef RP2040_UART_H
#define RP2040_UART_H

#include <vector>
#include <thread>
#include "framebuffer/Framebuffer.h"
#include "CFG/external/RP2040/RP2040_UART/RP2040_UART_CFG.h"

namespace rgb_matrix {
    template <typename T> class RP2040_UART: public Framebuffer<T> {
        public:
            RP2040_UART(CFG *cfg);
            ~RP2040_UART();

        protected:
            virtual void show_internal();
            virtual void  MapColors(int x, int y, uint8_t r, uint8_t g, uint8_t b, T *pixel);

        private:
            static void worker_thread(RP2040_UART<T> *object);
            void build_table(GAMMA g, bool use_CIE1931);

            RP2040_UART_CFG *cfg_;
            std::thread *thread_;
            volatile bool shutdown_;
            volatile bool start_;
    };
}

#endif