/*
Programmer:Jean Carlos Ng
*/
#include "Edge.h"

Edge::Edge()
{
	weight = 0;
	start = 0;
	dest = 0;
}



Edge::Edge(int eW, int eStart, int eDest)
{
	weight = eW;
	start = eStart;
	dest = eDest;
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
