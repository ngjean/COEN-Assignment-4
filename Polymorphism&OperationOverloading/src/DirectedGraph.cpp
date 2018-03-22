/*
Programmer:Jean Carlos Ng
*/
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
    inode = 0;
    iline = 0;
}

DirectedGraph::~DirectedGraph()
{
    //dtor
}

bool DirectedGraph::addVertex(Vertex& newNode)
{
    node.push_back(newNode);
    inode++;
    return true;
}

bool DirectedGraph::removeVertex(Vertex& v)
{
    int iid;
    iid = v.getId();
    for(int inum = 0; inum <= inode; inum++)
    {
        if(node[inum].getId() == iid)
        {
            node.erase(node.begin()+ (inum-1));
            inode--;

            for(int ivalue = 0 ; ivalue <= iline; ivalue++)
            {
                if(iid == line[ivalue].start)
                {
                    line.erase(line.begin() + (ivalue-1));
                    iline--;
                }
            }
            node.shrink_to_fit();
            line.shrink_to_fit();
            return true;
        }
    }
}

bool DirectedGraph::addEdge(Edge& newLine)
{
    for(int inum =0; inum<= inode; inum++)
    {
        if(node[inum].getId() == newLine.start)
        {
            node[inum].changeIconnet(1);
        }
    }

    line.push_back(newLine);
    iline++;
    return true;
}

bool DirectedGraph::removeEdge(Edge & e)
{
    for(int ivalue =0 ; ivalue <= iline ; ivalue++)
    {
        if(line[ivalue].start == e.start)
        {
            if(line[ivalue].dest == e.dest)
            {
                line.erase(line.begin() + (ivalue-1));
                iline--;

                for(int inum =0; inum<= inode; inum++)
                {
                    if(node[inum].getId() == e.start)
                    {
                        node[inum].changeIconnet(-1);
                    }
                }

                return true;
            }
        }
    }
}

bool DirectedGraph::searchVertex(const Vertex& v)
{
    int iid;
    iid = v.getId();
    for(int inum = 0; inum <= inode; inum++)
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
    for(int ivalue = 0; ivalue <= iline; ivalue++)
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
    for(int ivalue = 0 ; ivalue < iline; ivalue++)
    {
        if(line[ivalue].start == iid)
        {
            cout<<"|"<<line[ivalue].start<<"| --> |"<<line[ivalue].dest<<"|"<<endl;
        }
    }
}

void DirectedGraph::display(Edge& e)const
{
    cout<<"|"<<e.start<<"|-->|"<<e.dest<<"|"<<endl;
}

void DirectedGraph::display()const
{
    vector<int> vihead;
    vector<int> vitail;
    vector<string> vslist;
    int ihead, itail, ilone;

//-----------------------------Check for tails and head---------------------------------------------------------------------------
    for(int inum = 0; inum < iline; inum++)
    {
        ihead = 0;
        itail = 0;
        for(int ivalue = 0; ivalue < iline ; ivalue++)
        {
            if(line[inum].start == line[ivalue].dest)
            {
                ihead++;
            }
            if(line[inum].dest == line[ivalue].start)
            {
                itail++;
            }
        }
        if(ihead == 0)
        {
            vihead.push_back(inum);
        }
        if(itail == 0)
        {
            vitail.push_back(inum);
        }
    }
//----------------------------------------------------------------------------------------------------------------------------------
// ------------------------- add path to display-----------------------------------------------------------------------------------


//--------------------------------------------------- add lone vertex to display---------------------------------------------------
    for(int inum = 0; inum < inode; inum++)
    {
        ilone = 0;
        for(int ivalue = 0 ; ivalue < iline; ivalue++)
        {
            if(node[inum].getId() == line[ivalue].start || node[inum].getId() == line[ivalue].dest)
            {
                ilone++;
            }
        }
        if(ilone == 0)
        {
            int iid;
            iid = node[inum].getId();
            string list;
            list = to_string(iid);
            vslist.push_back(list);
        }
    }
//----meaning that if there isnt any edge that has a start or dest with the vertex 'X' Id woudl imply that this vertex is a lone vertex-----
}

string DirectedGraph::toString()const
{

}

bool DirectedGraph::clean()
{

}
