//
// Created by artem on 19.03.2023.
//

#include "CFunction.h"

ostream &operator<<(ostream &os, const CFunction &function) {
    os << function.function_definition;
    return os;
}
