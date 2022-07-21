#ifndef LIST_H
#define LIST_H
#include "node.h"

template <typename T> 
class list{
    private:
    Node<T>* head;

    public:
    list(){
        head = nullptr;
    }

    //controllo se è vuota
    bool isEmpty(){
        return head == nullptr;
    }

    Node<T>* getHead(){
        return this->head;
    }

    #pragma region "Inserimenti"
    
    //inserimento in testa
    void insertHead(T val){
        if(isEmpty()){
            head = new Node<T>(val);
            return;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }

    //inserimento in coda
    void insertTail(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext()){
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        ptr->next = temp;
    }
    
    //inserimento in ordine
    void insertOrder(T val){
        if(isEmpty()){
            insertHead(val);
            return;
        }

        if (val<=head->val){
            insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr){
            if(ptr->next->val >= val){
                break;
            }
            ptr = ptr->next;
        }

        Node<T>* temp = new Node<T>(val);
        temp->next = ptr->next;
        ptr->next = temp;
    }

    #pragma endregion

    #pragma region "Rimozioni"
    
    //rimozione della testa
    void removeHead(){
        if(isEmpty()){
            cout << "empty" << endl;
            return;
        }

        Node<T> ptr = head;
        head = head->next;
        delete ptr;
    }

    //rimozione della coda
    void removeTail(){
        if(isEmpty()){
            cout << "empty" << endl;
        }

        Node<T>* cur = head;
        Node<T>* prec = nullptr;

        while(cur->next){
            prec = cur;
            cur = cur->next;
        }

        prec->next = nullptr;
        delete cur;
    }

    //rimozione di un elemento specifico
    void removeKey(T val){
        if(isEmpty()){
            cout << "empty" << endl;
        }

        Node<T>* cur = head;
        Node<T>* prec = nullptr;

        while(cur->next){
            if (cur->val == val){
                break;
            }
            prec = cur;
            cur = cur->next;
        }

        if (!(cur->next) && cur->val != val){
            cout << "value " << val << " not found" << endl;
            return;
        }

        prec->next = cur->next;
        delete cur;
    }

    #pragma endregion

    //overload di stampa
    friend ostream& operator<< (ostream& out, list<T> &list){
        out << "Head= " << list.head;
        Node<T>* ptr = list.head;
        while (ptr){
            out << "\t" << *ptr << endl;
            ptr = ptr->getNext();
        }
        return out;
    }

};
#endif