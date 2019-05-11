//#include "Expression.hpp"

#include <sstream>
#include "stringconversion.hpp"



template <typename T>
T Expression<T>::stringtonum(const std::string& s)const{
    
    std::stringstream ss(s);
    T x = 0; 
    ss >> x;
    return x;
}


template <typename T>
Expression<T>::Expression(std::string infix){
    std::string szam="";
    //T val;
    Stack<Element<T>> temp;
    //temp.push('N')
    size_t len=infix.size();
    for(size_t i=0;i<len;++i){

        //operator
        if(isoperatorchar(infix[i])){
            ElementBase<T>* eb=(new Operator<T>(infix[i]));
            Element<T> e(eb);
            pushszam(szam);
            while(!temp.isEmpty() && e->precedence() <= temp.top()->precedence()) 
            { 
                Element<T> e = temp.top(); 
                temp.pop(); 
                postfix.push(e); 
            } 
            
            
            temp.push(e);
            
        }

        // (
            
        else if(infix[i] == '('){
            pushszam(szam);
            ElementBase<T>* eb=(new Operator<T>('('));
            temp.push(Element<T>(eb));
            
        } 

        // )
        else if(infix[i] == ')') 
        { 
            pushszam(szam);
            ElementBase<T>* closeb=(new Operator<T>('('));
            Element<T> close=(Element<T>(closeb));
            ElementBase<T>* openb=(new Operator<T>(')'));
            Element<T> open=(Element<T>(openb));
            while(!temp.isEmpty() && temp.top()->gettype() != '(') 
            { 
                Element<T> e= temp.top(); 
                if (!(temp.isEmpty()) ) temp.pop(); 
                postfix.push(e); 
            } 
            if( !(temp.isEmpty()) && (temp.top()->gettype() == '(')) 
            { 
                //char c = st.top(); 
                temp.pop(); 
            } 
        }
        else if(infix[i]==' ')  pushszam(szam);
        //ha szamok
        else{
            szam+=infix[i];

        }
          
        
    }
    pushszam(szam);

    while(!temp.isEmpty()){
        postfix.push(temp.top());
        temp.pop();
    }
}
template <typename T>
void Expression<T>::pushszam(std::string& szam){
    if(szam!=""){
        postfix.push(valuetoelement(stringtonum(szam)));szam="";
    }
    
}

template <typename T>
Element<T> Expression<T>::valuetoelement(T value)const{
    ElementBase<T>* eb=(new Operand<T>(value));
    return Element<T>(eb);
}

template <typename T>
Expression<T>::Expression(T value){
    
    postfix.push(valuetoelement(value));
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
            T val=forditott.top()->Operation(val2, val1);
            ElementBase<T>* operand=(new Operand<T>(val));
            munka.push(Element<T>(operand));
        }
        forditott.pop();
    }
    T ret=munka.top()->getval();
    munka.pop();
    return ret;
    
   
}


template <typename T>
std::string Expression<T>::getInfix()const{
    std::string pfx=getPostfix();
    return getInfixstr(pfx);
}



template <typename T>
std::string Expression<T>::getPostfix()const{
    std::string s;
    Stack<Element<T>> forditott=postfix.megfordit();
    for(size_t i=0;i<postfix.getactual();++i){
        std::string sn=forditott.top()->operator std::string();
        s+=sn;
        if(i!=postfix.getactual()-1) s+=" ";
        forditott.pop();
    }
    return s;
}

template<typename T>
void Expression<T>::hozzafuz(const Expression<T>& rhs, const char op){
    Stack<Element<T>> forditott=rhs.postfix.megfordit();
    while(!(forditott.isEmpty())){
        postfix.push(forditott.top());
        forditott.pop();
    }
    ElementBase<T>* eb=(new Operator<T>(op));
    Element<T> e(eb);
    postfix.push(e);
}


template <typename T>
std::string Expression<T>::getPrefix()const{
    std::string pfx=getPostfix();
    return getPrefix(pfx);
}


// /// Kétkifejezést összead
// /// @return - kifejezések összege
// template <typename T>
// Expression<T> Expression<T>::operator+(const Expression& e){}

// /// Kétkifejezést összead helyben
// /// @return - kifejezések összege helyben
template <typename T>
Expression<T>& Expression<T>::operator+=(const Expression& e){
    hozzafuz(e,'+');
    return (*this);
}

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
