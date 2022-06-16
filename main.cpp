#include <iostream>
#include "MatrixGraph.hpp"
using namespace std;

int main(){
    MatrixGraph graph = MatrixGraph(false);
    graph.addEdge(0,1,4);
    cout << "XD1" << endl;
    graph.print();
    
    cout << "XD2" << endl;
    graph.addEdge(1,2,5);
    cout << "XD3" << endl;
    graph.print();
    cout << "XD4" << endl;
    graph.addEdge(2,0,6);
    graph.print();
    graph.addEdge(3,0,6);
    graph.addEdge(3,1,5);
    graph.addEdge(3,2,4);
    graph.addEdge(3,3,1);
    graph.print();
    



    return 0;

}