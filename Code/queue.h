#ifndef QUEUE_H
#define QUEUE_H
#include "dllist.h"

template <typename T>
class Queue : protected DLList<T>{
    private:
    int size = 0; //la dimensione deve essere l'unica variabile passata
    public:
    Queue():DLList<T>(){};
    
    //controllo se è vuoto
    bool isEmpty(){
        return size == 0;
    }

    //aggiungo un nodo
    void enqueue(T val){
        DLList<T>::insertTail(val);
        size++;
    }

    DLNode<T> dequeue(){
        if(isEmpty()){
            return 0;
        }
        DLNode<T> ptr = *(DLList<T>::head);
        DLList<T> :: removeHead();
        size--;
        // cout << ptr;
        return ptr; 
    }

  friend ostream& operator<< (ostream& os, Queue<T>& coda){
        //os << "Head: " <<  coda.head << "\t Tail: " << coda.tail << endl;

        DLNode<T>* ptr = coda.head;

        while (ptr!=nullptr){
            cout << *ptr << endl;
            ptr=ptr->getNext();
        }
        return os;
    }

};

#endif

