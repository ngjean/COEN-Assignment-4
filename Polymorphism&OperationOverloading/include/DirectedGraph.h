#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include<string>
#include"Graph.h"
#include"Vertex.h"
#include"Edge.h"
#include "AdjList.h"
#include<iostream>
#include<vector>
using namespace std;

class DirectedGraph : public Graph
{
    public:
        DirectedGraph();
        virtual ~DirectedGraph();

        //adds one vertex; returns bool if added successfully.
        virtual bool addVertex(Vertex& );

        //Bonus question: adds in a set of vertices; returns bool if added
        //successfully
        //virtual bool addVertices(Vertex* vArray) = 0;
        //removes a vertex; the edges that have connection with this vertex need to
        //be removed;
        virtual bool removeVertex(Vertex&);

        //adds an edge; returns true if the edge is added successfully.
        virtual bool addEdge(Edge& );

        //Bonus question: removes a set of edges; as a result, some nodes may remain
        //as orphan.
        //virtual bool addEdges(Edge* eArray) = 0;
        // remove the edge
        virtual bool removeEdge(Edge& );

        // returns bool if a vertex exists in a graph.
        virtual bool searchVertex(const Vertex& );

        // returns bool if an Edge exists in a graph.
        virtual bool searchEdge(const Edge& );

        // displays the path that contains the vertex.
        virtual void display(Vertex& ) const;

        // displays the path that contains the edge.
        virtual void display(Edge& ) const;

        // displays the whole graph with your own defined format
        virtual void display() const;

        // converts the whole graph to a string such as 1-2-4-5; 1-3-5; each path
        // is separated by ';'
        virtual string toString () const;

        //remove all the vertices and edges;
        virtual bool clean();

        /*struct node{

        	int value;
        	struct node* next;
        };*/

        // THIS IS THE ADJACENCY LIST

        /*struct AdjList{

        	Vertex* heads;
        };*/

        vector <AdjList> VectorVertices; //This would actually substitute the Vector "node" that is below

    private:
        vector<Edge> line;
        vector<Vertex> node;
        int iline, inode,V;
};

#endif // DIRECTEDGRAPH_H
