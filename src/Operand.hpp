#ifndef OPERAND_HPP_INCLUDED
#define OPERAND_HPP_INCLUDED

#include "Element.hpp"
#include <string>


/// Operandus tipusu elemek.
/// @param T - adattpus
template <typename T>
class Operand : public ElementBase<T>{
    T value;
public:
    /// Operandus kontruktor
    /// @param number - milyen értéket vegyen fel az operandus: alapértelmezetten az adattipus default konstruktora
    Operand(T number=T()):value(number){};

    /// Operandus masolo
    ElementBase<T>* copy()const{return new Operand<T>(*this);}
    /// Operator-e az elem?
    bool isOperator()const{return false;}
    /// Visszaadja az operandus erteket
    /// @return operandus erteke
    T getval()const{ return value;};

    /// Stringge alakitja az operandus erteket
    /// @retrun string alakban az operandus
    operator std::string()const {return std::to_string(value);};
    /// @retrun - az operandus precedenciaja mindig -1
    int precedence()const {return -1;}
   

};

#endif
