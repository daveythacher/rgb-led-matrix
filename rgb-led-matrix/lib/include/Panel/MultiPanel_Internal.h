#ifndef MULTIPANEL_INTERNAL_H
#define MULTIPANEL_INTERNAL_H

#include <mutex>
#include <list>
#include <Panel/MultiPanel.h>
#include <IO/Scheduler/Scheduler.h>
#include <ThreadPool/ThreadPool.h>

namespace rgb_matrix {
    class MultiPanel_Internal : public MultiPanel {
        public:
            MultiPanel_Internal(uint16_t width, uint16_t height);
            ~MultiPanel_Internal();

            bool map_panel(uint16_t x, uint16_t y, Direction direction, Simple_Panel *panel, Protocol *protocol);

            void SetPixel(uint16_t x, uint16_t y, uint8_t red, uint8_t green, uint8_t blue);
            cord_t get_size();
            void show();
            void set_brightness(uint8_t brightness);
            void map_wavelength(uint8_t color, Color index, uint16_t value);

        protected:
            MultiPanel_Internal();

            struct Panel_t {
                Simple_Panel *panel;
                uint16_t x;
                uint16_t y;
                Direction direction;
                Protocol *protocol;
            };

            struct show_packet {
                MultiPanel_Internal *object;
                Panel_t *panel;
            };

            struct map_wavelength_packet {
                Panel_t *panel;
                uint8_t color;
                Color index;
                uint16_t value;
            };

            struct set_brightness_packet {
                Panel_t *panel;
                uint8_t brightness;
            };

            static void show_worker(void *result, show_packet args);
            static void map_wavelength_worker(void *result, map_wavelength_packet args);
            static void set_brightness_worker(void *result, set_brightness_packet args);

            static ThreadPool<void *, show_packet> *get_show_thread_pool();
            static ThreadPool<void *, map_wavelength_packet> *get_map_wavelength_thread_pool();
            static ThreadPool<void *, set_brightness_packet> *get_set_brightness_thread_pool();

            static constexpr uint32_t num_threads = 4;
            static ThreadPool<void *, show_packet> *show_thread_pool_;
            static ThreadPool<void *, set_brightness_packet> *set_brightness_thread_pool_;
            static ThreadPool<void *, map_wavelength_packet> *map_wavelength_thread_pool_;

            uint16_t width_;
            uint16_t height_;
            std::mutex lock_;
            std::list<Panel_t *> *panel_;
            pixel_t **pixel_;
            Scheduler *scheduler_;
    };
}
#endif