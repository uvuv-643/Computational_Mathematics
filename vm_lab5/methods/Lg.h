//
// Created by artem on 01.05.2023.
//

#ifndef VM1_LG_H
#define VM1_LG_H

#include "../../data_structures/CTable.h"
#include "../../discrete_functions/DiscreteFunction.h"

class Lg {

public:

    static CDouble performMethod(DiscreteFunction &df, CDouble target_x);

};


#endif //VM1_LG_H
