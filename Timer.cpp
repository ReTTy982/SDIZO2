#include "Timer.hpp"
#include <iostream>
#include <vector>
using namespace std;
const vector<size_t> graphSize = {50, 70, 100,120,150};
const vector<size_t> fillFactor = {25, 50, 75, 99};

const size_t datasetGenerationloops = 5;

template <typename Algorithm>
const size_t Timer::generateMSTMatrix(const size_t &size, const size_t &fill)
{
    AverageTimeMeasure algorithmTimeAverage;
    for (size_t i = 0; i < datasetGenerationloops; i++)
    {
        MatrixGraph graph = MatrixGraph(false);
        ListGraph dummy_graph = ListGraph(false);
        RandomGraphGenerator::random(graph,dummy_graph,size, fill, false);
        algorithmTimeAverage.benchmarkStart();
        auto answer = Algorithm::generateMST(graph);
        algorithmTimeAverage.benchmarkStop();
    }
    return algorithmTimeAverage.getAvgElapsedNsec();
};
template <typename Algorithm>
const size_t Timer::generateMSTList(const size_t &size, const size_t &fill)
{
    AverageTimeMeasure algorithmTimeAverage;
    for (size_t i = 0; i < datasetGenerationloops; i++)
    {
        ListGraph graph = ListGraph(false);
        MatrixGraph dummy_graph = MatrixGraph(false);
        RandomGraphGenerator::random(dummy_graph,graph,size, fill, false);
        algorithmTimeAverage.benchmarkStart();
        auto answer = Algorithm::generateMST(graph);
        algorithmTimeAverage.benchmarkStop();
    }
    return algorithmTimeAverage.getAvgElapsedNsec();
};

void Timer::run()
{
    cout <<"MATRIX KRUSKAL\n"; 
    for(const auto &fill : fillFactor){
        for(const auto &size : graphSize){
            cout << size <<" " << generateMSTMatrix<Kruskal>(size,fill) << "\n";
        }
        cout << endl;
    }
    cout << "MATRIX PRIMA\n";
     for(const auto &fill : fillFactor){
        for(const auto &size : graphSize){
            cout << size <<" " << generateMSTMatrix<Prim>(size,fill) << "\n";
        }
        cout << endl;
    }
        cout << "LIST KRUSKAL\n";
     for(const auto &fill : fillFactor){
        for(const auto &size : graphSize){
            cout << size <<" " << generateMSTList<Kruskal>(size,fill) << "\n";
        }
        cout << endl;
    }
}