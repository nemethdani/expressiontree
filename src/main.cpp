#include <iostream>
#include <stdexcept>

#include "stack.hpp"

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

int main() {
    try{
        stacktest();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    
}