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
    for(int inum = 0; inum < node.size() ; inum++)
    {
        if(node[inum].getId() == iid)
        {
            node.erase(node.begin()+ inum);
            for(int ivalue = 0 ; ivalue < line.size(); ivalue++)
            {
                if(iid == line[ivalue].start || iid == line[ivalue].dest)
                {
                    line.erase(line.begin() + ivalue);
                }
            }
            return true;
        }
    }
    return false;
}

bool DirectedGraph::addEdge(Edge& newLine)
{
    int istart(-1), idest(-1);
    for(int inum =0; inum < node.size(); inum++)
    {
        if(node[inum].getId() == newLine.start)
        {
            istart = inum;
        }
        if(node[inum].getId() == newLine.dest)
        {
             idest = inum;
        }
    }
    if(istart == -1 || idest == -1)
    {
        return false;
    }
    else
    {
        node[istart].changeIconnet(1);
        node[idest].changeIarrive(1);
        line.push_back(newLine);
        return true;
    }
}

bool DirectedGraph::removeEdge(Edge & e)
{
    for(int ivalue = 0 ; ivalue < line.size() ; ivalue++)
    {
        if(line[ivalue].start == e.start)
        {
            if(line[ivalue].dest == e.dest)
            {
                line.erase(line.begin() + ivalue);

                for(int inum =0; inum< node.size(); inum++)
                {
                    if(node[inum].getId() == e.start)
                    {
                        node[inum].changeIconnet(-1);
                    }
                    if(node[inum].getId() == e.dest)
                    {
                         node[inum].changeIarrive(-1);
                    }
                }
                return true;
            }
        }
    }
    return false;
}

bool DirectedGraph::searchVertex(const Vertex& v)
{
    int iid;
    iid = v.getId();
    for(int inum = 0; inum < node.size(); inum++)
    {
        if(node[inum].getId() == iid)
        {
            return true;
        }
    }
    return false;
}

bool DirectedGraph::searchEdge(const Edge& e)
{
    int istart, idest;
    istart = e.start;
    idest = e.dest;
    for(int ivalue = 0; ivalue < line.size(); ivalue++)
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
    int iid;
    iid = v.getId();

    for(int inum = 0 ; inum < node.size() ; inum++)
    {
        if(node[inum].getId() == iid)
        {
            if(node[inum].getIarrive() != 0)
            {
                cout<<"From 'X' Vertex to a given Vertex"<<endl;
                for(int ivalue = 0 ;ivalue < line.size(); ivalue++)
                {
                    if(line[ivalue].dest == iid)
                    {
                        cout<<"|"<<line[ivalue].start<<"|-->|"<<line[ivalue].dest<<"|"<<endl;
                    }
                }
            }
            cout<<endl;
            if(node[inum].getIconnect() != 0 )
            {
                cout<<"From a given Vertex to 'X' Vertex"<<endl;
                for(int ivalue = 0 ;ivalue < line.size(); ivalue++)
                {
                    if(line[ivalue].start == iid)
                    {
                         cout<<"|"<<line[ivalue].start<<"-->|"<<line[ivalue].dest<<"|"<<endl;
                    }
                }
            }
        }
    }
}

void DirectedGraph::display(Edge& e)const
{
    for(int ivalue = 0 ; ivalue < line.size(); ivalue++)
    {
        if(line[ivalue].start == e.start && line[ivalue].dest == e.dest)
        {
             cout<<"|"<<e.start<<"|-->|"<<e.dest<<"|"<<endl;
             return;
        }
    }
    cout<<"The given Edge either doesnt exist or counld not be found"<<endl;
}

void DirectedGraph::display()const
{

}

string DirectedGraph::toString()const
{
    vector<Vertex> vihead;
    vector<Vertex> vitail;
    vector<Vertex> vilone;
    vector<string> vslist;

    //----head and tail and lone vertex-----------------------------------
    for(int inum =0 ; inum < node.size();inum++)
    {
        if(node[inum].getIarrive() == 0 && node[inum].getIconnect() != 0 )
        {
            vihead.push_back(node[inum]);
        }

        if(node[inum].getIarrive() != 0 && node[inum].getIconnect() == 0 )
        {
            vitail.push_back(node[inum]);
        }

        if(node[inum].getIarrive() == 0 && node[inum].getIconnect() == 0 )
        {
            vilone.push_back(node[inum]);
        }
    }
    //---------------------------------------------------------------------

    for(int inum = 0 ; inum < vihead.size(); inum++)//for all the head
    {
        for(int ivalue = 0; ivalue < line.size(); ivalue++)
        {
            if(vihead[inum].getId() == line[ivalue].start)
            {
                int istore;
                string store;
                istore = line[ivalue].start;
                store = to_string(istore);
                istore = line[ivalue].dest;
                store = store+"-"+to_string(istore);

                vslist.push_back(store);
            }
        }
    }

}


bool DirectedGraph::clean()
{

}
