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
    bool flag1 = false;
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
            flag1 = true;
        }
    }

    return flag1;
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

    for (unsigned int j = 0; j < node.size() ; j++){

    	if(node[j].getId() == newLine.dest)
    	        {
    	        	node[j].changeArrivals(1);
    	        }
    }


    line.push_back(newLine);
    iline++;
    return true;
}

bool DirectedGraph::removeEdge(Edge & e)
{
	bool flag2 = false;

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

                flag2 = true;
            }
        }
    }

    return flag2;
}

bool DirectedGraph::searchVertex(const Vertex& v)
{
    int iid;
    iid = v.getId();
    bool flag3 = false;

    for(int inum = 0; inum <= inode; inum++)
    {
        if(node[inum].getId() == iid)
        {
            flag3 = true;
        }
    }

    return flag3;
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
    /*int iid;
    iid = v.getId();
    for(int ivalue = 0 ; ivalue < iline; ivalue++)
    {
        if(line[ivalue].start == iid)
        {
            cout<<"|"<<line[ivalue].start<<"| --> |"<<line[ivalue].dest<<"|"<<endl;
        }
    }*/


	vector <Vertex> display;

	if(v.getTotalArrivals() != 0){

		for (size_t j = 0; j < line.size(); j++){

			if ( line[j].dest == v.getId()){

				display.push_back(v);
				for (size_t k = 0; k < node.size(); k++){

					if(node[k].getId() == line[j].start){

						display.push_back(node[k]);					// here I add the first adjacent node to the list

						for(size_t l = 0 ; l < line.size() ; l++){

							if (line[l].dest == node[k].getId()){

								for (size_t m = 0; m < node.size(); m++){

									if(node[m].getId() == line[l].start){

										display.push_back(node[m]);			// I add a second level of adjacency to the display vector
									}
								}
							}
						}
					}
				}
			}

			if (display[0].getId() == v.getId()){

				cout << endl;
				for (unsigned int s = display.size(); s > 0; --s){

					cout << display[s].getId() << "--->";
				}
				cout << endl;

				for (size_t a = display.size(); a > 0; --a){

					display.erase(display.begin() + a);
				}
			}
		}
	}

	else if(v.getTotalArrivals() == 0){
		cout << "The Vertex " << v.getId() << " is orphan." << endl;
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
	string str1 = "none";
	return str1;
}

bool DirectedGraph::clean()
{
	bool flag4 = false;
	return flag4;
}

bool DirectedGraph::operator==(const DirectedGraph &other) const{

	bool flag = true;
	

	// Vectors of Vertices of this and other DirectedGraph are compared

	if (node.size() != other.node.size()){

		flag = false;
	}

	else{

		for (unsigned int j = 0; j < node.size(); j++){

			if(node[j].getId() != other.node[j].getId() || node[j].getValue() != other.node[j].getValue()){

				flag = false;
			}
		}
	}


	// Vectors of Edges of this and other DirectedGraph are compared

	if (line.size() != other.line.size()){

			flag = false;
	}

	else{

		for (unsigned int j = 0; j < line.size(); j++){

			if(line[j].start != other.line[j].start || line[j].dest != other.line[j].dest  || line[j].weight != other.line[j].weight){

				flag = false;
			}
		}
	}

	return flag;
}

const DirectedGraph& DirectedGraph::operator =(const DirectedGraph& other){

	if(&other != this){

		if(!(*this == other)){
			
			node.clear();
			line.clear();
			for (unsigned int i = 0; i < other.node.size();i++){
				
				node[i] = other.node[i];
			}
			
			for (unsigned int j = 0; j < other.line.size(); j++){
				
				line[j] = other.line[j];
			}
			
		}
	}

	return *this;
}


