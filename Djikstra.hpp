#include "Array.hpp"
#include "BinHeap.hpp"
#include "MatrixGraph.hpp"
#include "ListGraph.hpp"
#include <iostream>
#include "Node.hpp"

class Djikstra
{

    struct DjikstraNode
    {
        size_t distance;
        size_t vertex;
        size_t current;

        DjikstraNode(const size_t &distance, const size_t &vertex)
        {
            this->distance = distance;
            this->vertex = vertex;
        }
    };

public:
    static Array<Node> getShortestPath(const MatrixGraph &graph, const size_t &from);
    static Array<Node> getShortestPath(const ListGraph &graph, const size_t &from);
};