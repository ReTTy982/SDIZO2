#include "MatrixGraph.hpp"
#include "Array.hpp"
#define BRESET  "\x1B[0m"
#define BGREEN "\x1B[42m"
#define BMAGNETA "\x1B[45m"


using namespace std;

void MatrixGraph::addEdge(const size_t &from, const size_t &to, long long weight)
{
    const auto &newSize = std::max(from, to) + 1;
    const auto oldSize = matrix.get_array_size();
    if (newSize > oldSize)
    {
        std::cout << "XD" << std::endl;
        matrix.resize(newSize);

        const auto &edgesCount = matrix[0].get_array_size();
        for (size_t i = oldSize; i < newSize; i++)
        {
            std::cout << "SIZE:" << matrix[0].get_array_size() << std::endl;
            matrix[i].resize(edgesCount);
        }
    }
    for (int i =0;i<matrix.get_array_size();i++){
        if(i==from){
            if(!isDirected){
                matrix[i][to]=weight;
            }
            else{
                matrix[i].push_back(0);
            }
        }
        else if(i==to){
            matrix[i].push_back(weight);
        }
        else{
            matrix[i].push_back(0);
        }
    }

};

const size_t MatrixGraph::getRowSize() 
{
    if (matrix.get_array_size() != 0)
        return matrix[0].get_array_size();
    else
        return 0;
}

const size_t MatrixGraph::getColumnSize(){
    return matrix.get_array_size();
}

void MatrixGraph::print() 
{
    const auto &count = getRowSize();
    const auto &vertices = getColumnSize();

    if (vertices == 0) {
        std::cout << BGREEN << "Graf jest pusty!" << BRESET << std::endl;
        return;
    }

    std::cout << "   " << BGREEN;
    for (size_t j = 0; j < count; j++) {
        std::cout << j << "  ";

        if (j < 10)
            std::cout << " ";
    }
    std::cout << BRESET << std::endl;

    for (size_t i = 0; i < vertices; i++) {
        std::cout << BMAGNETA << i << BRESET << " ";
        if (i < 10)
            std::cout << " ";

        for (size_t j = 0; j < count; j++) {
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