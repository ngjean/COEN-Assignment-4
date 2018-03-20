#ifndef VERTEX_H
#define VERTEX_H
#include"Edge.h"

class Vertex
{
    public:
        Vertex();
        virtual ~Vertex();
        Vertex(const Vertex& other);

    private:
        friend Edge *head, *tail;

};

#endif // VERTEX_H
