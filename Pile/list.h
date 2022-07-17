#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;
#include "node.h"

template <typename T> 
class List{
    private:
    Node<T>* head;

    public: 
    List(){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    T getHead(){
        return this->head->val;
    }

    void insertHead(T val){
        if(isEmpty()){
            head = new Node<T>(val);
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }

    T removeHead(){
        if (isEmpty()){
            cout << "empty list";
        }

        Node<T>* ptr = head;
        head = head->next;
        T val = ptr->val;
        delete ptr;
        return val;
    }

    friend ostream& operator<< (ostream& out, const List<T>& list){
        out << "List head=" << endl <<"\t"; 
        Node<T> *ptr = list.head;
        while (ptr->getNext()->getNext()!=nullptr){
            out << *ptr << endl <<"\t";
            ptr = ptr->getNext();
        }
    }

};


#endif