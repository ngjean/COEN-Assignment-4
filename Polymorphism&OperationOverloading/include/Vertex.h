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
        void changeIconnet(int);
        void setValue(int);

    private:
        int id, value, iconnect;
};
#endif // VERTEX_H
