#ifndef ELEMENTBASE_HPP_INCLUDED
#define ELEMENTBASE_HPP_INCLUDED

/// Kifejezes elemeinek absztrakt ososztalya sablon.
/// @param T - adattpus
template<typename T>
class ElementBase{
public:

    /// Elemek masolasa tisztan virtualis fuggvenyekkel
    /// @return - a lemasolt elementbase-re mutato pointer
    virtual ElementBase* copy()const=0;
    /// virtualis destruktor
    virtual ~ElementBase();
    ///operator-e az elem?
    virtual bool isOperator()const=0;

};

#endif