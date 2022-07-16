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

    T getVal(){
        return this->val;
    }

    Node* getNext(){
        return this->next;
    }

    friend ostream& operator<<(ostream& out, const Node<T> &node){  
        out << " node val " << node.val << " - next " << node.next->getVal();
        return out;
    }
};

#endif