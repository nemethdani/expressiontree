#include "ElementBase.hpp"

/// Operandus tipusu elemek.
/// @param T - adattpus
template<typename T>
class Operand{
    T value;
public:
    /// Operandus kontruktor
    /// @param number - milyen értéket vegyen fel az operandus: alapértelmezetten az adattipus default konstruktora
    Operand(T number=T()):value(number){};

    /// Operandus masolo
    ElementBase* copy()const{return new Operand(*this);};
    /// Operator-e az elem?
    static bool isOperator(){return false;};

}