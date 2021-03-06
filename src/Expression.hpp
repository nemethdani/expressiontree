#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include "stack.hpp"
#include "Operand.hpp"
#include "Element.hpp"
#include "Operator.hpp"
#include "stringconversion.hpp"

/// Kifejezések osztálya
/// @param T - adattípus
template <typename T>
class Expression{
    Stack<Element<T>> postfix;
    /// precedenciat ad vissza operatorokhoz
    /// @param c - operator karaktere
    /// @return - */: 2, +-:1, egyebkent -1
    int precedence(std::string c){
        if(c == "*" || c == "/") 
        return 2; 
        else if(c == "+" || c == "-") 
        return 1; 
        else
        return -1; 
    }

    /// a kapott karakter operator-e
    /// @return true, ha operator, egyebken false
    bool isoperatorchar(std::string c){return isOperator(c);};

    /// Szamjegyekbol allo stringbol keszit szamot
    /// @param szamjegyeket es esetleg pontot(tizedesjegy) tartalmazo string
    /// @return T tipusu szam
    T stringtonum(const std::string& s)const;
    /// Adott értékből absztrak elemet (operandus) hoz létre
    /// @param value - az érték, amit át szeretnénk konvertálni
    /// @return - absztrakt elem
    Element<T> valuetoelement(T value)const;
    /// beteszi a stringként megkapott számot a postfix absztrak kollekcióba
    /// @param szam - stringkent megadott, lehet negatis es tizedes ponttal elvalasztott is pl: -4.56
    void pushszam(std::string& szam);
    /// A jelenlegi kefejezeshez hozzafuz egy masikat, megadott operandussal, += -= ... muveletekhez
    /// @param rhs - ezt a kifejezést egyesitjuk a meglevovel
    /// @param op - a kivant operandus (+ - * /)
    void hozzafuz(const Expression<T>& rhs, const char op);

public:

    /// Infix stringből készít kifejezést
    /// @param infix - Infix formátumban megadott string, lehet benne zárójel és space
    Expression(std::string infix);

    /// Értékből készít kifejezést
    /// @param value - ezt az értéket rendli a kifejezéshez
    Expression(T value=T());

    /// Kiértékeli a kifejezést
    /// @return - A kifejezés értéke
    T eval()const;

    /// infix formátumba konvertálás
    /// @return - String, infix formában
    std::string getInfix()const;
    /// postfix formátumba konvertálás
    /// @return - String, postfix formában
    std::string getPostfix()const;
    /// prefix formátumba konvertálás
    /// @return - String, prefix formában
    std::string getPrefix()const;


    /// Kétkifejezést összead
    /// @return - kifejezések összege
    Expression operator+(const Expression& e);
    /// Kétkifejezést összead helyben
    /// @return - kifejezések összege helyben
    Expression& operator+=(const Expression& e);
    /// Kétkifejezést kivon
    /// @return - kifejezések kulonbsege
    Expression operator-(const Expression& e);
    /// Kétkifejezést kivon helyben
    /// @return - kifejezések kulonbsege helyben
    Expression& operator-=(const Expression& e);
    /// Kétkifejezést szoroz
    /// @return - kifejezések szorzata
    Expression operator*(const Expression& e);
    /// Kétkifejezést szoroz helyben
    /// @return - kifejezések szorzata helyben
    Expression& operator*=(const Expression& e);
    /// Kétkifejezést eloszt egymassal
    /// @return - kifejezések hanyadosa
    Expression operator/(const Expression& e);
    /// Kétkifejezést eloszt egymassal helyben
    /// @return - kifejezések hanyadosa helyben
    Expression& operator/=(const Expression& e);
};

#include "Expression.tpp"

#endif