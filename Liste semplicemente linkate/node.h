#ifndef NODE_H
#define NODE_H
#include<iostream> 
using namespace std;

template <typename T>
class Node{
    private:
    T val;
    Node* next;
    template <typename U>
    friend class List;
    public: 
    Node(T val) : val(val){
        next = nullptr;
    }

    T getVal(Node* ptr){
        return ptr.val;
    }

    Node* getNext(Node* ptr){
        return ptr.next;
    }
};

#endif