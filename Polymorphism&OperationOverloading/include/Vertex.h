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
        Vertex(const Vertex& other);
        int getValue()const;
        int getId()const;
        int getIconnect()const;
        int getTotalArrivals();
        void changeIconnet(int);
        void changeArrivals(int);
        void setValue(int);
        bool isVisited();
        void markVisited();

    private:
        int id, value, iconnect, arrivals;
        bool visited;
};
#endif // VERTEX_H
