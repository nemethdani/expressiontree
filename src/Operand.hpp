#include "ElementBase.hpp"

template<typename T>
class Operand{
    T value;
public:
    Operand(T number):value(number){};

    ElementBase* copy()const{};
    static bool isOperator(){return false;};

}