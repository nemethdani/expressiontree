#ifndef ELEMENTBASE_HPP_INCLUDED
#define ELEMENTBASE_HPP_INCLUDED

#include <string>

/// Kifejezes elemeinek absztrakt ososztalya sablon.
/// @param T - adattpus
template<typename T>
class ElementBase{
public:

    /// Elemek masolasa tisztan virtualis fuggvenyekkel
    /// @return - a lemasolt elementbase-re mutato pointer
    virtual ElementBase* copy()const=0;
    /// virtualis destruktor
    virtual ~ElementBase(){};
    ///operator-e az elem?
    virtual bool isOperator()const=0;
    virtual  T Operation(T lhs, T rhs) {return T();};
    virtual T getval()const {return T();};
    virtual operator std::string()const=0;
    virtual int precedence()const{return -1;};
    
    virtual char gettype()const{return 0;};

};

#endif