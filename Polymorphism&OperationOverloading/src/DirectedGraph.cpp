/*
Programmer:Jean Carlos Ng
*/
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{

}

DirectedGraph::~DirectedGraph()
{
    //dtor
}

bool DirectedGraph::addVertex(Vertex& newNode)
{
	node.push_back(newNode);
    return true;

}

bool DirectedGraph::removeVertex(Vertex& v)
{
    int iid;
    iid = v.getId();
    bool flag = false;
    for(int inum = 0; inum <= node.size(); inum++)
    {
        if(node[inum].getId() == iid)
        {
            node.erase(node.begin()+ (inum-1));

            for(int ivalue = 0 ; ivalue <= line.size(); ivalue++)
            {
                if(node[inum].getId() == line[ivalue].start || node[inum].getId() == line[ivalue].dest)
                {
                    line.erase(line.begin() + (ivalue-1));

                }
            }

            flag = true;
        }
    }

    return flag;
}

bool DirectedGraph::addEdge(Edge& newLine)
{
    for(int inum =0; inum <= node.size(); inum++)
    {
        if(node[inum].getId() == newLine.start)
        {
            node[inum].setConnection(newLine);
        }

        if(node[inum].getId() == newLine.dest)			// I added the same function to also add the edge in the dest's Vertex Connection list
        {
            node[inum].setConnection(newLine);
        }
    }

    line.push_back(newLine);
    return true;
}

bool DirectedGraph::removeEdge(Edge &e)
{
	bool flag = false;

    for(int ivalue =0 ; ivalue <= line.size() ; ivalue++)
    {
        if(line[ivalue].start == e.start)
        {
            if(line[ivalue].dest == e.dest)
            {
                line.erase(line.begin() + (ivalue-1));

                flag = true;
            }
        }
    }





    return flag;
}

bool DirectedGraph::searchVertex(const Vertex& v)
{
    int iid;
    iid = v.getId();
    for(int inum = 0; inum <= node.size(); inum++)
    {
        if(node[inum].getId() == iid)
        {
            return true;
        }
    }
}

bool DirectedGraph::searchEdge(const Edge& e)
{
    int istart, idest;
    istart = e.start;
    idest = e.dest;
    for(int ivalue = 0; ivalue <= line.size(); ivalue++)
    {
        if(line[ivalue].start == istart)
        {
            if(line[ivalue].dest == idest)
            {
                return true;
            }
        }
    }
    return false;
}

void DirectedGraph::display(Vertex& v)const
{

}

void DirectedGraph::display(Edge& e)const
{

}

void DirectedGraph::display()const
{

}

string DirectedGraph::toString()const
{

}

bool DirectedGraph::clean()
{

}
