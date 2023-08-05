#include <math.h>
#include "framebuffer/external/external.h"
#include "framebuffer/external/RP2040/RP2040_UART/RP2040_UART.h"

namespace rgb_matrix {
    template <typename T> RP2040_UART<T>::RP2040_UART(CFG *cfg) : Framebuffer<T>(cfg) {
            build_table(cfg->get_gamma(), cfg_->use_CIE1931());
            
            shutdown_ = false;
            start_ = false;
            thread_ = new std::thread(&RP2040_UART<T>::worker_thread, this);
    }

    template <typename T> RP2040_UART<T>::~RP2040_UART() {
        shutdown_ = true;

        if (thread_ != nullptr)
            thread_->join();
    }
    
    template <typename T> void RP2040_UART<T>::show() {
        start_ = true;

        while (start_);
    }

    // Handles dot correction and PWM bit scaling
    template <> inline void  RP2040_UART<RGB48>::MapColors(int x, int y, uint8_t r, uint8_t g, uint8_t b, RGB48 *pixel) {
        float fr, fg, fb;
        uint8_t bright =  brightness_;

        cfg_->get_dot().get(x, y, r, g, b, &fr, &fg, &fb);
        pixel->red = (uint16_t) round(lut[r][bright].red / 65535.0 * fr * cfg_->get_pwm_bits());
        pixel->green = (uint16_t) round(lut[g][bright].green / 65535.0 * fg * cfg_->get_pwm_bits());
        pixel->blue = (uint16_t) round(lut[b][bright].blue / 65535.0 * fb * cfg_->get_pwm_bits());
    }

    template <typename T> void RP2040_UART<T>::worker_thread(RP2040_UART<T> *object) {
        uint32_t size = sizeof(T) * object->cfg_->get_cols() * object->cfg_->get_rows();
        char *start = (char *) "s";
        char *idle = (char *) "i";

        while (object->shutdown_) {
            if (object->start_) {
                // Send active tocken to get buss out of idle
                object->cfg_->get_node()->write(start, 1);

                // Wait for bus to become active (timout after 100uS and drop frame)
                for (int i = 0; i < 10; i++) {
                    // If it times out then the bus is idle, send frame
                    if (object->cfg_->get_node()->read(&idle, 1, 10) == 0) {
                        object->cfg_->get_node()->write((char *) object->buffer_, size);

                        // Check for idle loop, recover if still active
                        while (object->cfg_->get_node()->read(&idle, 1, 100) == 0)
                            object->cfg_->get_node()->write(idle, 1);
                    
                        break;
                    }
                }

                object->start_ = false;
            }
        }
    }

    template class RP2040_UART<RGB48>;
}