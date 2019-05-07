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
    s10=s0;
    std::cout<<"aktualis meret: " <<s0.getactual()<< " elvart:3"<<std::endl;
    Stack<int> s1=s0;
    Stack<int> s1_forditva=s1.megfordit();
    std::cout<<"s1:"<<std::endl;
    while(s1.getactual()!=0){std::cout<<s1.top()<<"\n";s1.pop();}
    std::cout<<"s1 forditva:"<<std::endl;
    while(s1_forditva.getactual()!=0){std::cout<<s1_forditva.top()<<"\n";s1_forditva.pop();}
    
    s10.pop();
    s10.pop();
    // snull.top();
    // snull.pop();
}

void expressiontest(){
    
    Expression<int> e1(1), e2(2);
    //Expression<int> e0=e1+e2;
    std::cout<<"e1: "<<e1.eval()<<std::endl;
    std::cout<<"e2: "<<e2.eval()<<std::endl;
    // std::cout<<e0.getInfix();
    std::cout<<e1.getPostfix()<<std::endl;
    std::cout<<e2.getPostfix()<<std::endl;
    // std::cout<<e0.getPrefix();
    // Expression<int> estring("5+3*6");
    // estring*=2;
    



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