//
// Created by artem on 23.02.2023.
//

#ifndef VM1_METHODRESULT_H
#define VM1_METHODRESULT_H

enum MethodResult {
    WRONG_NUMBER_OF_SOLUTIONS = -1,
    METHOD_WAS_SUCCESSFULLY_FINISHED = 0,
    METHOD_CAN_BE_APPLIED = 1,
    DERIVATIVE_MUST_BE_SAME_SIGN = 2,
    SECOND_DERIVATIVE_MUST_BE_SAME_SIGN = 3,
    LIPSCHITZ_CONSTANT_GREATER_THAN_ONE = 4
};

#endif //VM1_METHODRESULT_H
