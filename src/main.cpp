#include <iostream>
#include <stdexcept>

#include "stack.hpp"
#include "Element.hpp"
#include "Expression.hpp"
#include "Operand.hpp"
#include "Operator.hpp"
#include "stringconversion.hpp"
#include <fstream>
#include <vector>
#include "memtrace.h"




void stacktest(){
    std::cout<<"Stack kezelés"<<std::endl;
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
    std::cout<<std::endl;
}

void expressiontest(){
    
    Expression<int> e1(1), e2(2);
    std::cout<<"e1 infix: "<<e1.getInfix() << std::endl;
    std::cout<<"e1 postfix: "<<e1.getPostfix()<<std::endl;
    std::cout<<"e2 postfix: "<<e2.getPostfix()<<std::endl;
    std::string infix="1 + 2 * ( 3 * 4 - 5 ) * ( 6 + 7 * 8 ) - 9";
    std::cout<<"infix: "<<infix<<std::endl;
    
    Expression<int> ep(infix);
    std::cout<<"infix: "<<ep.getInfix()<<std::endl;
    std::cout<<"postfix elvart: 1234*5-*678*+*+9-"<<std::endl;
    std::cout<<ep.getPostfix()<<std::endl;
    Expression<double> ep2("1.54 + 2.1 * ( 3.4 * 4 - 5 ) * ( 6.8 + 7.9 * 8.4 ) - 9");
    std::cout<<"double expr infix: "<<"1.54 + 2.1 * ( 3.4 * 4 - 5 ) * ( 6.8 + 7.9 * 8.4 ) - 9"<<std::endl;
    std::cout<<ep2.getInfix()<<std::endl;
    std::cout<<ep2.getPostfix()<<std::endl;
    std::cout<<"prefix: "<<ep2.getPrefix()<<std::endl;
}

void eval(){
    Expression<int> e1(1), e2(2);
    std::cout<<"e1: "<<e1.eval()<<std::endl;
    std::cout<<"e2: "<<e2.eval()<<std::endl;
    Expression<int> ep("1 + 2 * ( 3 * 4 - 5 ) * ( 6 + 7 * 8 ) - 9");
    std::cout<<"eval: "<<ep.eval()<<std::endl;
    std::cout<<"elvart: "<<1+2*(3*4-5)*(6+7*8)-9<<std::endl;
    Expression<double> ep2("1.54 + 2.1 * ( 3.4 * 4 - 5 ) * ( 6.8 + 7.9 * 8.4 ) - 9");
    std::cout<<"eval: "<<ep2.eval()<<std::endl;
    std::cout<<"elvart: "<<1.54+2.1*(3.4*4-5)*(6.8+7.9*8.4)-9<<std::endl;
}

void stringconvert(){
    std::string pfx = "1 2 * 3 +"; 
    std::cout<<"pfx: "<<pfx<<std::endl;
    std::cout<<"infix:         "<<getInfixstr(pfx)<<std::endl;
    std::string postfix="1 2 3 4 * 5 - * 6 7 8 * + * + 9 -";
    std::cout<<"postfix: 1 2 3 4 * 5 - * 6 7 8 * + * + 9 -"<<std::endl;
    std::cout<<"infix elvart: 1+2*(3*4-5)*(6+7*8)-9"<<std::endl;
    std::cout<<"infix:         "<<getInfixstr(postfix)<<std::endl;

    std::string post_exp = "1 2 3 / - 1 4 / 5 - *";
    std::cout<<"postfix: "<<post_exp<<std::endl;
    std::cout<<postToPre(post_exp)<<std::endl;
    std::cout<<"elvart: *-1/23-/145"<<std::endl; 
}

void negativ(){
    Expression<int> e1("5 * ( -1 ) ");
    std::cout<<e1.eval()<<std::endl;
    std::cout<<"elvart: " << 5 * ( -1 )<<std::endl;
}

void muveletek(){
    Expression<int>e1("1 * 4 - 6"); //-2
    
    Expression<int>e2("40 / 5 - 7"); //1
    e1+=e2; //-1
    std::cout<<e1.eval()<<std::endl;
    Expression<int>e3=e1+e2; //0
    std::cout<<e3.eval()<<std::endl;
    std::cout<<e1.eval()<<std::endl;

}


void grandeval(){
    std::ifstream values;
    values.open ("values.txt");
    std::ifstream expcode;
    expcode.open ("expcode.txt");
    int val;
    int idx;
    std::string infix;
    bool ok=true;

    while(values>>val && expcode>>idx){
        std::getline(expcode,infix);
        Expression<int> e(infix);
        int evl=e.eval();
        if(evl!=val){
            std::cout<<"hiba: "<<idx<<" elvart: "<<val<<" kapott: "<<evl<<std::endl;
            ok=false;

        }
    }
     if(ok) {
        std::cout<< "Minden OK, minden az oroszOKé"<<std::endl;

    }
    else std::cout<<"Baj volt"<<std::endl;
}

void grandinfix(){
    std::ifstream expcode;
    expcode.open ("expcode.txt");
    int idx;
    std::string infix;
    //std::vector<Expression<int>> ev;
    bool ok=true;

    while(expcode>>idx){
        std::getline(expcode,infix);
        Expression<int> e(infix);
        std::string if2=e.getInfix();
        Expression<int> e2(if2);
        std::string if3=e2.getInfix();
        
        if(if2!=if3){
            std::cout<<"Hiba "<<idx<<": "<<"Elvart: "<<if2<<" kapott: "<< if3<<std::endl;
            ok=false;
        }

    }
    if(ok) {
        std::cout<< "Minden OK, minden az oroszOKé"<<std::endl;

    }
    else std::cout<<"Baj volt"<<std::endl;
}
    





int main() {
    
    

    int nr;
    while (std::cin >> nr && nr > 0) {
        try{
            switch(nr){
                case 1:
                    stacktest();
                    break;
                case 2:
                    expressiontest();
                    break;
                case 3:
                    stringconvert();
                    break;
                case 4:
                    eval();
                    break;
                case 5:
                    grandeval();
                    break;
                case 6:
                    negativ();
                    break;
                case 7:
                    muveletek();
                    break;
                case 8:
                    grandinfix();
                    break;
                default:
                    std::cout<<"tesztek: 1-8, kilepes:0"<<std::endl;

            }
                
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    }


    

    
}