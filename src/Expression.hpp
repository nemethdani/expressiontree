#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED

#include "stack.hpp"
#include "Operand.hpp"
#include "Element.hpp"
#include "Operator.hpp"

/// Kifejezések osztálya
/// @param T - adattípus
template <typename T>
class Expression{
    Stack<Element<T>> postfix;
    /// precedenciat ad vissza operatorokhoz
    /// @param c - operator karaktere
    /// @return - */: 2, +-:1, egyebkent -1
    int precedence(char c){
        if(c == '*' || c == '/') 
        return 2; 
        else if(c == '+' || c == '-') 
        return 1; 
        else
        return -1; 
    }

    /// a kapott karakter operator-e
    /// @return true, ha operator, egyebken false
    bool isoperatorchar(char c){return (precedence(c)==1 || precedence(c)==2);};

    /// Szamjegyekbol allo stringbol keszit szamot
    /// @param szamjegyeket es esetleg pontot(tizedesjegy) tartalmazo string
    /// @return T tipusu szam
    T stringtonum(const std::string& s)const;
    Element<T> valuetoelement(T value)const;
    void pushszam(std::string& szam);

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