#pragma once

#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include "MatrixGraph.hpp"
#include <iterator>
#include <bits/stdc++.h>

static unsigned seed= std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine generator(seed);

template <typename T>
class RandomGraphGenerator{
    

    static size_t randomNumberWithinRange(const size_t &first , const size_t &secound);


public:
    static void random(T &graph, size_t vertexCount, size_t fillFactor, const bool &isDirected);

};

#include "RandomGraphGenerator.cpp"
