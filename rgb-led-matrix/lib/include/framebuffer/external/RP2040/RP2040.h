#ifndef RP2040_H
#define RP2040_H

#include <vector>
#include "framebuffer/Framebuffer.h"
#include "CFG/RP2040/RP2040_CFG.h"

namespace rgb_matrix {
    template <typename T> class RP2040: public Framebuffer<T> {
        public:
            RP2040(CFG *cfg);

            virtual void DumpToMatrix();

        protected:
            virtual void  MapColors(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint16_t *red, uint16_t *green, uint16_t *blue);

        private:
            void build_table(GAMMA g, bool use_CIE1931);

            uint16_t lut[256][100][3];
            RP2040_CFG *cfg_;
    };
}

#endif