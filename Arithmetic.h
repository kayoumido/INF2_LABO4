//
// Created by deekay on 10/04/19.
//

#ifndef LABO4_ARITHMETIC_H
#define LABO4_ARITHMETIC_H

#include "Exceptions.h"

template<typename T>
T multiply(T a, T b) {
    T result = a * b;

    if (((a >= T() and b >= T()) or (a < T() and b < T())) and result < T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow."
                " a and b were greater or lower than default value but the result was lower"
        );
    }

    if (((a < T() and b >= T()) or (a >= T() and b < T())) and result < T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow."
                "a is greater and b is lower or a is lower and b greater than the default value "
                "but the result is lower"
        );
    }

    return result;
}

template<typename T>
T add(T a, T b) {
    T result = a + b;

    if (a > T() and b > T() and result < T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow."
                " a and b were greater than default value but the result was lower"
        );
    }

    if (a < T() and b < T() and result > T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow."
                " a and b were lower than default value but the result was greater"
        );
    }

    return result;
}

template<typename T>
T subtract(T a, T b) {
    T result = a - b;

    if (a >= T() and b < T() and result < T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow"
                " a is greater and b is lower than the default value but the result is lower"
        );
    }

    if (a < T() and b >= T() and result > T()) {
        throw ArithmeticOverflow(
                "ERROR : Operation caused a memory overflow"
                " a is lower and b is greater than the default value but the result is greater"
        );
    }

    return result;
}


#endif //LABO4_ARITHMETIC_H
