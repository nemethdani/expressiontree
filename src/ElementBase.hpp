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
    /// Végrehajtja az adott operaciot, Operator felulirja
    /// @param lhs,rhs - ezekent az ertekeken hajtja vegre az operaciot
    /// @return - T tipusu ertek, az eredmeny
    virtual  T Operation(T lhs, T rhs) {return T();};
    /// Visszaadja az elem erteket, Operandus felulirja
    /// @return - T tipusu erteke az operandusnak
    virtual T getval()const {return T();};
    /// stringbe konvertalja az absztrakt elemeket
    virtual operator std::string()const=0;
    /// visszaadja az Operator precedenciajat, Operator felulirja
    /// @return - alapertelmezetten -1, tobbit lasd: Operator
    virtual int precedence()const{return -1;};
    /// visszaadja az operator tipusat karakterkent, Operator felulirja
    /// @return operator karakter
    virtual char gettype()const{return 0;};

};

#endif