#ifndef LEDPANEL_H
#define LEDPANEL_H

#include "Panel.h"
#include "framebuffer/framebuffer.h"

namespace rgb_matrix {
  template <typename T> class LEDPanel : public Panel {
    public:
      LEDPanel(Framebuffer<T> *frame) : frame_(frame) {}
      virtual ~LEDPanel();

      virtual void SetPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
      virtual void Fill(uint8_t red, uint8_t green, uint8_t blue);

      virtual void show();

    protected:
      Framebuffer<T> *const frame_;
  };
}
#endif