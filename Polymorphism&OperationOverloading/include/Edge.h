#ifndef EDGE_H
#define EDGE_H


class Edge
{
    public:
        Edge();
        virtual ~Edge();
        Edge(const Edge& other);

    protected:

    private:
        int weight
        node *next;
};

#endif // EDGE_H
