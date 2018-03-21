/*
Programmer:Jean Carlos Ng
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;
    id = 0;
//    next = 0; //next -> null
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;
   value = ivalue;
//   inext = 0;
}

Vertex::~Vertex()
{
    //deleted vectex
}

Vertex::Vertex(const Vertex& other)
{

}

int Vertex::getIconnect()
{
    return iconnect;
}

int Vertex::getId()
{
    return id;
}

int Vertex::getValue()
{
    return value;
}

void Vertex::setIconnet(int inum)
{
    iconnect = inum;
}

void Vertex::setConnection(Edge& newConnection)
{
    Edge next = newConnection;
    Connection.push_back(next);
    iconnect++;
}

void Vertex::setValue(int ivalue)
{
    value = ivalue;
}
