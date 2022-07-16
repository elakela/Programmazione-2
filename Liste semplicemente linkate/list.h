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
        return (head == nullptr);
    }
    
    //inserimento in testa
    void insertHead(T val){
        if (isEmpty()){
            head = new Node<T>(val);
        }
        Node<T>* ptr = new Node<T>(val);
        ptr->next = head;
        head = ptr;
    }

    //inserimento in coda
    void insertTail(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while (!ptr->getNext()){
            ptr = ptr->getNext;
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
    }

    //inserimento in ordine
    void Insert(T val){
        if (isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while (!(ptr->getNext()) && val>ptr->val){
            if (ptr->next->val > val)
                break;
            ptr = ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = ptr->getNext();
        ptr->next = temp;
    }

    //cancellazione in testa
    void removeHead(T val){
        if (isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* ptr = head;
        head = head->getNext();
        delete ptr;
    }

    //cancellazione in coda
    void removeTail(T val){
        if(isEmpty){
            cout << "empty list" << endl;
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* cur = head;
        while(!(cur->getNext())){
            prev = cur;
            cur = cur->getNext();
        }
        prev->next = nullptr;
    }

    void removeNode(T val){
          if(isEmpty){
            cout << "empty list" << endl;
            return;
        }
        
        if (head->val == val){
            removeHead(val);
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* cur = head;
        while(!(cur->getNext())){
            prev = cur;
            cur = cur->getNext();
        }
        prev->next = cur->next;
    }

};


#endif