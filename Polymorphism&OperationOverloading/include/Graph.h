#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        //adds one vertex; returns bool if added successfully.
        virtual bool addVertex(Vertex& )=0;
        //Bonus question: adds in a set of vertices; returns bool if added
         //successfully
        //virtual bool addVertices(Vertex* vArray) = 0;
        //removes a vertex; the edges that have connection with this vertex need to
         //be removed;
        virtual bool removeVertex(Vertex& ) = 0;
        //adds an edge; returns true if the edge is added successfully.
        virtual bool addEdge(Edge& ) = 0;
        //Bonus question: removes a set of edges; as a result, some nodes may remain
         //as orphan.
        //virtual bool addEdges(Edge* eArray) = 0;
        // remove the edge
        virtual bool removeEdge(Edge& ) = 0;
        // returns bool if a vertex exists in a graph.
        virtual bool searchVertex(const Vertex& ) = 0;
        // returns bool if an Edge exists in a graph.
        virtual bool searchEdge(const Edge& ) = 0;
        // displays the path that contains the vertex.
        virtual void display(Vertex& ) const = 0;
        // displays the path that contains the edge.
        virtual void display(Edge& ) const = 0;
        // displays the whole graph with your own defined format
        virtual void display() = 0;
         // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
         // is separated by ';'
        virtual string toString () = 0;
        //remove all the vertices an
};

#endif // GRAPH_H
