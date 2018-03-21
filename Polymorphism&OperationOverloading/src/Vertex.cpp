/*
Programmer:Jean Carlos Ng
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;
    id = 0;
    next = 0; //next -> null
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;
   value = ivalue;
}

Vertex::~Vertex()
{
    //dtor
}

Vertex::Vertex(const Vertex& other)
{
    //copy ctor
}

Vertex::getId()
{
    return id;
}

Vertex::getValue()
{
    return value;
}

Vertex::setNext(Vertex* Vnext)
{
    next = Vnext;
}

Vertex::setValue(int ivalue)
{
    value = ivalue
}
