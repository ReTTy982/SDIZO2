#include "Timer.hpp"
#include <iostream>
#include <vector>
using namespace std;
const vector<size_t> graphSize = {50, 70, 100};
const vector<size_t> fillFactor = {25, 50, 75, 99};

const size_t datasetGenerationloops = 5;

template <typename Structure, typename Algorithm>
const size_t Timer::generateMST(const size_t &size, const size_t &fill)
{
    AverageTimeMeasure algorithmTimeAverage;
    for (size_t i = 0; i < datasetGenerationloops; i++)
    {
        Structure graph = Structure(false);
        RandomGraphGenerator<Structure>::random(graph, size, fill, false);
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
            cout << size <<" " << generateMST<MatrixGraph,Kruskal>(size,fill) << "\n";
        }
        cout << endl;
    }
}