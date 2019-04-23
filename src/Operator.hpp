#ifndef OPERATOR_HPP_INCLUDED
#define OPERATOR_HPP_INCLUDED

#include "ElementBase.hpp"

/// Operator tipusu elemek.
/// @param T - adattpus
template <typename T>
class Operator : public ElementBase<T>{
    char type;
public:
    /// Operator konstruktor
    /// @param c - operatort jelkepezo char tipusu karakter
    Operator(char c):type(c){};

    /// Operator masolo
    /// @return - masolatra mutato Elementbase* tipusu pointer
    ElementBase<T>* copy()const{return new Operator<T>(*this);};
    /// Operator-e?
    /// @return - igen.
    static bool isOperator(){return true;};

    /// Vegrehajtja a beallitott muveletet a ket parameterre
    /// @param lhs - bal oldali operandus
    /// @param rhs - jobb oldali operandus
    T Operation(T lhs, T rhs){};

};

#endif