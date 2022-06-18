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
                std::cout << queue.top().weight << std::endl;
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