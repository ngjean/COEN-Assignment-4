/*
Programmer:Jean Carlos Ng
*/
#include "Edge.h"

Edge::Edge()
{
    start = 0;
    dest = 0;
    weight = 0;
}

Edge::Edge(int istart,int idest,int iweight)
{
    start = istart;
    dest = idest;
    weight = iweight;
}


Edge::~Edge()
{
    //dtor
}

Edge::Edge(const Edge& other)
{
    weight = other.weight;
    start = other.start;
    dest = other.dest;
}

void Edge::print()
{
    cout<<"This edge is connecting form Vertex "<<start<<" to "<<dest<<endl;
    cout<<"The weight of this edge is "<<weight<<endl;
}
