#include "Djikstra.hpp"

Array<Node> Djikstra::getShortestPath(const MatrixGraph &graph, const size_t &from)
{
    const size_t &vert = graph.getVerSize();
    const size_t &edges = graph.getColumns();
    const IndicenceMatrix &matrix = graph.getMatrix();

    Array<Node> pathWeights;
    BinHeap<Node> vertexesToProcess;
    Array<bool> visited;

    for (size_t i = 0; i < vert; i++)
    {
        pathWeights.push_back(Node(i));
        visited.push_back(false);
    }

    if (vert == 0)
    {
        return pathWeights;
    }

    pathWeights[from] = Node(0, from, from);
    for (size_t i = 0; i < vert; i++)
    {
        if (i == from)
        {
            vertexesToProcess.push(Node(0, from, i));
        }
        else
        {
            vertexesToProcess.push(Node(i));
        }
    }

    while (vertexesToProcess.get_array().get_array_size() != 0)
    {
        const size_t curVertex = vertexesToProcess.top().current;
        vertexesToProcess.pop(0);
        visited[curVertex] = true;

        for (size_t i = 0; i < vert; i++)
        {
            if (matrix[curVertex][i] != 0)
            {
                if (matrix[curVertex][i] + pathWeights[curVertex].weight < pathWeights[i].weight)
                {
                    pathWeights[i].weight = matrix[curVertex][i] + pathWeights[curVertex].weight;
                    pathWeights[i].prev = curVertex;
                    if (visited[i] == false)
                    {
                        vertexesToProcess.push(Node(pathWeights[i].weight, pathWeights[i].prev, pathWeights[i].current));
                    }
                }
            }
        }
    }

    return pathWeights;
}

Array<Node> Djikstra::getShortestPath(const ListGraph &graph, const size_t &from)
{
    const size_t &vert = graph.getVerSize();

    Array<Node> pathWeights;
    BinHeap<Node> vertexesToProcess;
    Array<bool> visited;

    for (size_t i = 0; i < vert; i++)
    {
        pathWeights.push_back(Node(i));
        visited.push_back(false);
    }

    if (vert == 0)
    {
        return pathWeights;
    }

    pathWeights[from] = Node(0, from, from);

    for (size_t i = 0; i < vert; i++)
    {
        if (i == from)
        {
            vertexesToProcess.push(Node(0, from, i));
        }
        else
        {
            vertexesToProcess.push(Node(i));
        }
    }

    while (vertexesToProcess.get_array().get_array_size() != 0)
    {
        const size_t curVertex = vertexesToProcess.top().current;
        vertexesToProcess.pop(0);
        visited[curVertex] = true;
        const auto &edges_array = graph.getArrayOfEdges(curVertex);
        for (size_t i = 0; i < edges_array.get_array_size(); i++)
        {
            if (edges_array[i].weight + pathWeights[curVertex].weight < pathWeights[edges_array[i].edge_to].weight)
            {
                pathWeights[edges_array[i].edge_to].weight = edges_array[i].weight + pathWeights[curVertex].weight;
                pathWeights[edges_array[i].edge_to].prev = curVertex;
                if (visited[edges_array[i].edge_to] == false)
                {
                    vertexesToProcess.push(Node(pathWeights[edges_array[i].edge_to].weight, pathWeights[edges_array[i].edge_to].prev, pathWeights[edges_array[i].edge_to].current));
                }
            }
        }
    }
    return pathWeights;
}
