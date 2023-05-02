//
// Created by artem on 02.05.2023.
//

#ifndef VM1_ST_H
#define VM1_ST_H

#include "../../data_structures/CTable.h"
#include "../../discrete_functions/DiscreteFunction.h"
#include "Gs.h"

class St {

public:

    static CDouble performMethod(DiscreteFunction &df, CDouble target_x);

};


#endif //VM1_ST_H
