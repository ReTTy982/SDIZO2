#pragma once
#include "RandomGraphGenerator.hpp"

const static size_t MAX_COST = 20;



template <typename T>
size_t RandomGraphGenerator<T>::randomNumberWithinRange(const size_t &first, const size_t &second)
{
    std::uniform_int_distribution<size_t> distribution(first, second);
    return distribution(generator);
}

template <typename T>
void RandomGraphGenerator<T>::random(T &graph, size_t vertexCount, size_t fillFactor, const bool &isDirected)
{

    size_t edges;
    edges = vertexCount * (vertexCount - 1);

    edges *= 0.01 * fillFactor;
    std::vector<size_t> neededVert, seenFrom, seenTo, aviableVert;

    for (size_t i = 0; i < vertexCount; i++)
    {
        neededVert.push_back(i);
        aviableVert.push_back(i);
    }
    std::random_shuffle(neededVert.begin(), neededVert.end());
    std::random_shuffle(aviableVert.begin(), aviableVert.end());
    while (neededVert.size() != 1)
    {
        size_t from = neededVert.back();
        neededVert.pop_back();
        size_t to = neededVert.back();
        seenFrom.push_back(from);
        seenTo.push_back(to);
        graph.addEdge(from, to, randomNumberWithinRange(1, MAX_COST));
        edges--;
        /*
                if (neededVert.size() % 2 == 0)
                {
                    std::cout << "SIZE:X " << neededVert.size() << std::endl;
                    size_t from = neededVert.back();
                    neededVert.pop_back();
                    size_t to = neededVert.back();
                    neededVert.pop_back();
                    seenFrom.push_back(from);
                    seenTo.push_back(to);
                    graph.addEdge(from, to, randomNumberWithinRange(1, MAX_COST));
                    edges--;
                }

                else
                {
                    size_t from = neededVert.back();
                    std::cout << "FROM:X " << from << std::endl;
                    neededVert.pop_back();
                    size_t to = randomNumberWithinRange(0, vertexCount - 1);
                    while (to == from)
                    {
                        to = randomNumberWithinRange(0, vertexCount - 1);
                    }
                    seenFrom.push_back(from);
                    seenTo.push_back(to);
                    graph.addEdge(from, to, randomNumberWithinRange(1, MAX_COST));
                    edges--;
                }
                */
    }
    const IndicenceMatrix &matrix = graph.getMatrix();
    while (edges != 0)
    {

        size_t from = aviableVert.back();
        std::vector<size_t> aviableTo;

        for (size_t i = 0; i < matrix.get_array_size(); i++)
        {
            if (matrix[from][i] == 0 && from != i)
            {
                aviableTo.push_back(i);
            }
        }
        if (aviableTo.size() != 0)
        {
            std::random_shuffle(aviableVert.begin(), aviableVert.end());
            graph.addEdge(from, aviableTo.back(), randomNumberWithinRange(1, MAX_COST));

            edges--;
        }
        else
        {
            aviableVert.pop_back();
        }

        /*
        std::cout << "EDGES: " << edges << std::endl;
        size_t from = randomNumberWithinRange(0, vertexCount - 1);
        size_t to = randomNumberWithinRange(0, vertexCount-1);
        for (size_t i = 0; i < seenFrom.size(); i++)
        {
            while (seenFrom[i] == from && seenTo[i] == to)
            {
                to = randomNumberWithinRange(0, vertexCount-1);
            }
        }
        graph.addEdge(from, to, randomNumberWithinRange(1, MAX_COST));
        seenFrom.push_back(from);
        seenTo.push_back(to);
        edges--;
        */
    }
}