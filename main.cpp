#include <iostream>
#include "MatrixGraph.hpp"
using namespace std;

int main(){
    MatrixGraph graph = MatrixGraph(true);
    graph.addEdge(0,1,4);
    graph.print();
    graph.addEdge(1,0,5);
    graph.print();
    graph.addEdge(2,0,6);
    graph.print();
    graph.addEdge(3,0,8);
    graph.print();
    cout << graph.matrix[1][0];



    return 0;

}