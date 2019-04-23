#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <stdexcept>

/// Stack sablon.
/// @param T - adattpus
template <typename T>
class Stack{
    size_t size;
    size_t actual;
    T* data;


    /// Ures-e?
    /// @return - true, ha üres, egyébként false
    bool isEmpty(){return actual==0;}

    /// Atmeretezes
    /// @param newsize - a kívánt új méret
    /// @return - ha az aktuális tartalomnál kisebbre akarjuk méretezni, length error-t dob
    void resize(size_t newsize){
        if (newsize<actual) throw std::length_error("Resizing to smaller size than content size is not allowed");
        T* newdata=new T[newsize];
        for(size_t i=0;i<actual;++i)
            newdata[i]=data[i];
        delete[] data;
        data=newdata;
        size=newsize;
    }

    public:

    /// Konstruktor
    /// @param s - a kívánt méret (alapértelmezetten 0)
    Stack(size_t s=0):
        size(s),
        actual(0),
        data(new T[size]){}
    ~Stack(){delete[] data;}
    
    /// Copy Konstruktor
    /// @param s - a másolni kívánt stack, referenciaként
    Stack(const Stack& s):size(s.size),
        actual(s.actual),
        data(new T[size]){
        for(size_t i=0;i<actual;++i)
            data[i]=s.data[i];
    }

    /// =Egyenlőség operátor.
    /// @param s - a másolni kívánt stack, referenciaként
    Stack& operator=(const Stack& s){
        if(this!=&s){
            delete[] data;
            size=s.size;
            actual=s.actual;
            data= new T[size];
            for(size_t i=0;i<actual;++i)
            data[i]=s.data[i];
            
        }
        return *this;
    }
    
    /// Top.
    /// @return - a stack legfelső (legutoljár hozzáadott) elemével tér vissza
    /// @return - ha üres a stack, out of range hibát dob
    const T& top()const{
        if(isEmpty()) throw std::out_of_range("Stack is empty");
        return data[actual-1];
    }
    /// Top.
    /// @return - a stack legfelső (legutoljár hozzáadott) elemével tér vissza
    /// @return - ha üres a stack, out of range hibát dob
    T& top(){
        if(isEmpty()) throw std::out_of_range("Stack is empty");
        return data[actual-1];
    }
    /// Pop.
    /// @return - a stack legfelső (legutoljár hozzáadott) elemét törli
    /// @return - ha üres a stack, out of range hibát dob
    void pop(){
        if(isEmpty()) throw std::out_of_range("Stack is empty");
        actual--;
        if(actual<size/4) resize(size/2);
    }
    /// Push.
    /// a stack tetejére betesz egy értéket.
    void push(const T& val){
        if(actual==size) resize(size*2);
        data[actual]=val;
        actual++;
    }
        

};

#endif