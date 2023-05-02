//
// Created by artem on 01.05.2023.
//

#ifndef VM1_GSMETHODRESULT_H
#define VM1_GSMETHODRESULT_H

#include "../../data_structures/CTable.h"

class GsMethodResult {

    bool success;
    string function_definition;
    CDouble answer;
    CTable finiteDifferences;

public:

    explicit GsMethodResult(bool success);

    GsMethodResult(bool success, string function_definition, CDouble answer, CTable finiteDifferences);

    bool isSuccess() const;

    string getFunctionDefinition() const;

    CDouble getAnswer() const;

    CTable getFiniteDifferences() const;

    // Setters
    void setSuccess(bool success);

    void setFunctionDefinition(const string &function_definition);

    void setAnswer(CDouble answer);

    void setFiniteDifferences(CTable table);


};


#endif //VM1_GSMETHODRESULT_H
