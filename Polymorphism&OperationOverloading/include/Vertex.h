#ifndef VERTEX_H
#define VERTEX_H
#include<iostream>
using namespace std;
class Vertex
{
    public:
        Vertex(); // constructor
        Vertex(int,int); // constructor with argument
        virtual ~Vertex(); // destructor
        Vertex(const Vertex& other); // copy constructor
        int getValue()const; // return value
        void setValue(int); // set value
        int getId()const; //return id
        int getIconnect()const;//return iconnect
        void changeIconnet(int);//set iconnect
        int getIarrive()const;//return iarrive
        void changeIarrive(int); // set iarrive

    private:
        int id, value, iconnect, iarrive;// declare variable
};
#endif // VERTEX_H
