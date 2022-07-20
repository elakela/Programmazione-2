#include "bst.h"

int main(){
    bst<int> albero;
    cout << albero.isEmpty();
    albero.inorder();

    albero.insert(24);
    albero.insert(27);
    albero.insert(31);
    albero.insert(29);
    albero.insert(12);
    albero.insert(15);
    albero.insert(11);
    
    albero.inorder();
    system("pause");
    system("cls");
    
    albero.preorder();
    system("pause");
    system("cls");

    albero.postorder();
    system("pause");
    system("cls");

    cout << *(albero.min());
    cout << *(albero.max());
    system("pause");
    system("cls");
    
    //controllare prima di stampare il successore se esiste, in quel caso stamparlo altrimenti no
    cout << " il successore di 24 = " << *(albero.succ(albero.search(24)));
    if ((albero.succ(albero.search(27)))!=nullptr){  
    cout << " il successore di 31 = " << *(albero.succ(albero.search(27)));}
    else {cout << endl << "no" << endl;}
    
    
    cout << "Il predecessore di 24 = " << *(albero.prec(albero.search(24)));

    albero.remove(29);
    
    albero.inorder();
    system("pause");
    system("cls");
    
    
    albero.remove(27);
    
    albero.inorder();
    system("pause");
    system("cls");
    
    albero.remove(12);
    
    albero.inorder();
    
}