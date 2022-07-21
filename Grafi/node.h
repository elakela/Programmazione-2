#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <typename T> 
class Node{
    private:
    T val;
    Node<T>* next;
    template <typename U> 
    friend class list;

    public: 
    Node(T val) : val(val){
        next = nullptr;
    }

    T getVal(){
        return this->val;
    }

    Node<T>* getNext(){
        return this->next;
    }

    friend ostream& operator<< (ostream& out, Node<T> &node){
        out << endl << "node val = " << node.val << endl << &node << " - next:" << node.next;
        return out; 
    }
};
#endif