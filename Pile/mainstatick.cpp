#include"statickstack.h"

int main(){
    Statick<int> pila(4);

    pila.push(0);
    pila.push(11);
    pila.push(13);
    pila.push(23);
    pila.push(18);
    cout << pila;
    system("pause");
    system("cls");

    pila.pop();
    pila.pop();
    cout << pila;
    cout << pila.getTop();
}