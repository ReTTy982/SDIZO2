#pragma once
#include <stdio.h>


struct Edge{
    Edge(size_t &from,size_t &to,long long weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    Edge(){};
    size_t from;
    size_t to;
    long long weight;
    

    bool isGreater(const Edge &other) {return weight > other.weight;}

    bool isLess(const Edge &other){ return weight <other.weight;}

    bool isEqual(const Edge &other){return weight == other.weight;}
};