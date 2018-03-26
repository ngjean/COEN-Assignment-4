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
    for(unsigned int inum = 0; inum < node.size(); inum++)
    {
        if(node[inum].getId() == newNode.getId())
        {
            return false;
        }
    }
    node.push_back(newNode);
    return true;
}

bool DirectedGraph::removeVertex(Vertex& v)
{
    int iid;
    iid = v.getId();
    for(unsigned int inum = 0; inum < node.size() ; inum++)
    {
        if(node[inum].getId() == iid)
        {
            node.erase(node.begin()+ inum);
            for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++)
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
    for(unsigned int inum =0; inum < node.size(); inum++)
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
    for(unsigned int ivalue = 0 ; ivalue < line.size() ; ivalue++)
    {
        if(line[ivalue].start == e.start)
        {
            if(line[ivalue].dest == e.dest)
            {
                line.erase(line.begin() + ivalue);

                for(unsigned int inum =0; inum< node.size(); inum++)
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
    for(unsigned int inum = 0; inum < node.size(); inum++)
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
    for(unsigned int ivalue = 0; ivalue < line.size(); ivalue++)
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

    for(unsigned int inum = 0 ; inum < node.size() ; inum++)
    {
        if(node[inum].getId() == iid)
        {
            if(node[inum].getIarrive() != 0)
            {
                cout<<"From 'X' Vertex to a given Vertex"<<endl;
                for(unsigned int ivalue = 0 ;ivalue < line.size(); ivalue++)
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
                for(unsigned int ivalue = 0 ;ivalue < line.size(); ivalue++)
                {
                    if(line[ivalue].start == iid)
                    {
                         cout<<"|"<<line[ivalue].start<<"|-->|"<<line[ivalue].dest<<"|"<<endl;
                    }
                }
            }
        }
    }
}

void DirectedGraph::display(Edge& e)const
{
    for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++)
    {
        if(line[ivalue].start == e.start && line[ivalue].dest == e.dest)
        {
             cout<<"|"<<e.start<<"|-->|"<<e.dest<<"|"<<endl;
             return;
        }
    }
    cout<<"The given Edge either doesnt exist or counld not be found"<<endl;
}

void DirectedGraph::display()// displaying graph as of connection betwen two vertex + the vertex that are not connec
{
    VertexCheck();
    cout<<endl;
    cout<<"VERTEX WITH NO CONNECTION: "<<endl;
    for(unsigned int inum = 0; inum <vilone.size(); inum++)
    {
        cout<<"|"<<vilone[inum].getId()<<"|"<<endl;
    }
    cout<<endl;
    for(unsigned int inum = 0; inum < vihead.size(); inum++) // for all head
    {
       for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++) // check all edge
       {
           if(vihead[inum].getId() == line[ivalue].start) // if edge start from this vertex head
           {
                int istore;
                string store;
                istore = line[ivalue].start;
                store = "|"+to_string(istore);
                istore = line[ivalue].dest;
                store = store+"|-|"+to_string(istore)+"|";
                vslist.push_back(store);
                CheckConnect(line[ivalue].dest, store);
           }
       }
    }
    cout<<"GRAPH ALL POSSIBLE PATH WILL ALL POSSIBLE STOP"<<endl;
   for(unsigned int inum = 0 ; inum < vslist.size(); inum++)
   {
       cout<<vslist[inum]<<endl;
   }
}

string DirectedGraph::toString()
{
    string show;
    VertexCheck();
    cout<<endl;
    for(unsigned int inum = 0; inum < vihead.size(); inum++) // for all head
    {
       for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++) // check all edge
       {
           if(vihead[inum].getId() == line[ivalue].start) // if edge start from this vertex head
           {
                int istore;
                string store;
                istore = line[ivalue].start;
                store = "|"+to_string(istore);
                istore = line[ivalue].dest;
                store = store+"|-|"+to_string(istore)+"|";
                vslist.push_back(store);
                CheckConnect(line[ivalue].dest, store);
           }
       }
    }

    for(unsigned int ivalue = 0; ivalue < vslist.size(); ivalue++)
    {
        show = show + vslist[ivalue] + "; ";
    }

   for(unsigned int ivalue = 0; ivalue < vilone.size(); ivalue++)
   {
       show = show + "|" + to_string(vilone[ivalue].getId()) + "|; ";
   }

    return show;
}

void DirectedGraph::CheckConnect(int inum, string store)
{
    for(unsigned int icount = 0 ; icount < node.size(); icount++)
    {
        if(inum == node[icount].getId() )
        {
            if(node[icount].getIconnect() !=0 )
            {
                for(unsigned int ichain = 0 ; ichain < line.size(); ichain++)
                {
                    if(node[icount].getId() == line[ichain].start)
                    {
                        int istore2;
                        string store2;
                        istore2 = line[ichain].dest;
                        store2 = store;
                        store2 = store+"-|"+to_string(istore2)+"|";
                        vslist.push_back(store2);

                        for(unsigned int inum = 0 ; inum < node.size(); inum++)
                        {
                            if(line[ichain].dest == node[inum].getId())
                            {
                                if(node[inum].getIconnect() != 0)
                                {
                                    CheckConnect(line[ichain].dest,store2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void DirectedGraph::VertexCheck()
{
    vihead.clear();
    vihead.clear();
    vilone.clear();
    vslist.clear();

    for(unsigned int inum =0 ; inum < node.size();inum++)
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
}

bool DirectedGraph::clean()
{
    line.clear();
    node.clear();
    return true;
}


//---------------------------OVERLOADING-----------------------------------------------------------------------------------
bool DirectedGraph::operator ==(const DirectedGraph &other) const // I THINK IT WOKRS
{

	bool flag = true;
	unsigned int inodecheck(0);
	unsigned int ilinecheck(0);
	// Vectors of Vertices of this and other DirectedGraph are compared
	if (node.size() != other.node.size())
	{
		flag = false;
	}
	else
    {
        for(unsigned int inum = 0; inum < other.node.size(); inum++)
        {
            for (unsigned int j = 0; j < node.size(); j++)
            {
                if(node[j].getId() == other.node[inum].getId() || node[j].getValue() == other.node[inum].getValue())
                {
                    inodecheck++;
                }
            }
        }
        if(inodecheck != node.size())
        {
            flag = false;
        }
    }

	// Vectors of Edges of this and other DirectedGraph are compared
	if (line.size() != other.line.size()){

			flag = false;
	}
	else
    {
        for(unsigned int inum = 0; inum < other.line.size(); inum++)
        {
            for (unsigned int j = 0; j < line.size(); j++)
            {
                if(line[j].start == other.line[inum].start || line[j].dest == other.line[inum].dest  || line[j].weight == other.line[inum].weight)
                {
                    ilinecheck++;
                }
            }
            if(ilinecheck != line.size())
            {
                flag = false;
            }
        }
	}
	return flag;
}

const DirectedGraph& DirectedGraph::operator =(const DirectedGraph& other){ // WORKS I THINK

	if(&other != this)
    {
			node.clear();
			line.clear();
			for (unsigned int i = 0; i < other.node.size();i++)
            {
				node.push_back(other.node[i]);
			}

			for(unsigned int j = 0; j < other.line.size(); j++)
			{

                line.push_back(other.line[j]);
			}
	}
	return *this;
}

DirectedGraph DirectedGraph::operator++() //NOT SURE IF IT WOKR
{
    for(unsigned int inum = 0; inum < line.size(); inum++)
    {
        line[inum].weight = line[inum].weight + 1;
    }
    return *this;
}

DirectedGraph DirectedGraph::operator+(DirectedGraph& other)
{
    //create a list, add the left hand and righ hand lists to it then return it
    DirectedGraph newGraph;

    newGraph = *this;

    if(&other != this)
    {
        for(unsigned int inum = 0; inum < other.node.size(); inum++)
        {
            newGraph.addVertex(other.node[inum]);
        }
        for(unsigned int inum = 0; inum < other.line.size(); inum++)
        {
            newGraph.addEdge(other.line[inum]);
        }
    }

    return newGraph;
}

bool  DirectedGraph::operator>(const DirectedGraph &other)const // G1 = current graph; G2 = given Graph NOT SURE IF IT WORKS
{
    int inum1(0),inum2(0);

    for(unsigned int inum = 0 ; inum < line.size(); inum++) // current Graph
    {
        inum1 = inum1 + line[inum].weight;
    }

    for(unsigned int inum = 0 ; inum < line.size(); inum++) // Given Graph
    {
        inum1 = inum1 + other.line[inum].weight;
    }

    return (inum1>inum2);
}

ostream& operator<<(ostream& output, DirectedGraph& DG ) // NOT WORKING YET
{
    output << DG.toString();
    return output;  // enables cout << d1 << d2 << d3;
}



