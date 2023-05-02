//
// Created by artem on 01.05.2023.
//

#include "GsMethodResult.h"

#include <utility>

// Constructor
GsMethodResult::GsMethodResult(bool success, string function_definition, CDouble answer, CTable finiteDifferences)
        : success(success), function_definition(std::move(function_definition)), answer(answer),
          finiteDifferences(std::move(finiteDifferences)) {}

// Getters
bool GsMethodResult::isSuccess() const {
    return success;
}

string GsMethodResult::getFunctionDefinition() const {
    return function_definition;
}

CDouble GsMethodResult::getAnswer() const {
    return answer;
}

// Setters
void GsMethodResult::setSuccess(bool _success) {
    this->success = _success;
}

void GsMethodResult::setFunctionDefinition(const string &_function_definition) {
    this->function_definition = _function_definition;
}

void GsMethodResult::setAnswer(CDouble _answer) {
    this->answer = _answer;
}

GsMethodResult::GsMethodResult(bool _success) {
    this->success = _success;
}

void GsMethodResult::setFiniteDifferences(CTable _table) {
    this->finiteDifferences = std::move(_table);
}

CTable GsMethodResult::getFiniteDifferences() const {
    return this->finiteDifferences;
}
