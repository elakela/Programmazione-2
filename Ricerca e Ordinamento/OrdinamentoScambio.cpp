#include<iostream>
using namespace std;

void swap(int &x, int &y){ //i valori devono essere dereferenziati
    int temp = y;
    y = x;
    x = temp;
}

void order(int x[], int dim){
    for(int i = 0; i<dim; i++){
        for (int j = i+1; j<dim; j++){
            if(x[j] < x[i]){
                swap(x[i], x[j]);
            }
        }
    }
}


int main(){
    int x[] = {2, 4, 9, 1, 3, 6, 5, 2};
    for (int i = 0; i<8; i++)
    {
        cout << x[i];
    }
    cout << endl;
    order(x, 8);
    for (int i = 0; i<8; i++)
    {
        cout << x[i];
    }
}