#ifndef LIST_H
#define LIST_H
#include "node.h"
#include<iostream>
using namespace std;

template <typename T>
class List{
    private:
    Node<T>* head;
    public: 
    List(){
        head = nullptr;
    }

    //controllo lista vuota
    bool isEmpty(){
        return head == nullptr;
    }
    
    //inserimento in testa
    void insertHead(T val){
        if (this->isEmpty()){
            head = new Node<T>(val);
        }
        Node<T>* ptr = new Node<T>(val);
        ptr->next = head;
        head = ptr;
    }

    //inserimento in coda
    void insertTail(T val){
        if(this->isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while (ptr->getNext() != nullptr){  //va scritto diverso da nullptr, se no non entra nel while.
            ptr = ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
    }

    //inserimento in ordine
    void Insert(T val){
        if (this->isEmpty()){
            insertHead(val);
            return;
        }

        if (val <= head->val){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while ((ptr->getNext() != nullptr) && val>ptr->val){
            if (ptr->next->val > val)
                break;
            ptr = ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = ptr->getNext();
        ptr->next = temp;
    }

    //cancellazione in testa
    void removeHead(){
        if (this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        head = head->getNext();
        delete ptr;
    }

    //cancellazione in coda
    void removeTail(){
        if(this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* cur = head;
        while((cur->getNext()) != nullptr){
            prev = cur;
            cur = cur->getNext();
        }
        prev->next = nullptr;
    }

    void removeNode(T val){
          if(this->isEmpty()){
            cout << "empty list" << endl;
            return;
        }
        
        if (head->val == val){
            removeHead();
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* cur = head;
        while(cur->getNext()!= nullptr && (val!=cur->val)){
            prev = cur;
            cur = cur->getNext();
        }

        prev->next = cur->next;
    }
    friend ostream& operator<< (ostream& out, const List<T>& list){
        out << "List head=" << endl <<"\t"; 
        Node<T> *ptr = list.head;
        while (ptr->getNext()!=nullptr){
            out << *ptr << endl <<"\t";
            ptr = ptr->getNext();
        }
        out <<"node val " << ptr->getVal() << " - next nullptr";
        return out;
    }
};


#endif