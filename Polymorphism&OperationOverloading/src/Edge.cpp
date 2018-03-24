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

Edge::Edge(int s, int d, int w)
{
	start = s;
	dest = d;
	weight = w;
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
