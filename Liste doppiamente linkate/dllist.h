#ifndef DLLIST_H
#define DLLIST_H
#include "dlnode.h"
#include<iostream> 
using namespace std;

template <typename T>
class DLList{
    private:
    DLNode<T>* head;
    DLNode<T>* tail;
    public: 
    DLList(){
        head = nullptr;
        tail = nullptr;
    }

    //controllo se è vuota
    bool isEmpty(){
        return (tail == head) && (tail == nullptr);
    }

    // inserimento in testa
    void insertHead(T val){
        if (isEmpty()){
            head = new DLNode<T>(val);
            tail = head;
            return;
        }

        DLNode<T>* ptr = new DLNode<T>(val);
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }

    void insertTail(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        DLNode<T>* ptr = new DLNode<T>(val);
        ptr->prev= tail;
        tail->next = ptr;
        tail = ptr;
    }

    void insertOrder(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        if (val <= head->val){
            insertHead(val);
            return;
        }

        if(val >= tail->val){
            insertTail(val);
            return;
        }
 

        DLNode<T>* ptr = head;
        while (ptr->next!=nullptr){    
            if (ptr->next->val >= val){
                break;
            }
            ptr = ptr->next;
        }

        DLNode<T>* temp = new DLNode<T>(val);
        temp->next = ptr->next;
        temp->prev = ptr;

        ptr->next->prev = temp;
        ptr->next = temp;
    }

    //rimozione del nodo in testa
    void removeHead(){
        if (isEmpty()){
            cout << "empty list "<< endl;
            return;
        }

        if (head == tail){
            DLNode<T>* temp = head;
            head = nullptr;
            tail = nullptr;
            delete temp;
        }

        DLNode<T>* temp = head;
        temp->next->prev = head;
        head = temp->next;
        delete temp; 
    }

    void removeTail(){
        if(isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        if(head == tail){
            removeHead();
            return;
        }

        DLNode<T>* temp = tail;
        temp->prev->next = nullptr;
        tail = tail->prev;
        delete temp;
    }

    void removeKey(T key){
        if (isEmpty()){
            cout << "empty list" << endl;
            return;
        }

        if (head->val == key){
            removeHead();
            return;
        }

        else if(tail->val == key){
            removeTail();
            return;
        }

        DLNode<T>* ptr = head;
        while (ptr->next != nullptr && ptr->val!= key){
            // if (ptr->getVal() == val){
            //     break;
            // }
            ptr = ptr->next;
        }

        if(ptr->val!=key){
            cout << "value " << key << " not found" << endl;
            return;
        }

        // ptr->next->prev = ptr->prev;
        // ptr->prev->next = ptr->next; AL CONTRARIO:

        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        delete ptr;
    }

    friend ostream& operator<<(ostream& out, DLList<T> &l){
        DLNode<T>* ptr = l.head;
        while(ptr != nullptr){
            out << "\t" << *ptr << endl;
            ptr = ptr->getNext();
        }
        return out;
    }
};
#endif