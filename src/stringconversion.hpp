#ifndef STRINGCONVERSION_HPP_INCLUDED
#define STRINGCONVERSION_HPP_INCLUDED

#include <string>
#include "stack.hpp"
#include <sstream>

///Eldonti, hogy a kapott string operator-e
/// @param c - string
/// @return - True, ha operator
bool isOperator(const std::string& c){
    return (c=="+" || c=="-" || c=="*" || c=="/");

}
/// Eldonti, hogy a kapott string operandus-e
/// @param s - string
/// @return - True ha operandus
bool isOperand(const std::string& s){return !isOperator(s);}
/// Beteszi a stringeket tartalmazo stackbe az operandust
/// @param operand - egy karakteru string, az operandus
/// @param s - stringeket tartalmazo stack
void pushoperand(std::string& operand, Stack<std::string>& s){
    if(operand!="") s.push(operand);
    operand="";
}
/// Postfix stringbol infix stringet ad vissza
/// @param exp - Postfix string minden elem space-el elvalasztva
/// @return - infix formatumu string
std::string getInfixstr(std::string exp) 
{ 
    Stack<std::string> s;
    std::string element="";
    //std::string temp="";
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
/// Prefix stringge alakitja a postfix stringet
/// @param post_exp postfix tipusu string
/// @return - prefix formatumu string
std::string postToPre(std::string post_exp) 
{ 
    Stack<std::string> s; 
  

     

    std::string element="";

    std::stringstream ss(post_exp);

  
    while(ss>>element)
    {
        // check if symbol is operator 
        if (isOperator(element)) { 
  
            // pop two operands from stack 
            std::string op1 = s.top(); 
            s.pop(); 
            std::string op2 = s.top(); 
            s.pop(); 
  
            // concat the operands and operator 
            std::string temp = element + op2 + op1; 
  
            // Push string temp back to stack 
            s.push(temp); 
        } 
  
        // if symbol is an operand 
        else { 
  
            // push the operand to the stack 
            s.push(element); 
        } 
    }
  
    
  
    // stack[0] contains the Prefix expression 
    return s.top(); 
} 

#endif
