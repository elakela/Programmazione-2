#include "queue.h"

int main(){
    Queue<int> coda;

    coda.enqueue(1);
    coda.enqueue(2);
    coda.enqueue(3);
    coda.enqueue(4);

    cout << coda;

    cout << endl;
    system("pause");

    system("cls");
    coda.dequeue();
    coda.dequeue();
 

    cout << coda;


}