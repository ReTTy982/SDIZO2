#include "MatrixGraph.hpp"
#include "Array.hpp"
#define BRESET "\x1B[0m"
#define BGREEN "\x1B[42m"
#define BMAGNETA "\x1B[45m"

using namespace std;
/*
void MatrixGraph::addEdge(const size_t &from, const size_t &to, long long weight)
{
    const auto &newSize = std::max(from, to) + 1;
    const auto oldSize = matrix.get_array_size();
    if (newSize > oldSize)
    {
        std::cout << "XD1" << std::endl;
        matrix.resize(newSize);

        const auto &edgesCount = matrix[0].get_array_size();
        for (size_t i = oldSize; i < newSize; i++)
        {
            std::cout << "SIZE:" << matrix[0].get_array_size() << std::endl;
            matrix[i].resize(edgesCount);
        }
    }
    for (int i = 0; i < matrix.get_array_size(); i++)
    {
        if (i == from && from == to)
        {
            matrix[i].push_back(weight);
        }
        else if (i == to)
        {
            matrix[i].push_back(weight);
        }
        else
        {
            matrix[i].push_back(0);
        }
    }
};
*/

void MatrixGraph::addEdge(const size_t &from, const size_t &to, long long weight)
{
    std::cout << "ADD1" << std::endl;
    size_t old_size;
    if (matrix.get_array_size() == 0)
    {
        old_size = 0;
    }
    else
    {
        old_size = matrix[0].get_array_size();
    }

    size_t new_size = std::max(from, to) + 1;

    size_t vert_size = matrix.get_array_size();
    std::cout << "DANE:" << old_size << " " << new_size << " " << vert_size << std::endl;
    if (new_size > old_size)
    {
        std::cout << "ADD3" << std::endl;
        matrix.resize(new_size);
        for (size_t i = old_size; i < new_size; i++)
        {
            std::cout << "!: " << matrix.get_array_size() << std::endl;
            std::cout << i << std::endl;
            std::cout << "?1: " << matrix[i].get_array_size() << std::endl;
            std::cout << "?2: " << matrix[i].get_array_size() << std::endl;
            matrix[i].fill(new_size);
            std::cout << "?3: " << matrix[i].get_array_size() << std::endl;
        }
    }

    for (size_t i = 0; i < new_size; i++)
    {

        std::cout << "OOR" << std::endl;
        if (i == from && from == to)
        {
            std::cout << "OOR1" << std::endl;
            matrix[from].resize(new_size);
            matrix[from][from] = weight;
        }
        else if (i == from)
        {
            std::cout << "OOR2" << std::endl;
            matrix[from].resize(new_size);
            matrix[from][to] = weight;
        }
        else
        {
            std::cout << "OOR45: " << matrix[i].get_array_size() << std::endl;
            if (matrix[i].get_array_size() < new_size)
            {
                matrix[i].push_back(0);
            }
        }
    }

    std::cout << "COS JEST NIE TAK: " << matrix[0].get_array_size() << std::endl;
}

const size_t MatrixGraph::getColumns()
{
    if (matrix.get_array_size() != 0)
    {
        size_t max_size = 0;
        for (size_t i = 0; i < matrix.get_array_size(); i++)
        {
            size_t temp = matrix[i].get_array_size();
            max_size = std::max(max_size, temp);
        }
        std::cout << "MAX: " << max_size << std::endl;
        return max_size;
    }
    else
        return 0;
}

const size_t MatrixGraph::getVerSize() const
{
    const size_t size = matrix.get_array_size();
    return size;
}

void MatrixGraph::print()
{
    const auto count = getColumns();
    const auto vertices = getVerSize();

    if (vertices == 0)
    {
        std::cout << BGREEN << "Graf jest pusty!" << BRESET << std::endl;

        return;
    }
    std::cout << "   " << BGREEN;
    for (size_t j = 0; j < count; j++)
    {
        std::cout << j << "  ";

        if (j < 10)
            std::cout << " ";
    }
    std::cout << BRESET << std::endl;

    for (size_t i = 0; i < vertices; i++)
    {
        std::cout << BMAGNETA << i << BRESET << " ";
        if (i < 10)
            std::cout << " ";

        for (size_t j = 0; j < count; j++)
        {
            std::cout << matrix[i][j] << " ";

            if (matrix[i][j] < 10 && matrix[i][j] > -1)
                std::cout << "  ";
            else if (matrix[i][j] > -10)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}