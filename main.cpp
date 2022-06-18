#include <iostream>
#include "MatrixGraph.hpp"
#include "Kruskal.hpp"
#include "RandomGraphGenerator.hpp"
#include "Timer.hpp"
#include "Prim.hpp"
#include "ListGraph.hpp"
using namespace std;

int main()
{
    /*
        ListGraph graph = ListGraph(true);
        graph.addEdge(0, 1, 4);
        graph.addEdge(1, 3, 8);
        graph.addEdge(1, 2, 8);
        graph.addEdge(1, 3, 11);
        graph.addEdge(2, 4, 2);
        graph.addEdge(2, 5, 4);
        graph.addEdge(3, 4, 7);
        graph.addEdge(3, 6, 1);
        graph.addEdge(4, 6, 6);
        graph.addEdge(5, 6, 2);
        graph.addEdge(0, 1, 5);
        graph.print();
        */
    /*
        ListGraph list_graph = ListGraph(true);
        MatrixGraph matrix_graph = MatrixGraph(true);
        RandomGraphGenerator::random(matrix_graph,list_graph,5,99,true);
        matrix_graph.print();
        list_graph.print();
        MatrixGraph matrix_temp = Kruskal::generateMST(matrix_graph);
        ListGraph list_temp = Kruskal::generateMST(list_graph);
        matrix_temp.print();
        list_temp.print();

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
    /*
        MatrixGraph graph = MatrixGraph(false);
        RandomGraphGenerator<MatrixGraph>::random(graph, 8, 50, false);
        graph.print();

        MatrixGraph graph_kurskal = Kruskal::generateMST(graph);


        graph_kurskal.print();
        */
    Timer timer;
    timer.run();
    /*
        MatrixGraph graph = MatrixGraph(false);
        RandomGraphGenerator<MatrixGraph>::random(graph, 6, 25, false);
        graph.print();
        MatrixGraph graph_prim = Prim::generateMST(graph);
        graph_prim.print();
        */
    /*
        MatrixGraph graph1 = MatrixGraph(false);
        RandomGraphGenerator<MatrixGraph>::random(graph1, 8, 25, false);
        graph1.print();
        MatrixGraph graph_kruskal = Kruskal::generateMST(graph1);
        graph_kruskal.print();

    */
    return 0;
}