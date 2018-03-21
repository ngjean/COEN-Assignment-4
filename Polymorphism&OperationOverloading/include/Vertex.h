#ifndef VERTEX_H
#define VERTEX_H

#include"Edge.h"

class Vertex
{
    public:
        Vertex();
        vertex(int,int);
        virtual ~Vertex();
        Vertex(const Vertex& other);
        int getvalue();
        int getId();
        void setValue(int);
        void setNext(Vertex*);

    private:
      Vertex *next;
      int id, value;
};
#endif // VERTEX_H
