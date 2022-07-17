#ifndef PILA_H
#define PILA_H
#include"list.h"

template <typename T>
class Pila : protected List<T>{
    private: 
    int size = 0;

    public:
    Pila() : List<T>(){};

    bool isEmpty(){
        return size == 0;
    }

    T getTop(){
        if(isEmpty()){
            cout << "empty stack" << endl;
            return -1;
        }
        return List<T>::getHead();
    }

    void push(T val){
        List<T>::insertHead(val);
        size++;
    }

    T pop(){
        if (isEmpty()){
            cout << "empty stack" << endl;
            return -1;
        }
        T val = List<T>::removeHead();
        return val;
    }

    friend ostream& operator<<(ostream& out, Pila<T> &p){
        out << (List<T>)p;
        return out;
        }

};

#endif