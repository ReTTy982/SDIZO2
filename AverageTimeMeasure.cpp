#include <iostream>
#include <chrono>
#include "AverageTimeMeasure.hpp"


template <typename T>
void AverageTimeMeasure<T>::benchmarkStart()
{
    start = std::chrono::high_resolution_clock::now();
}
template <typename T>
void AverageTimeMeasure<T>::benchmarkStop()
{
    end = std::chrono::high_resolution_clock::now();
    elapsed += end - start;
    times++;
}
template <typename T>
T AverageTimeMeasure<T>::getAvgElapsedNsec()
{

    return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count() / times;
}

template class AverageTimeMeasure<unsigned long long>;