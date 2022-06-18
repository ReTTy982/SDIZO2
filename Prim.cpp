#include "Prim.hpp"

MatrixGraph Prim::generateMST(const MatrixGraph &graph)
{

    const size_t &edges = graph.getColumns();
    const size_t &vert = graph.getVerSize();
    const IndicenceMatrix &matrix = graph.getMatrix();

    std::cout << vert << std::endl;
    MatrixGraph mstGraph = MatrixGraph(false);
    BinHeap<Edge> queue;
    Array<bool> visited;
    for (size_t i = 0; i < vert; i++)
    {
        visited.push_back(false);
    }
    size_t firstVert = 0;
    for (size_t i = 0; i < vert; i++)
    {
        if (matrix[0][i] != 0)
        {
            queue.push(Edge(firstVert, i, matrix[0][i]));
            std::cout << queue.top().weight << std::endl;
        }
        
    }

    for (size_t addedEdges = 0; addedEdges < vert - 1;)
    {
        Edge candidate = queue.top();
        queue.pop(0);
        std::cout << "From, to , weight"
                  << " " << candidate.from << " " << candidate.to << " " << candidate.weight << std::endl;

        if (!visited[candidate.to])
        {
            visited[candidate.to] = true;
            mstGraph.addEdge(candidate.from, candidate.to, candidate.weight);
            for (size_t i = 0; i < vert; i++)
            {
                if (matrix[candidate.to][i] != 0)
                {
                    queue.push(Edge(candidate.to, i, matrix[candidate.to][i]));
                }
            }
            addedEdges++;
        }
    }

    return mstGraph;
}