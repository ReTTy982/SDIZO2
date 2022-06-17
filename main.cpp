#include <iostream>
#include "MatrixGraph.hpp"
#include "Kruskal.hpp"
#include "RandomGraphGenerator.hpp"
using namespace std;

int main()
{
    /*
    MatrixGraph graph = MatrixGraph(false);
    graph.addEdge(0,1,4);
    graph.addEdge(1,3,8);
    graph.addEdge(1,2,8);
    graph.addEdge(1,3,11);
    graph.addEdge(2,4,2);
    graph.addEdge(2,5,4);
    graph.addEdge(3,4,7);
    graph.addEdge(3,6,1);
    graph.addEdge(4,6,6);
    graph.addEdge(5,6,2);
    graph.print();
    */
    /*
    10 7
0 1 4
0 3 8
1 2 8
1 3 11
2 4 2
2 5 4
3 4 7
3 6 1
4 6 6
5 6 2
*/

    MatrixGraph graph = MatrixGraph(false);
    RandomGraphGenerator<MatrixGraph>::random(graph, 8, 50, false);
    graph.print();

    MatrixGraph graph_kurskal = Kruskal::generateMST(graph);
    

    graph_kurskal.print();
    return 0;
}