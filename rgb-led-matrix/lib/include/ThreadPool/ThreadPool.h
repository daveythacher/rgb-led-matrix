#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace rgb_matrix {
    class Runnable {
        public:
            Runnable() {}
            virtual ~Runnable() {}

            virtual void run() = 0;
    };

    class ThreadPool {
        public:
            enum class Pool_ID {
                Drawer,
                IO
            };

            static ThreadPool *get_threadpool(Pool_ID id);
            void submit(Runnable *t);

        private:
            ThreadPool();

            static void ThreadLoop(ThreadPool *object);

            std::mutex lock_;
            std::condition_variable conditional_;
            std::vector<std::thread> threads_;
            std::queue<Runnable *> work_queue_;
            static ThreadPool *pool_[2];
    };
}
#endif
