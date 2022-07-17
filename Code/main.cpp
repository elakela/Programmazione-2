#include "statick_queue.h"

int main(){
    StatickQ<int> coda(6);
    cout << coda.isEmpty() << endl;
    cout << coda;
    
    coda.enqueue(1);
    coda.enqueue(2);
    coda.enqueue(3);
    coda.enqueue(4);
    coda.enqueue(5);
    coda.enqueue(6);
    coda.enqueue(7);
    cout << coda;
    system("pause");
    system("cls");

    coda.dequeue();
    coda.dequeue();
    coda.dequeue();
    cout << coda;
    system("pause");
    system("cls");
    
    coda.dequeue();
    coda.dequeue();
    coda.dequeue();
    coda.dequeue();
    coda.dequeue();
    cout << coda;
}