#include "Exception/Null_Pointer.h"

namespace rgb_matrix {
    // Do not use this!
    Null_Pointer::Null_Pointer() : String_Exception() {
        prefix_ = "Null Pointer: ";
    }

    Null_Pointer::Null_Pointer(const char *str, bool log) : String_Exception(str, log) {
        // Do nothing
    }
}