/*
Programmer:Jean Carlos Ng Lee
ID: 40026914
Programmer: Gabriel Giordano
ID: 40065184
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;  // initialize value
    id = 0;  // initialize value
    iconnect = 0;  // initialize value
    iarrive = 0; // initialize value
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;  // initialize value with a given value
   value = ivalue; // initialize value with a given value
   iconnect = 0;// initialize value
   iarrive = 0;// initialize value
}

Vertex::~Vertex()
{
    //deleted vertex
}

Vertex::Vertex(const Vertex& other)
{
    id = other.id;// initialize value with a given value
    value = other.value;// initialize value with a given value
    iconnect = other.iconnect;// initialize value with a given value
    iarrive = other.iarrive;// initialize value with a given value
}

int Vertex::getIconnect()const
{
    return iconnect; // return iconnect
}

void Vertex::changeIconnet(int inum)
{
    iconnect = iconnect + inum; // it increase iconnect by inum
}

void Vertex::changeIarrive(int inum)
{
    iarrive = iarrive + inum; // it increase iarrive by inum
}

int Vertex::getIarrive()const
{
    return iarrive; //return iarrive
}

int Vertex::getId()const
{
    return id; // return id
}

int Vertex::getValue()const
{
    return value; // return value
}

void Vertex::setValue(int ivalue)
{
    value = ivalue; // set value to a given int name ivalue
}
