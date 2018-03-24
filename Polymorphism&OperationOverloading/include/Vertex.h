#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
#include <vector>
#include "Edge.h"
using namespace std;

class Vertex
{
    public:
        Vertex();
        Vertex(int,int);
        virtual ~Vertex();
        Vertex(const Vertex&);

        void setValue(int);
        int getValue()const;
        void setId(int);
        int getId()const;

        //void setConnection(const Edge&);
        //void removeConnection(const Edge&);            // For what I was trying to do with the Vector of Connections
        int getIconnect()const;

        void setNext(Vertex);		// To set the Vertex to which this one is going to point to.
        							// (I don't know how to properly pass the object Vertex in this funct.)

        //void setConnection(Edge& );

    private:
        //vector<Edge> connections;
        int id, value, iconnect;
        //Vertex* next;     I don't know where are we going to use it now
        bool visited;
};
