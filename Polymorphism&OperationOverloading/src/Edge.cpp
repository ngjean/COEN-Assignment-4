/*
Programmer:Jean Carlos Ng
*/
#include "Edge.h"

Edge::Edge()
{
    //ctor
}

Edge::~Edge()
{
    //dtor
}

Edge::Edge(const Edge& other)
{
    weight = other.weight;
    next = new Edge();
    *next = *other.next;
}
