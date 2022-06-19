#include "BellmanFord.hpp"

Array<Node> BellmanFord::getShortestPath(const MatrixGraph &graph, const size_t &from)
{
    const size_t &vert = graph.getVerSize();
    const IndicenceMatrix &matrix = graph.getMatrix();

    Array<Node> pathWeights;

    for (size_t i = 0; i < vert; i++)
    {
        pathWeights.push_back(Node(i));
    }

    if (vert == 0)
    {
        return pathWeights;
    }

    pathWeights[from] = Node(0, from, from);

    for (size_t loop_count = 0; loop_count < vert - 1; loop_count++)
    {

        for (size_t start_vert = 0; start_vert < vert; start_vert++)
        {
            for (size_t end_vert = 0; end_vert < vert; end_vert++)
            {
                if (matrix[start_vert][end_vert] > 0)
                {
                    if (matrix[start_vert][end_vert] + pathWeights[start_vert].weight < pathWeights[end_vert].weight)
                    {
                        pathWeights[end_vert].weight = matrix[start_vert][end_vert] + pathWeights[start_vert].weight;
                        pathWeights[end_vert].prev = start_vert;
                    }
                }
            }
        }
    }
    return pathWeights;
}

Array<Node> BellmanFord::getShortestPath(const ListGraph &graph, const size_t &from)
{

    const size_t &vert = graph.getVerSize();
    Array<Node> pathWeights;

    for (size_t i = 0; i < vert; i++)
    {
        pathWeights.push_back(Node(i));
    }

    if (vert == 0)
    {
        return pathWeights;
    }

    pathWeights[from] = Node(0, from, from);

    for (size_t loop_count = 0; loop_count < vert - 1; loop_count++)
    {
        for (size_t start_vert = 0; start_vert < vert; start_vert++)
        {
            const auto &edges_array = graph.getArrayOfEdges(start_vert);
            for (size_t i = 0; i < edges_array.get_array_size(); i++)
            {
                if (edges_array[i].weight + pathWeights[start_vert].weight < pathWeights[edges_array[i].edge_to].weight)
                {
                    pathWeights[edges_array[i].edge_to].weight =edges_array[i].weight + pathWeights[start_vert].weight;
                    pathWeights[edges_array[i].edge_to].prev=start_vert;
                }
            }
        }
    }
    return pathWeights;
}