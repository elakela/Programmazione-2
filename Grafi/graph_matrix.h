#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H
#include <iostream>
using namespace std;

template <typename T>
class Vertex{
    private:
    T val;
    template <typename U>
    friend class Graph;

    public:
    Vertex(T key): val(key){};
    Vertex():Vertex(NULL){};

    //controllo se è uguale

    bool operator=(Vertex<T> &val){
        return this->val == val.val;
    }

    void setVal(T key){
        this->val = key;
    }

    T getVal(){
        return this->val;
    }

    friend ostream& operator<<(ostream& out, Vertex<T> &vertice){
        out << vertice.key;
        return out;
    }

};

template <typename T>
class Graph{
    private:
    Vertex<T>** vertices;
    bool** exl;
    int maxSize;
    int size = 0;
    bool isOriented;

    public: 
    //costruttore
    Graph(T dim, bool oriented) : maxSize(dim), isOriented(oriented){
        vertices = new Vertex<T>*[maxSize];
        exl = new bool*[maxSize];
        for(int i = 0; i<maxSize; i++){
            exl[i] = new bool[maxSize]{0};
        }
    }

    //addVertex
    void addVertex(T val){
        if(size == maxSize){
            cout << "pieno" << endl;
            return;
        }

        vertices[size++] = new Vertex<T>(val);
    }
    //addEdge
    void addEdge(T key1, T key2){
       int i = search(key1);
       int j = search(key2);
    
       if (i!=-1 && j!=-1){
        exl[i][j] = true;
        if(!isOriented){
            exl[j][i] = true;
        }
       }

       else if(i == -1){
        cout << "value " << key1 << " not found" << endl;
       }

       else{
        cout << "value " << key2 << " not found" << endl; 
       }
    }

    //search
    int search(T val){
        if(size == 0){
            return -1;
        }
        
        for (int i = 0; i<size; i++){
            if(vertices[i]->val == val)
            return i;
        }

        return -1;
    }

    //overload di stampa
    friend ostream& operator<< (ostream& out, Graph<T> &grafo){
        if(grafo.size==0){
            out << "empty" << endl;
            return out;
        }

        out << "size: " << grafo.size << " - max: " << grafo.maxSize << endl;
        for (int i = 0; i<grafo.size; i++){
            out << "v[" << i << "]=" << grafo.vertices[i] << " = " << grafo.vertices[i]->getVal() <<  "\t";
        }

        out << endl;

        for(int i = 0; i<grafo.size; i++){
            for(int j = 0; j<grafo.size; j++){
                out << "  " << grafo.exl[i][j] << "  ";
            }
            out << endl;
        }
        return out;
    }
};
#endif