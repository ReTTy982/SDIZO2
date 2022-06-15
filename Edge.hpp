#pragma once


struct Edge{


    unsigned int from;
    unsigned int to;
    long long weight;
    

    bool isGreater(const Edge &other) {return weight > other.weight;}

    bool isLess(const Edge &other){ return weight <other.weight;}

    bool isEqual(const Edge &other){return weight == other.weight;}
};