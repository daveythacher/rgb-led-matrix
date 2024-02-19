#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <list>
#include <mutex>
#include <IO/Protocol/Protocol.h>

namespace rgb_matrix {
    class Scheduler {
        public:
            void start();
            bool add_protocol(Protocol *protocol);

        protected:
            std::list<Protocol *> protocols_;
            std::mutex lock_;
    };
}
#endif