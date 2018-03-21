#ifndef EDGE_H
#define EDGE_H
#include<iostream>
using namespace std;

class Edge
{
    public:
        Edge();
        Edge(const Edge& other);
        virtual ~Edge();

        int weight;
        Edge* next;
};

#endif // EDGE_H
