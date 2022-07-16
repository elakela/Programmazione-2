#include<iostream>
using namespace std;

void printArray(int array[], int size) {
  int i;
  for (i = 0; i <= size; i++)
    cout << array[i] << " ";
  cout << endl;
}

void swap (int *a, int *b){ //vanno passati i valori dereferenziati
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int num[], int p, int q){
    int j = p-1;
    int pivot = num[q];
    cout << endl << pivot << endl;
    for (int i = p; i<q; i++){ //deve essere minore di q
        if(num[i] <= pivot){
            j++;
            swap(&num[i], &num[j]);
            printArray(num, q);
        }
        printArray(num, q);
    } 
    
    swap(&num[j+1], &num[q]);
    printArray(num, q);
    return (j+1);
}

void quickSort(int num[], int p, int q){
    if(p>=q)
        return;
    
    int r = partition(num, p, q);
    cout << endl << r;
    quickSort(num, p, r-1);
    quickSort(num, r+1, q);
}

int main() {
  int data[] = {1, 4, 3, 1, 0, 10, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Unsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  quickSort(data, 0, n - 1);
  
  cout << "Sorted array in ascending order: \n";
  printArray(data, n-1);
}

