#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

void merge(int num[], int p, int q, int r){
    int dim1 = q-p+1;
    int dim2 = r - q;
    cout << " la dimensone è " << dim1 << dim2 << endl;

    int* L = new int[dim1+1];
    int* R = new int[dim2+1];

    for (int i=0; i<dim1; i++){
        L[i] = num[p+i];
    }

    for (int j = 1; j<=dim2; j++){
        R[j-1] = num[q+j];
    }

    L[dim1] = INT_MAX;
    R[dim2] = INT_MAX;

    for (int i=0; i<dim1; i++){
        cout << L[i];
    }
    cout << endl;
    for (int j = 1; j<=dim2; j++){
        cout <<  R[j-1];
    }
    cout << endl;

    int i = 0, j = 0, k = p;
    for (k = p; k<=r; k++){
        if (L[i] < R[j]){
            num[k] = L[i];
            i++;
        }

        else{
            num[k] = R[j];
            j++;
        }
    }
    for (k = p; k<=r; k++){
        cout << num[k];
    }

    delete[] L;
    delete[] R;
}

void mergesort(int num[], int p, int r){
    if (p<r) {
        int q = floor((p+r)/2.0);
        cout << "i valori sono: " << q << " " << p << " " << r << endl;
        mergesort(num, p, q);
        mergesort(num, q+1, r);
        merge(num, p, q, r);
    }
}

int main() {
    int dim = 10;
    int vett[10];

    for (int i = 0; i < 10;i++) {
        vett[i] = rand() % 100;
    }

    cout << "Vettore non ordinato:" << endl;
    for (int i = 0; i < dim;i++) {
        cout << vett[i] << " ";
    }
    cout << endl;

    mergesort(vett, 0, dim - 1);

    cout << "Vettore ordinato:" << endl;
    for (int i = 0; i < dim;i++) {
        cout << vett[i] << " ";
    }

}