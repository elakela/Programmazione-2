#include "graph_matrix.h"

int main(){
    Graph<int> grafo(30, 0);
    cout << grafo;
    grafo.addVertex(15);
    grafo.addVertex(18);
    cout << grafo;
    system("pause");
    system("cls");
    
    grafo.addEdge(15, 18);
    cout << grafo;

}