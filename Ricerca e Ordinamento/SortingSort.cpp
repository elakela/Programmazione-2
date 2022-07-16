#include<iostream>
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Sorting(int x[], int dim){
    for(int i = 0; i<dim; i++){
        int index = i;
        for (int j = i+1; j<dim; j++){
            if (x[j] < x[i])
            index = j;
        }
        if (index!=i)
            swap(x[i], x[index]);
    }
}

int main(){
    int x[] = {2, 5, 3, 4, 1, 9, 8};
    for(int i = 0; i<7; i++)
        cout << x[i];
    cout << endl;
    Sorting(x, 7);
    for(int i = 0; i<7; i++)
        cout << x[i];
}