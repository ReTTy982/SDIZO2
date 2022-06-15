#include <iostream>
#include "MatrixGraph.hpp"
using namespace std;

int main(){
    MatrixGraph graph = MatrixGraph(true);
    graph.addEdge(0,1,4);
    graph.print();
    graph.addEdge(0,2,5);
    graph.print();
    graph.addEdge(0,3,6);
    graph.print();
    graph.addEdge(0,4,8);
    graph.print();
    cout << graph.matrix[1][0];



    return 0;

}