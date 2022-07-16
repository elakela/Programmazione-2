#include "dllist.h"

int main(){
    DLList<int> lista;

    lista.insertHead(10);
    lista.insertHead(15);
    lista.insertHead(23);
    lista.insertHead(28);

    cout << lista;
    system("pause");
    system("cls");

    lista.insertTail(19);
    lista.insertTail(2);
    cout << lista;
    system("pause");
    system("cls");

    lista.removeHead();
    lista.removeHead();
    lista.removeHead();
    cout << lista << endl;
    system("pause");
    system("cls");

    lista.removeTail();
    cout << lista << endl;
    system("pause");
    system("cls");


    cout << endl;
    lista.removeKey(19);
    cout << lista;
    lista.removeKey(13);
    system("pause");
    system("cls");
    cout << lista;

    lista.insertOrder(8);
    lista.insertOrder(23);
    lista.insertOrder(20);
    lista.insertOrder(15);
    system("pause");
    system("cls");
    cout << lista;
    
}
