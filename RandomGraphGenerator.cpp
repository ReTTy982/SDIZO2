#pragma once
#include "RandomGraphGenerator.hpp"

const static size_t MAX_COST = 100;



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

    if(!isDirected){
        edges /=2;
    }

    edges *= 0.01 * fillFactor;
    std::vector<size_t> neededVert, seenFrom, seenTo, aviableVert;

    for (size_t i = 0; i < vertexCount; i++)
    {
        neededVert.push_back(i);
        aviableVert.push_back(i);
    }
    std::shuffle(neededVert.begin(), neededVert.end(),generator);
    std::shuffle(aviableVert.begin(), aviableVert.end(),generator);
    while (neededVert.size() != 1)
    {
        size_t from = neededVert.back();
        neededVert.pop_back();
        size_t to = neededVert.back();
        seenFrom.push_back(from);
        seenTo.push_back(to);
        size_t weight = randomNumberWithinRange(1,MAX_COST);
        graph.addEdge(from, to, weight);
        if(!isDirected){
            graph.addEdge(from,to,weight);
            seenFrom.push_back(to);
            seenTo.push_back(from);
        }
        edges--;

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
            std::shuffle(aviableVert.begin(), aviableVert.end(),generator);
            size_t weight = randomNumberWithinRange(1,MAX_COST);
            graph.addEdge(from, aviableTo.back(), weight);
            if(!isDirected){
                graph.addEdge(aviableTo.back(),from, weight);
            }

            edges--;
        }
        else
        {
            aviableVert.pop_back();
        }

    }
}