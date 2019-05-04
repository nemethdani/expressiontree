#ifndef OPERAND_HPP_INCLUDED
#define OPERAND_HPP_INCLUDED

#include "Element.hpp"


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
    T getval()const{ return value;};

};

#endif
