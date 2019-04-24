#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include "ElementBase.hpp"

/// Ertek szerint masolhatova tesz egy ElementBase-t
/// @param T - adattipus
template <typename T>
class Element{
    ElementBase<T>* e;
public:

    /// Konstruktor
    explicit Element(ElementBase<T>* e=NULL):e(e){};
    /// Lemasol egy Elementet
    /// @param tocopy - masolando Element
    Element(const Element& tocopy){
        e=tocopy.e->copy();
    }
    ~Element(){delete e;};

    ///Meglevo elembe masol egy masikat
    /// @param tocopy - masolando Element
    Element& operator=(const Element& tocopy){
        if(&tocopy!=this){
            delete e;
            e=tocopy.e->copy();
        }
        return *this;
    }
    /// -> operator
    ElementBase<T>* operator->(){return e;};
    const ElementBase<T>* operator->()const{return e;};

    /// dereferencia 
    ElementBase<T>& operator*(){return *e;};
    const ElementBase<T>& operator*()const{return *e;};

};

#endif