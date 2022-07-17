#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <typename T>
class Node{
    private:
    template<typename U>
    friend class List;
    T val;
    Node<T>* next;

    public: 
    Node(T val) : val(val){
        next = nullptr;
    }

    Node<T>* getNext(){
        return this->next;
    }

    T getVal(){
        return this->val;
    }

    friend ostream& operator<<(ostream& out, Node<T> &n){
        out << "node value: " << n.val << " - next: " << n.next->getVal();
        return out;
    }

};

#endif