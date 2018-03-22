/*
Programmer:Jean Carlos Ng
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;
    id = 0;
    //iconnect = 0;
    next = new Vertex();
    next = NULL;
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;
   value = ivalue;
  // iconnect = 0;
   next = new Vertex();
   next = NULL;
}

Vertex::~Vertex()
{
    //deleted vectex
}

Vertex::Vertex(const Vertex& other)
{
    value = other.getValue();
    id = other.getId();
    next = other.next;
}

/*int Vertex::getIconnect()const
{
    return iconnect;
}
void Vertex::setIconnet(int inum)
{
}
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

void Vertex::setNext(Vertex v){

	next = v;
}
