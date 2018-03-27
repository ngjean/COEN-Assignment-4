/*
Programmer:Jean Carlos Ng
*/
#include "Edge.h"

Edge::Edge()
{
    start = 0; // initialize value
    dest = 0;// initialize value
    weight = 0;// initialize value
}

Edge::Edge(int istart,int idest,int iweight)
{
    start = istart; // store given value
    dest = idest;// store given value
    weight = iweight;// store given value
}


Edge::~Edge()
{
    //dtor
}

Edge::Edge(const Edge& other)
{
    weight = other.weight; //pass value of the given edge to this object
    start = other.start;//pass value of the given edge to this object
    dest = other.dest;//pass value of the given edge to this object
}

void Edge::print()
{
    cout<<"This edge is connecting form Vertex "<<start<<" to "<<dest<<endl;//display text
    cout<<"The weight of this edge is "<<weight<<endl;//display text
}
