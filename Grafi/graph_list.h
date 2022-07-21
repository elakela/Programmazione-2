#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H
#include "list.h"

template <typename T> 
class GraphVertex : public list<T>{
    public:
    GraphVertex(T key) : list<T>(){
        list<T>::insertTail(key);
    } 

    friend ostream& operator<< (ostream& out, GraphVertex<T> &vertices){
        out << "Vertex " << vertices.getHead()->getVal();
        out << "\t"<< "Adjiacency: ";
        Node<T>* ptr = vertices.getHead();
        while(ptr){
            out << ptr->getVal() << "->";
            ptr = ptr->getNext();
        }

        return out;
    }
};


template <typename T>
class GraphList{
    private:
    list<GraphVertex<T>> vertices;
    int nvertices = 0;
    bool isOriented;

    public: 
    GraphList(bool oriented = true) : isOriented(oriented){};

    //aggiungo un vertice
    void addVertex(T val){
        GraphVertex<T> toadd(val);
        vertices.insertTail(toadd);
        nvertices++;
    }

    //ricerca
    Node<GraphVertex<T>>* search(T val){
        if(nvertices == 0){
            return nullptr;
        }

        Node<GraphVertex<T>>* ptr = vertices.getHead();
        while(ptr){
            if(ptr->getVal().getHead()->getVal() == val){
            return ptr;
            }
            ptr= ptr->getNext();
        }
        return nullptr;
    }

     //aggiungo un arco
    void addEdge(T key1, T key2){
        Node<GraphVertex<T>>* node1 = this->search(key1);
        Node<GraphVertex<T>>* node2 = this->search(key2);

        if(node1 && node2){
            node1->getVal().insertTail(key2);
            if(!isOriented){
                node2->getVal().insertTail(key1);
            }
        }
    }

    friend ostream& operator<< (ostream& out, GraphList<T> &lista){
        out << lista.vertices;
        return out;
    }
};

#endif