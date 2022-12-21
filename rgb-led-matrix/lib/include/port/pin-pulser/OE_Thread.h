#ifndef OE_THREAD_H
#define OE_THREAD_H

#include "port/thread/Thread.h"
#include "port/gpio/gpio.h"
#include "CFG/CFG.h"
#include "port/pin-mapper/PinMapping.h"

namespace rgb_matrix {
    template <typename T, typename R> class OE_Thread : public Thread {
        public:
            OE_Thread(T *pins);
            virtual ~OE_Thread() {}

            static Thread *CreateThread(CFG *cfg, PinMapping *pins);

        protected:
            void Run();

            GPIO *io_;
            T *pins_;
    };
}

#endif