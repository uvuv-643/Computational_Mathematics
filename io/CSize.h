//
// Created by artem on 10.02.2023.
//

#ifndef VM1_CSIZE_H
#define VM1_CSIZE_H

#include "CInt.h"

class CSize : public CInt {
public:
    CSize();
    CSize(int32_t _value);
    friend istream &operator>>(istream &is, CSize &data);
};


#endif //VM1_CSIZE_H
