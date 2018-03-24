
/*
Programmer:Jean Carlos Ng
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;
    id = 0;
    iconnect = 0;
    arrivals = 0;
    visited = 0;
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;
   value = ivalue;
   iconnect = 0;
   arrivals = 0;
   visited = 0;
}

Vertex::~Vertex()
{
    //deleted vectex
}

Vertex::Vertex(const Vertex& other)
{
    id = other.id;
    value = other.value;
    iconnect = other.iconnect;
    arrivals = other.arrivals;
    visited = other.visited;
}

int Vertex::getIconnect()const
{
    return iconnect;
}

int Vertex::getTotalArrivals(){

	return arrivals;
}

void Vertex::changeIconnet(int inum)
{
    iconnect = iconnect + inum;
}

void Vertex::changeArrivals(int inum)
{
    arrivals = arrivals + inum;
}

/*
void Vertex::setConnection(Edge& newConnection)
{
    Edge next = newConnection;
    Connection.push_back(next);
    iconnect++;
}
*/

int Vertex::getId()const
{
    return id;
}

int Vertex::getValue()const
{
    return value;
}

void Vertex::setValue(int ivalue)
{
    value = ivalue;
}

void Vertex::markVisited(){

	visited = true;
}

bool Vertex::isVisited(){

	return visited;
}
