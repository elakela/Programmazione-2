#include "graph_list.h"

int main(){
    GraphList<int> grafo;
    grafo.addVertex(13);
    grafo.addVertex(15);
    cout << grafo << endl;
    grafo.addEdge(13, 15);
    cout << grafo;
}