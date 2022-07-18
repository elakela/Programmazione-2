#ifndef DLNODE_H
#define DLNODE_H
#include<iostream>
using namespace std;

template <typename T>
class DLNode {
    private: 
    T val; 
    DLNode<T>* next;
    DLNode<T>* prev;
    template <typename U>
    friend class DLList;
    public:
    DLNode(T val) : val(val), next(nullptr), prev(nullptr){};
    
    T getVal(){
        return this->val;
    }

    DLNode<T>* getNext(){
        return this->next;
    }

    DLNode<T>* getPrev(){
        return this->prev;
    }

    friend ostream& operator<< (ostream& out, DLNode<T> &node){
        out << "node val: " << node.val << " " << &node.val << " - next val: " << node.next << " - prev val: " << node.prev;
        return out;
    }
};

#endif