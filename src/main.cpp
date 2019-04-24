#include <iostream>
#include <stdexcept>

#include "stack.hpp"
#include "Element.hpp"
#include "Expression.hpp"
#include "Operand.hpp"
#include "Operator.hpp"


void stacktest(){
    //ures stack,10es stack
    Stack<int> s0, snull, s10(10);
    s0.push(0);
    s0.push(1);
    s0.push(2);
    Stack<int> s1=s0;
    s10=s0;
    s10.pop();
    s10.pop();
    snull.top();
    snull.pop();
}

void expressiontest(){
    
    Expression<int> e1(1), e2(2);
    Expression<int> e0=e1+e2;
    std::cout<<e0.eval();
    std::cout<<e0.getInfix();
    std::cout<<e0.getPostfix();
    std::cout<<e0.getPrefix();
    Expression<int> estring("5+3*6");
    estring*=2;
    



}

int main() {
    try{
        stacktest();
        expressiontest();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    
}