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
    

    bool operator<(const Edge &other) {return weight < other.weight;}

    bool operator>(const Edge &other){ return weight >other.weight;}

    bool operator==(const Edge &other){return weight == other.weight;}
};