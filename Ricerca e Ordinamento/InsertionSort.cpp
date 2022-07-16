#include<iostream>
#include<cstdlib>
using namespace std;

void Insertion(int* vett, int dim){
   
    int j;
    int temp;
   
    for (int i = 1; i<dim; i++){
        temp = vett[i];
        for(j = i; j>0; j--){ //j non va nuovamente indicato come int
            if (temp<vett[j-1]){
                vett[j] = vett[ j - 1 ];
                }
            else break;
        }
        vett[j] = temp;
    }
    
}

int main() {
    int dim = 10;
    int vett[dim];

    for (int i = 0; i < 10;i++) {
        vett[i] = rand() % 100;
    }

    cout << "Vettore non ordinato:" << endl;
    for (int i = 0; i < 10;i++) {
        cout << vett[i] << " ";
    }
    cout << endl;

    Insertion(vett, dim);

    cout << "Vettore ordinato:" << endl;
    for (int i = 0; i < 10;i++) {
        cout << vett[i] << " ";
    }

}
