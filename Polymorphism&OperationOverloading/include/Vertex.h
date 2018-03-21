#ifndef VERTEX_H
#define VERTEX_H
#include<iostream>
#include <vector>
#include "Edge.h"
using namespace std;
class Vertex
{
    public:
        Vertex();
        Vertex(int,int);
        virtual ~Vertex();
        Vertex(const Vertex& other);
        int getValue();
        int getId();
        int getIconnect();
        void setIconnet(int);
        void setValue(int);
        void setConnection(Edge& );

    private:
        vector<Edge> Connection;
        int id, value,iconnect;
};
#endif // VERTEX_H
