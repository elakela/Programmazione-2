#ifndef BST_H
#define BST_H
#include "node.h"

template <typename T>
class bst{
    private: 
        Node<T>* root;
    public:
        bst(){
        root = nullptr;
    }

   // controllo se è vuota
    bool isEmpty(){
        return root == nullptr;
    }

    #pragma region// inserisco un nodo
    void insert (T key){
        if (this->isEmpty()){
            root = new Node<T>(key);
            return;
        }
        insert (root, key);
    }

    void insert (Node<T>* ptr, T key){

        if(ptr == nullptr){
            ptr = new Node<T>(key);
        }

        if(ptr->left == nullptr && key<=ptr->val){
            ptr->left = new Node<T>(key);
            ptr->left->setParent(ptr); //ricordati di settare il parent
            return;
        }

        else if(ptr->right == nullptr && key > ptr->val){
            ptr->right = new Node<T>(key);
            ptr->right->setParent(ptr); //ricordati di settare il parent
            return;
        }

        else if (key <= ptr->val){
            ptr = ptr->left;
            insert(ptr, key);
        }

        else{
            ptr = ptr->right;
            insert(ptr, key);
        }
    }
    #pragma endregion
    //stampo un nodo
    #pragma region //visita
    void visit(Node<T>* ptr){
        cout << *ptr;
    }

    // visita inorder, preorder, postorder
    void inorder(Node<T>* ptr){
        if (ptr == nullptr){
            return;
        }

        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }

    void inorder(){
        inorder(root);
    }

    void preorder(Node<T>* ptr){
        if (ptr == nullptr){
            return;
        }

        visit(ptr);
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void preorder(){
        preorder(root);
    }
    
    void postorder(Node<T>* ptr){
        if (ptr == nullptr){
            return;
        }

        postorder(ptr->left);
        postorder(ptr->right);
        visit(ptr);
    }
    
    void postorder(){
        postorder(root);
    }
    #pragma endregion
    
    #pragma region// ricerche varie
    Node<T>* min(){
            return min(root);
        }

    Node<T>* min(Node<T>* start){
        if(isEmpty()){
            return nullptr;
        }
        //Node<T>* ptr = start; //il puntatore va inizializzato qua non va passato come parametro, non va inizializzato a root.
        while (start->left){
            start = start->left;    //NON è ricorsiva, MA è ITERATIVA.
        }

        return start;
    }
   
   // ricerca del maggiore
   Node<T>* max(){
            return max(root);
        }
   
   Node<T>* max (Node<T>* start){
    if(isEmpty()){
            return nullptr;
        }
           //il puntatore va inizializzato qua non va passato come parametro
        while (start->right){
            start = start->right;
        }

        return start;
   }

    // ricerca del successore
    Node<T>* succ(Node<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }

        if (x->right){
            return min(x->right);
        }

        Node<T>* y = x->parent;       // va inizializzato al puntatore del genitore
        while(y!= nullptr && x == y->right){ //controllare anche che non "sia finito"
            x = y;
            y = x->parent;
        }

        return y; 
    }

    // ricerca del predecessore
    Node<T>* prec(Node<T>* ptr){
        if(isEmpty()){
            return nullptr;
        }

        if (ptr->left){
            return max(ptr->left);
        }

        Node<T>* x = ptr->parent;
        while(x!= nullptr && ptr == x->left){ //controllare anche che non "sia finito"
            ptr = x;
            x = ptr->parent;
        }

        return x; 
    }

    // ricerca
    Node<T>* search(T key){
        return search(key, root);  //eseternamente dico "ok cercami questo, internamente dico ok ti do il puntatore"
    }

    Node<T>* search(T key, Node<T>* ptr){
        if (ptr == nullptr){
            return nullptr;
        }

        if (ptr->val == key){
            return ptr;
        }

        if(key<ptr->val){
            return search(key, ptr->left);
        }

        if(key>ptr->val){
            return search(key, ptr->right);
        }
        return nullptr;
    }

    #pragma endregion
    //eliminazione 1 o 2 caso
    #pragma region //eliminazione 
    Node<T>* removefs(Node<T>* ptr){
        if(ptr->left == nullptr && ptr->right == nullptr){
            if(ptr == ptr->parent->left){
                ptr->parent->left = nullptr;
            }
            else{
                ptr->parent->right=nullptr;
            }
            return ptr;  // tornare il puntatore
        }

        if(ptr->left == nullptr && ptr->right != nullptr){
            ptr->right->parent = ptr->parent;
            if(ptr->parent->right == ptr){
                ptr->parent->right = ptr->right;
            }
            else{
                ptr ->parent->left = ptr->right;
            }
            return ptr; // tornare il puntatore
        }

        if(ptr->right == nullptr && ptr->left != nullptr){
            ptr->left->parent = ptr->parent;
            if(ptr->parent->right == ptr){
                ptr->parent->right = ptr->left;
            }
            else{
                ptr->parent->left = ptr->left;
            }
            return ptr; // tornare il puntatore
        }

        return nullptr;

    }

    //eliminazione "completa"
    Node<T>* remove(T key){
        if (isEmpty())
            return nullptr;

        Node<T>* node = this->search(key);        // prima di eliminare un nodo dobbiamo essere sicuri che esiste 
        if (node == nullptr){
        return nullptr;
        }

        Node<T>* temp = removefs(node);                   // il valore passato è il puntatore TROVATO CERCANDO IL VALORE DA ELIMINARE
        if(temp != nullptr)             // torniamo temp per assicurarci che sia stata effettuate l'eliminazione
            return temp;

        Node<T>* suc = succ(node);
        T swap = suc->val;                  // facciamo lo swap direttamente qua
        suc->val = node ->val;
        node->val = swap;
        temp = removefs(suc);
        return temp;
    }
    #pragma endregion

};
#endif