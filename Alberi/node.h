#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream> 

using namespace std;

template <typename T>
class Node{
    private:
    
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    
    template <typename U>
    friend class bst;

    public: 
    Node(T key) : val(key){
        left = nullptr;
        right = nullptr;
        parent = nullptr;   // va inizializzato anche il genitore
    }

   void setParent(Node<T>* parent){
        this->parent = parent;
    }

    void setLeft(Node<T>* left){
        this->left = left;
    }

    void setRight(Node<T>* right){
        this->right = right;
    }

    Node<T>* getParent(){
        return this->parent;
    }

    Node<T>* getLeft(){
        return this->left;
    }

    Node<T>* getRight(){
        return this->right;
    }

    void setKey(T key){
        this->val = key;
    }

    T getVal(){
        return this->val;
    }
    
    friend ostream& operator<<(ostream& out, Node<T> &node){
        out << endl << "node val: " << node.val << " " << &node << " - left: " << node.left << " - right: " << node.right << " - parent: " << node.parent;
        return out;
    }    
};

#endif