#ifndef OPERATOR_HPP_INCLUDED
#define OPERATOR_HPP_INCLUDED

#include "Element.hpp"
#include <string>

/// Operator tipusu elemek.
/// @param T - adattpus
template <typename T>
class Operator : public ElementBase<T>{
    std::string type;
public:
    /// Operator konstruktor
    /// @param c - operatort jelkepezo char tipusu karakter
    Operator(char c):type(std::string(1, c)){};
    Operator(std::string c):type(c){};

    /// Operator masolo
    /// @return - masolatra mutato Elementbase* tipusu pointer
    ElementBase<T>* copy()const{return new Operator<T>(*this);};
    /// Operator-e?
    /// @return - igen.
    bool isOperator()const{return true;};

    /// Vegrehajtja a beallitott muveletet a ket parameterre
    /// @param lhs - bal oldali operandus
    /// @param rhs - jobb oldali operandus
    T Operation(T lhs, T rhs){
        switch(type[0]){
            case '+': return lhs+rhs;
            case '-': return lhs-rhs;
            case '*': return lhs*rhs;
            case '/': return lhs/rhs;
        }
        return T();
    };

    operator std::string()const{return type;};
    
    int precedence()const{
        if(type == "*" || type == "/") return 2; 
        
        else if (type == "+" || type == "-") return 1;
        else return -1;
        
    }

    
    char gettype()const{return type[0];}

};

#endif