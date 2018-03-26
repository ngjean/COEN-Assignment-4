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
        void setValue(int);
        int getId()const;
        int getIconnect()const;
        void changeIconnet(int);
        int getIarrive()const;
        void changeIarrive(int);

    private:
        int id, value, iconnect, iarrive;
        Vertex *next;
};
#endif // VERTEX_H
