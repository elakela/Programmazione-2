#ifndef STATICK_STACK_H
#define STATICK_STACK_H
#include<iostream>
using namespace std;

template <typename T>
class Statick{
    private:
    T* val;
    int size = 0;
    int top = -1;
    int maxSize = -1;

    public: 
    Statick(int maxSize) : maxSize(maxSize){
       val = new T[maxSize];
    }

    //controllo se è vuota
    bool isEmpty(){
        return size == 0;
    }

    //ritorno il top
    T getTop(){
        if(isEmpty()){
            cout << "empty statick stack" << endl;
            return -1;
        }
        return val[top];
    }

    //inserisco un valore
    void push(T x){
        if (maxSize == size){
            cout << "Stack Overflow" << endl;
            return;
        }
        val[++top] = x;
        size++;
    }

    //rimuovo un valore
    T pop(){
        if (isEmpty()){
            cout << "empty statick stack" << endl;
            return -1;
        }
        size--;
        return val[top--];
    }

    T getVal(){
        return this->val;
    }

    friend ostream& operator<< (ostream& out, Statick<T> &s){
        if(s.isEmpty()){
                out << "Empty static stack!";
                return out;
            }
        out << "Statick stack: maxSize " << s.maxSize << endl;
        for (int i = s.size-1; i>0; i--)
            {
                out << s.val[i] << " - ";
            }
            out << s.val[0]; 
            out << endl;
        return out;
        
    }
};

#endif