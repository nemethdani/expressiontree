#ifndef OPERATOR_HPP_INCLUDED
#define OPERATOR_HPP_INCLUDED

#include "Element.hpp"
#include <string>

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
    bool isOperator(){return true;};

    /// Vegrehajtja a beallitott muveletet a ket parameterre
    /// @param lhs - bal oldali operandus
    /// @param rhs - jobb oldali operandus
    T Operation(T lhs, T rhs){
        switch(type){
            case '+': return lhs+rhs;
            case '-': return lhs-rhs;
            case '*': return lhs*rhs;
            case '/': return lhs/rhs;
        }
    };

    operator std::string()const{return std::string(1,type);};
    operator std::string&(){return std::string(1,type);};

};

#endif