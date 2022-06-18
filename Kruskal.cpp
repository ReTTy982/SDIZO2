#include "Kruskal.hpp"
#include "DisjointSets.hpp"

MatrixGraph Kruskal::generateMST(const MatrixGraph &graph)
{

    const size_t &edges = graph.getColumns();
    const size_t &vert = graph.getVerSize();
    const IndicenceMatrix &matrix = graph.getMatrix();

    MatrixGraph mstGraph = MatrixGraph(false);

    BinHeap<Edge> queue;

    DisjointSets unionArray(vert);
    if (vert == 0)
    {
        return mstGraph;
    }

    for (size_t vertex = 0; vertex < vert; vertex++)
    {
        for (size_t edge = 0; edge < edges; edge++)
        {

            if (matrix[vertex][edge] > 0)
            {

                queue.push(Edge(vertex, edge, matrix[vertex][edge]));
            }
        }
    }
    for (size_t addedEdges = 0; addedEdges < vert - 1;)
    {
        // trzeba wyjatek na puste

        const auto &node = queue.top();

        const auto &parentA = unionArray.findNode(node.from);

        const auto &parentB = unionArray.findNode(node.to);

        if (parentA != parentB)
        {

            unionArray.nodeUnion(node.from, node.to);
            mstGraph.addEdge(node.from, node.to, node.weight);
            addedEdges++;
        }
        queue.pop(0);
    }
    return mstGraph;
}

ListGraph Kruskal::generateMST(const ListGraph &graph)
{
    const size_t &vert = graph.getVerSize();

    ListGraph mstGraph = ListGraph(false);
    BinHeap<Edge> queue;
    DisjointSets unionArray(vert);

    if(vert==0){
        return mstGraph;
    }
    for(size_t vertex=0;vertex<vert;vertex++){
        const auto &edges_array = graph.getArrayOfEdges(vertex);
        for(size_t edges=0;edges<edges_array.get_array_size();edges++){
            if(edges_array[edges].edge_to <vertex){
                continue;
            }
            queue.push(Edge(vertex,edges_array[edges].edge_to,edges_array[edges].weight));
        }
    }


    for (size_t addedEdges = 0; addedEdges < vert - 1;)
    {
        // trzeba wyjatek na puste

        const auto &node = queue.top();

        const auto &parentA = unionArray.findNode(node.from);

        const auto &parentB = unionArray.findNode(node.to);

        if (parentA != parentB)
        {

            unionArray.nodeUnion(node.from, node.to);
            mstGraph.addEdge(node.from, node.to, node.weight);
            addedEdges++;
        }
        queue.pop(0);
    }
    return mstGraph;
}