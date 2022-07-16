#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int search(int x[], int dim, int key){
    int start = 0;
    int end = dim;
    bool found = false;
    int pos = -1;
   
    while (!found && (start!=end)) {
        int q = start + ((end-start)/2);
        cout << start << " " << q << " " << end << endl;
        if (key == x[q]){
            pos = q;
            found = true;
        }
        else if (key < x[q]){
            end = q;        
        }
        else {
            start = q+1;
        }
    }
    return pos;
}


int main(){
    srand(time(NULL));
    int x[] = {1, 2, 3, 4, 5, 6, 7};
    int s = rand()%10;
    int pos = search(x, 7, s);
    if (pos == -1)
        cout << "sorry, value " << s << " not found";
    else {
        cout << "value " << s << " found at the " << pos << " position of the array";
    }
}