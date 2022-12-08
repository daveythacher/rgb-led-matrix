#include <assert.h>
#include "framebuffer/HUB75/BCM/BCM.h"
#include "port/pin-mapper/HUB75/HUB75_Pins.h"

namespace rgb_matrix {
    extern struct PinMapping *hardware_mapping_;

    template <typename T> BCM<T>::BCM(Canvas_ID id, CFG *cfg) 
        : Framebuffer<T>(id, cfg) {
            io = new GPIO();
            InitGPIO();
            *pin_mappings = HUB75_pin_mappings;
    }
    
    template <typename T> void BCM<T>::DumpToMatrix() {
        // TODO: Send buffer to GPIO
        //  Create thread class in port API
    }

    template <typename T> inline void  BCM<T>::MapColors(uint8_t r, uint8_t g, uint8_t b, uint16_t *red, uint16_t *green, uint16_t *blue) {
        // TODO: RGB Gamma, Brightness, Dot correction, CIE1931, etc.
    }

    template <typename T> void BCM<T>::InitGPIO() {
        const struct HUB75_Pins &h =  *((struct HUB75_Pins *) hardware_mapping_);
        gpio_bits_t all_used_bits = h.clk | h.lat | h.flag | h.interrupt;
        
        switch (h.num) {
            case 3:
                all_used_bits |= h.p2.r0 | h.p2.g0 | h.p2.b0 | h.p2.r1 | h.p2.g1 | h.p2.b1;
            case 2:
                all_used_bits |= h.p1.r0 | h.p1.g0 | h.p1.b0 | h.p1.r1 | h.p1.g1 | h.p1.b1;
            case 1:
                all_used_bits |= h.p0.r0 | h.p0.g0 | h.p0.b0 | h.p0.r1 | h.p0.g1 | h.p0.b1;
            default:
                break;
        }

        const gpio_bits_t result = io->InitOutputs(all_used_bits);
        assert(result == all_used_bits); 
    }

    template class BCM<PixelDesignator_HUB75>;
}