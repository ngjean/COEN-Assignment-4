#ifndef EDGE_H
#define EDGE_H
#include<iostream>
//#include"Vertex.h"
using namespace std;

class Edge
{
    public:
        Edge();
        Edge(int,int,int);
        Edge(const Edge& other);
        virtual ~Edge();

        int weight;
        int start, dest;
};

#endif // EDGE_H
