#ifndef STRINGCONVERSION_HPP_INCLUDED
#define STRINGCONVERSION_HPP_INCLUDED

#include <string>
#include "stack.hpp"
#include <sstream>

bool isOperator(const std::string& c){
    return (c=="+" || c=="-" || c=="*" || c=="/");

}

bool isOperand(const std::string& s){return !isOperator(s);}
void pushoperand(std::string& operand, Stack<std::string>& s){
    if(operand!="") s.push(operand);
    operand="";
}

std::string getInfixstr(std::string exp) 
{ 
    Stack<std::string> s;
    std::string element="";
    std::string temp="";
    std::stringstream ss(exp);

  
    while(ss>>element)
    { 
        // Push operands 
        if (isOperand(element)) 
        { 
           s.push(element);
           
        } 
  
        // We assume that input is 
        // a valid postfix and expect 
        // an operator. 
        else
        { 
            
            std::string op1 = s.top(); 
            s.pop(); 
            std::string op2 = s.top(); 
            s.pop(); 
            s.push("(" + op2 + element + 
                   op1 + ")"); 
        } 
    }
    
  
    // There must be a single element 
    // in stack now which is the required 
    // infix. 
    return s.top(); 
} 

#endif
