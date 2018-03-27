/*
Programmer:Jean Carlos Ng Lee
ID: 40026914
Programmer: Gabriel Giordano
ID: 40065284
*/
#ifndef EDGE_H
#define EDGE_H
#include<iostream>
using namespace std;

class Edge
{
    public:
        Edge();
        Edge(int,int,int);
        Edge(const Edge& other);
        virtual ~Edge();

        void print();

        int weight;
        int start, dest;
};

#endif // EDGE_H
