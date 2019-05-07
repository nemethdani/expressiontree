//#include "Expression.hpp"


/// Infix stringből készít kifejezést
/// @param infix - Infix formátumban megadott string, lehet benne zárójel és space
template <typename T>
Expression<T>::Expression(std::string infix){

}

template <typename T>
Expression<T>::Expression(T value){
    ElementBase<T>* eb=(new Operand<T>(value));
    postfix.push(Element<T>(eb));
}

template <typename T>
T Expression<T>::eval()const{
    /// Stack megfordit
    Stack<Element<T>> forditott=postfix.megfordit();
    Stack<Element<T>> munka;
    while(forditott.getactual()!=0){
        /// Ha ertek (nem operator)
        if(!(forditott.top()->isOperator())){
            munka.push(forditott.top());
        }
        else{
            T val1 = munka.top()->getval();munka.pop();  
            T val2 = munka.top()->getval();munka.pop();
            T val=forditott.top()->Operation(val1, val2);
            ElementBase<T>* operand=(new Operand<T>(val));
            munka.push(Element<T>(operand));
        }
        forditott.pop();
    }
    T ret=munka.top()->getval();
    munka.pop();
    return ret;
    
   
}

// /// infix formátumba konvertálás
// /// @return - String, infix formában
// template <typename T>
// std::string Expression<T>::getInfix()const{}


/// postfix formátumba konvertálás
/// @return - String, postfix formában
template <typename T>
std::string Expression<T>::getPostfix()const{
    std::string s;
    Stack<Element<T>> forditott=postfix.megfordit();
    for(size_t i=0;i<postfix.getactual();++i){
        std::string sn=postfix.top()->operator std::string();
        s+=sn;
        forditott.pop();
    }
    return s;
}


// /// prefix formátumba konvertálás
// /// @return - String, prefix formában
// template <typename T>
// std::string Expression<T>::getPrefix()const{}


// /// Kétkifejezést összead
// /// @return - kifejezések összege
// template <typename T>
// Expression<T> Expression<T>::operator+(const Expression& e){}
// /// Kétkifejezést összead helyben
// /// @return - kifejezések összege helyben
// template <typename T>
// Expression<T>& Expression<T>::operator+=(const Expression& e){}
// /// Kétkifejezést kivon
// /// @return - kifejezések kulonbsege
// template <typename T>
// Expression<T> Expression<T>::operator-(const Expression& e){}
// /// Kétkifejezést kivon helyben
// /// @return - kifejezések kulonbsege helyben
// template <typename T>
// Expression<T>& Expression<T>::operator-=(const Expression& e){}
// /// Kétkifejezést szoroz
// /// @return - kifejezések szorzata
// template <typename T>
// Expression<T> Expression<T>::operator*(const Expression& e){}
// /// Kétkifejezést szoroz helyben
// /// @return - kifejezések szorzata helyben
// template <typename T>
// Expression<T>& Expression<T>::operator*=(const Expression& e){}
// /// Kétkifejezést eloszt egymassal
// /// @return - kifejezések hanyadosa
// template <typename T>
// Expression<T> Expression<T>::operator/(const Expression& e){}
// /// Kétkifejezést eloszt egymassal helyben
// /// @return - kifejezések hanyadosa helyben
// template <typename T>
// Expression<T>& Expression<T>::operator/=(const Expression& e){}
