#ifndef LOGGER_H
#define LOGGER_H

namespace rgb_matrix {
    class Logger {
        public:
            enum Level {
                DEBUG,
                INFO,
                WARN,
                ERROR
            };

            virtual void write(Level level, const char *str) = 0;

            static Logger *get_logger();

        protected: // TODO: Make private
            static Logger *logger_;
    };
}
#endif
