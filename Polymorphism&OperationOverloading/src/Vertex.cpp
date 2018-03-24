/*
Programmer:Jean Carlos Ng
*/
#include "Vertex.h"

Vertex::Vertex()
{
    value = 0;
    id = 0;
    iconnect = 0;
    //next = new Vertex();
    //next = NULL;
    visited = false;
}

Vertex::Vertex(int iid,int ivalue)
{
   id = iid;
   value = ivalue;
   iconnect = 0;
   //next = new Vertex();
   //next = ptr;
   visited = false;
}

Vertex::~Vertex()
{
    //delete vertex
}

Vertex::Vertex(const Vertex& other)
{
    value = other.getValue();
    id = other.getId();
    //next = other.next;
    visited = other.visited;
    iconnect = other.iconnect;
}

int Vertex::getIconnect()const
{
    return iconnect;
}

/*void Vertex::setIconnet(int inum)
{
}*/

void Vertex::setConnection(const Edge& newConnection)
{
    // Edge next = newConnection;				I don't think this is necessary
    connections.push_back(newConnection);
    iconnect++;
}

void Vertex::removeConnection(const Edge& remo){

	for (int j ; j <= connections.size() ; j++ ){

		if (connections[j].dest == remo.dest || connections[j].start == remo.start ){

			connections.erase(connections.begin() - (j-1));
		}
	}

}


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

void Vertex::setId(int iid){

	id = iid;
}

void Vertex::setNext(Vertex v){

	next = &v;
}
