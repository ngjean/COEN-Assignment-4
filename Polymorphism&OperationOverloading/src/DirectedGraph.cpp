/*
Programmer:Jean Carlos Ng Lee
ID: 40026914
Programmer: Gabriel Giordano
ID: 40065184
*/
#include "DirectedGraph.h"

DirectedGraph::DirectedGraph()
{
}

DirectedGraph::~DirectedGraph()
{
    //dtor
}

bool DirectedGraph::addVertex(Vertex& newNode)		//Adds a new Vertex to the Vector "node"
{
    for(unsigned int inum = 0; inum < node.size(); inum++)
    {
        if(node[inum].getId() == newNode.getId())
        {
            return false;							//If the Vertex was already in the vector, returns false
        }
    }
    node.push_back(newNode);
    return true;									//Returns True when added successfully
}

bool DirectedGraph::removeVertex(Vertex& v)
{
    int iid;
    iid = v.getId();
    for(unsigned int inum = 0; inum < node.size() ; inum++)
    {
        if(node[inum].getId() == iid)					//Searchs for the Vertex by matching id's
        {
            node.erase(node.begin()+ inum);				//if Vertex found, element[inum] is erased from the vector
            for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++)
            {
                if(iid == line[ivalue].start || iid == line[ivalue].dest)			//also searchs the Edges that were adjacent to that Vertex
                {
                    line.erase(line.begin() + ivalue);						//if found, erases Edges adjacents
                }
            }
            return true;
        }
    }
    return false;
}

bool DirectedGraph::addEdge(Edge& newLine)				//adds an Edge to the Vector "line"
{
    int istart(-1), idest(-1);							//a proof value is assigned to istart and idest in case the Edge cannot be added
    for(unsigned int ivalue =0; ivalue < line.size(); ivalue++)
    {
        if(line[ivalue].start == newLine.start && line[ivalue].dest == newLine.dest)		// if both start and destination of the Edge match with one in the vector, return false
        {
            return false;
        }
    }
    for(unsigned int inum =0; inum < node.size(); inum++)	//goes trough the vector of Vertex searching for matches in start or dest point
    {
        if(node[inum].getId() == newLine.start)			//if ID of Vertex matches with Start of Edge, stores the index where found
        {
            istart = inum;
        }
        if(node[inum].getId() == newLine.dest)			//if ID of Vertex matches with Dest of Edge, stores the index where found
        {
             idest = inum;
        }
    }
    if(istart == -1 || idest == -1)			//If start OR dest don't find any match, return false.
    {
        return false;
    }
    else									//if start AND dest found match
    {
        node[istart].changeIconnet(1);			//Adds 1 to the counter of departures	(attribute of Vertex)
        node[idest].changeIarrive(1);			//Adds 1 to the counter of arrivals		(attribute of Vertex)
        line.push_back(newLine);				//Adds the Edge to the vector "line"
        return true;
    }
}

bool DirectedGraph::removeEdge(Edge & e)
{
    for(unsigned int ivalue = 0 ; ivalue < line.size() ; ivalue++)
    {
        if(line[ivalue].start == e.start)				//if start matches
        {
            if(line[ivalue].dest == e.dest)				//if dest matches
            {
                line.erase(line.begin() + ivalue);			//erase the element[ivalue] of the vector line

                for(unsigned int inum =0; inum< node.size(); inum++)
                {
                    if(node[inum].getId() == e.start)		//if a node had that edge as start point
                    {
                        node[inum].changeIconnet(-1);		//reduce the counter in 1
                    }
                    if(node[inum].getId() == e.dest)		//if a node had that edge as dest point
                    {
                         node[inum].changeIarrive(-1);		//reduce the counter in 1
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
    for(unsigned int inum = 0; inum < node.size(); inum++) // for all the vertex in this graph
    {
        if(node[inum].getId() == iid) // if there is a vertex with the sama id of the given vertex
        {
            return true;//return true
        }
    }
    return false;//return false
}

bool DirectedGraph::searchEdge(const Edge& e)
{
    int istart, idest;//declare variable
    istart = e.start;//store value in variable
    idest = e.dest;//store value in variable
    for(unsigned int ivalue = 0; ivalue < line.size(); ivalue++)//for all the edge in this graph
    {
        if(line[ivalue].start == istart) // if the a edge have the same id for start
        {
            if(line[ivalue].dest == idest) // if the edge have teh same id for start and dest
            {
                return true;//return ture
            }
        }
    }
    return false;// retunr false
}

void DirectedGraph::display(Vertex& v)const
{
    int iid;//declare variable
    iid = v.getId();//store variable

    for(unsigned int inum = 0 ; inum < node.size() ; inum++) //for all vertex in this grapp
    {
        if(node[inum].getId() == iid)// check if given vertex is in this graph
        {
            if(node[inum].getIarrive() != 0)//check if this node have vertex connected to him
            {
                cout<<"From 'X' Vertex to a given Vertex"<<endl;//display text
                for(unsigned int ivalue = 0 ;ivalue < line.size(); ivalue++)
                {
                    if(line[ivalue].dest == iid)//check for all the edge with this the id as dest
                    {
                        cout<<"|"<<line[ivalue].start<<"|-->|"<<line[ivalue].dest<<"|"<<endl;// display text plus some values
                    }
                }
            }
            cout<<endl;
            if(node[inum].getIconnect() != 0 )//check if this node have vertex connected to him
            {
                cout<<"From a given Vertex to 'X' Vertex"<<endl;//display text
                for(unsigned int ivalue = 0 ;ivalue < line.size(); ivalue++)//for all the edge in this graph
                {
                    if(line[ivalue].start == iid) // search for all the edge with this id as start
                    {
                         cout<<"|"<<line[ivalue].start<<"|-->|"<<line[ivalue].dest<<"|"<<endl;// display text plus some values
                    }
                }
            }
        }
    }
}

void DirectedGraph::display(Edge& e)const
{
    for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++)// for all the edge
    {
        if(line[ivalue].start == e.start && line[ivalue].dest == e.dest) // if the given edge is in this graph enter
        {
             cout<<"|"<<line[ivalue].start<<"|-->|"<<line[ivalue].dest<<"|"<<endl;  //display text with some value
             return; // return to main
        }
    }
    cout<<"The given Edge either doesnt exist or counld not be found"<<endl; // display text
}

void DirectedGraph::display()// displaying graph as of connection betwen two vertex + the vertex that are not connec
{
    VertexCheck(); // call funtion VertexCheck();
    cout<<endl;//skip a line
    for(unsigned int inum = 0; inum < vihead.size(); inum++) // for all head
    {
       for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++) // check all edge
       {
           if(vihead[inum].getId() == line[ivalue].start) // if edge start from this vertex head
           {
                int istore;//declare variable
                string store;//declare variable
                istore = line[ivalue].start; // store start id in istore
                store = "|"+to_string(istore);// concatinated string and transfrom the id store in istore to a string
                istore = line[ivalue].dest; // store dest id in istore
                store = store+"|-|"+to_string(istore)+"|"; // concatinated string and transfrom the id store in istore to a string
                vslist.push_back(store);//add string to vslist vector
                CheckConnect(line[ivalue].dest, store);//call funtion and pass them the values
           }
       }
    }

    cout<<"GRAPH ALL POSSIBLE PATH WILL ALL POSSIBLE STOP"<<endl;
   for(unsigned int inum = 0 ; inum < vslist.size(); inum++)//for all the element store in vslist
   {
       cout<<vslist[inum]<<endl;//display all the information in vslist
   }
}

string DirectedGraph::toString()
{
    string show;//declaring variable
    VertexCheck(); // call funtion VertexCheck();
    cout<<endl;//skip a line
    for(unsigned int inum = 0; inum < vihead.size(); inum++) // for all head
    {
       for(unsigned int ivalue = 0 ; ivalue < line.size(); ivalue++) // check all edge
       {
           if(vihead[inum].getId() == line[ivalue].start) // if edge start from this vertex head
           {
                int istore;//declare variable
                string store;//declare variable
                istore = line[ivalue].start; // store start id in istore
                store = "|"+to_string(istore);// concatinated string and transfrom the id store in istore to a string
                istore = line[ivalue].dest; // store dest id in istore
                store = store+"|-|"+to_string(istore)+"|"; // concatinated string and transfrom the id store in istore to a string
                vslist.push_back(store);//add string to vslist vector
                CheckConnect(line[ivalue].dest, store);//call funtion and pass them the values
           }
       }
    }

    for(unsigned int ivalue = 0; ivalue < vslist.size(); ivalue++)
    {
        show = show + vslist[ivalue] + "; "; //concatinating all the string in vector vslist
    }

   for(unsigned int ivalue = 0; ivalue < vilone.size(); ivalue++)
   {
       show = show + "|" + to_string(vilone[ivalue].getId()) + "|; "; // convert all the id of the lonenly vertex and concatinating them
   }

    return show;//return show
}

void DirectedGraph::CheckConnect(int inum, string store) // check for possible connection
{
    for(unsigned int icount = 0 ; icount < node.size(); icount++)// for all the vertex that exist right now
    {
        if(inum == node[icount].getId() )// look for the given id name inum
        {
            if(node[icount].getIconnect() !=0 ) // check if that node have connection
            {
                for(unsigned int ichain = 0 ; ichain < line.size(); ichain++) // fo all the edge
                {
                    if(node[icount].getId() == line[ichain].start) // search for any edge that start in the given id
                    {
                        int istore2; // declaration of variable
                        string store2;// declaration of variable
                        istore2 = line[ichain].dest; // store the id of the destination in store2
                        store2 = store; // store given string to store2
                        store2 = store2+"-|"+to_string(istore2)+"|"; // concatinating string
                        vslist.push_back(store2);//add store to vector

                        for(unsigned int inum = 0 ; inum < node.size(); inum++) // for all the vertex in this object
                        {
                            if(line[ichain].dest == node[inum].getId()) // search for the object give a certain id
                            {
                                if(node[inum].getIconnect() != 0) // check if that object have a connection
                                {
                                    CheckConnect(line[ichain].dest,store2); // call funtion again (recursion)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void DirectedGraph::VertexCheck()// to check all the head, tail and lonely vertex
{
    vitail.clear();//eliminate element store
    vihead.clear();//eliminate element store
    vilone.clear();//eliminate element store
    vslist.clear();//eliminate element store

    for(unsigned int inum =0 ; inum < node.size();inum++)
    {
        if(node[inum].getIarrive() == 0 && node[inum].getIconnect() != 0 ) // check for all the head vertex
        {
            vihead.push_back(node[inum]);// add to vector
        }

        if(node[inum].getIarrive() != 0 && node[inum].getIconnect() == 0 )// check for all the tail vertex
        {
            vitail.push_back(node[inum]);// add to vector
        }

        if(node[inum].getIarrive() == 0 && node[inum].getIconnect() == 0 )// check for all the lonely vertex
        {
            vilone.push_back(node[inum]);// add to vector
        }
    }
}

bool DirectedGraph::clean()
{
    line.clear();//eliminate element store
    node.clear();//eliminate element store
    return true; // return true
}


//---------------------------OVERLOADING-----------------------------------------------------------------------------------
bool DirectedGraph::operator ==(const DirectedGraph &other) const // WORKS
{
	unsigned int inodecheck(0);//declaration of variable
	unsigned int ilinecheck(0);//declaration of variable
	// Vectors of Vertices of this and other DirectedGraph are compared
	if (node.size() != other.node.size())// check fi thesize are the same to save time
	{
		return false;//return false
	}
	else
    {
        for(unsigned int inum = 0; inum < other.node.size(); inum++) // for all node of the other class
        {
            for (unsigned int j = 0; j < node.size(); j++) // for all node of this class
            {
                if(node[j].getId() == other.node[inum].getId() && node[j].getValue() == other.node[inum].getValue())// check if this node is in the other object
                {
                    inodecheck++;// add 1 to the current value of inodecheck;
                }
            }
        }
        if(inodecheck != node.size())// if all the node in this object are in the other object
        {
            return false;//return false
        }
    }

	// Vectors of Edges of this and other DirectedGraph are compared
	if (line.size() != other.line.size()) // check if the size are the same to save time
    {

			return false;//return false
	}
	else
    {
        for(unsigned int inum = 0; inum < other.line.size(); inum++)// for all line of other object
        {
            for (unsigned int j = 0; j < line.size(); j++) // for all line of this object
            {
                if(line[j].start == other.line[inum].start && line[j].dest == other.line[inum].dest && line[j].weight == other.line[inum].weight)//check if the edge is identical to the other
                {
                    ilinecheck++;// add 1 to the current value of ilinecheck;
                }
            }
        }
        if(ilinecheck != line.size()) // if all the edge are in other are in this object
        {
            return false;//return false
        }
	}
	return true; // return true
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
DirectedGraph DirectedGraph::operator =(DirectedGraph& other)
{
    node.clear();//eliminated all the element in node
    line.clear();//eliminated all the element in line
    for (unsigned int inum = 0; inum < other.node.size(); inum++)
    {
        addVertex(other.node[inum]);
    }

    for(unsigned int inum = 0; inum < other.line.size(); inum++)
    {
        addEdge(other.line[inum]);
    }
    return *this;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------
void DirectedGraph::operator++(int)
{
    for(unsigned int inum = 0; inum < line.size(); inum++)
    {
        line[inum].weight = line[inum].weight + 1; // add 1 too all the object and save it in itself
    }
}

DirectedGraph& DirectedGraph::operator+(DirectedGraph& other)
{
        for(unsigned int inum = 0; inum < other.node.size(); inum++)
        {
            addVertex(other.node[inum]); // call funtion add vertx give him object other.node[inum]
        }
        for(unsigned int inum = 0; inum < other.line.size(); inum++)
        {
            addEdge(other.line[inum]);// call funtion add edge give him object other.line[inum]
        }

    return *this;//return object we are currently in
}

bool DirectedGraph::operator>(const DirectedGraph &other)const // G1 = current graph; G2 = given Graph
{
    int inum1(0),inum2(0);//declaration of variable

    for(unsigned int inum = 0 ; inum < line.size(); inum++) // current Graph
    {
        inum1 = inum1 + line[inum].weight;//add all the weight of edge of the current graph graph
    }

    for(unsigned int inum = 0 ; inum < other.line.size(); inum++) // Given Graph
    {
        inum2 = inum2 + other.line[inum].weight;//add all the weight of edge of the given graph
    }

    return (inum1>inum2);// return true if inum1>inum2
}

ostream& operator<<(ostream& output,DirectedGraph& DG )
{
    output << "Directed GRAPH: "<<endl; // display text
    output << DG.toString(); // display return of the funtion
    return output; //return output
}



