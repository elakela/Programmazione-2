#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include<iostream>
using namespace std;

template<typename T>
class StatickQ{
    private:
    int head = -1;
    int tail = -1;
    int size = 0;
    int maxSize = -1;
    T* val;

    public:
    StatickQ(int max): maxSize(max){
        val = new T [maxSize];
    }

    //isEmpty
    bool isEmpty(){
        return size == 0;
    }

    //dequeue (rimuovi)
    T dequeue(){
        if(isEmpty()){
            cout << "empty queue" << endl;
            return -1;
        }
        T x = val[head];
        head = (++head%maxSize);
        size--;
        return x;
    }

    //enqueue (inserimento)
    void enqueue (T x){
        if (size == maxSize){
            cout << "Queue overflow " << endl;
            return;
        }
        if (head = -1)
        head = 0;
        tail = (++tail%maxSize);
        val[tail] = x;
        size++;
    }

    friend ostream& operator<< (ostream& out, StatickQ &sq){
        if (sq.isEmpty()){
            out << "is Empty" << endl;
            return out;
        }
        out << "Size: " << sq.size << "Head: " << sq.val[sq.head] << "\tTail: " << sq.val[sq.tail] << endl;
        for(int i = sq.head, count = 0; count<sq.size; count++){
            out << sq.val[i] << " - ";
            i = (i+1) % sq.maxSize;
        }
        return out;
    }
};

#endif