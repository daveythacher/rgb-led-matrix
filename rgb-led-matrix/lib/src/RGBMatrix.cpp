#include "RGBMatrix.h"
#include "Panel/Panel_Internal.h"
#include "Panel/MultiPanel_Internal.h"
#include "Exception/Unknown_Type.h"
#include "Exception/Null_Pointer.h"
#include "Panel/RGB/RGB24.h"
#include "Panel/RGB/RGB48.h"
#include "Panel/RGB/RGB_555.h"
#include "Panel/RGB/RGB_222.h"

namespace rgb_matrix {
    Panel *RGBMatrix::Create_Panel(CFG *cfg) {
        if (cfg == nullptr)
            throw Null_Pointer("RGBMatrix: Cannot create panel without configuration.");

        switch (cfg->get_data_format()) {
            case Data_Format_ID::RGB48_ID:
                return new Panel_Internal<RGB48>(cfg);
            case Data_Format_ID::RGB24_ID:
                return new Panel_Internal<RGB24>(cfg);
            case Data_Format_ID::RGB_222_ID:
                return new Panel_Internal<RGB_222>(cfg);
            case Data_Format_ID::RGB_555_ID:
                return new Panel_Internal<RGB_555>(cfg);
            default:
                throw Unknown_Type("RGBMatrix: Data Format ID is not defined");
                break;
        }
    }

    MultiPanel *RGBMatrix::Create_MultiPanel(uint16_t width, uint16_t height) {
        return new MultiPanel_Internal(width, height);
    }
 };
