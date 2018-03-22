#ifndef VERTEX_H
#define VERTEX_H
#include<iostream>
using namespace std;

class Vertex
{
    public:
        Vertex();
        Vertex(int,int);
        virtual ~Vertex();
        Vertex(const Vertex&);
        int getValue()const;
        int getId()const;
       // int getIconnect()const;
       // void setIconnet(int);
        void setValue(int);

        void setNext(const Vertex&);		// To set the Vertex to which this one is going to point to.
        							// (I don't know how to properly pass the object Vertex in this funct.)

        //void setConnection(Edge& );

    private:
        //vector<Edge> Connection;
        int id, value;//,iconnect;
        Vertex* next;
};
#endif // VERTEX_H
