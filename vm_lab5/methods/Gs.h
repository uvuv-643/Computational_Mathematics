//
// Created by artem on 01.05.2023.
//

#ifndef VM1_GS_H
#define VM1_GS_H

#include "../../data_structures/CTable.h"
#include "../../discrete_functions/DiscreteFunction.h"
#include "../method_result/GsMethodResult.h"

class Gs {

    static string getFunctionDefinition(CVector<CDouble>& x, CVector<CDouble>& y, vector<vector<double>>& fd);

public:

    static GsMethodResult performMethod(DiscreteFunction &df, CDouble target_x);

    static CTable getTableOfFiniteDifferences(DiscreteFunction &df);

};


#endif //VM1_GS_H
