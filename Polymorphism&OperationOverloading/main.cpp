#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "DirectedGraph.h"
using namespace std;

int main()
{
    DirectedGraph *DGptr;
    Vertex *Vptr;
    Edge *Eptr;

    DGptr = new DirectedGraph();
//----------------------------------ADD VERTEX TO GRAPH---------------------------------
    Vptr = new Vertex(0,0);
    if(DGptr->addVertex(*Vptr))
    {
        cout<<"Vertex "<<0<<" with a value of "<<0<<" added successfully"<<endl;
    }
    else
    {
        cout<<"FAIL TO ADD VERTEX"<<endl;
    }

    for(int inum = 0 ; inum < 10; inum++) // add vertex with ID 1-10
    {
        Vptr = new Vertex(inum+1, 2*inum+1);
        DGptr->addVertex(*Vptr);
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//-------------------ADD EDGE TO GRAPH---------------------------------------------
    Eptr = new Edge(1,4,5);// add a edge from vertex 1 to 4 with a weight of 5
    if(DGptr->addEdge(*Eptr))
    {
        cout<<"Edge add successfully"<<endl;
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl;
    }
    Eptr = new Edge(9,11,5);// add a edge from vertex 9 to 11 with a weight of 5 which vertex 11 doesnt exsist
    if(DGptr->addEdge(*Eptr))
    {
        cout<<"Edge add successfully"<<endl;
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl;
    }
    Eptr = new Edge(1,5,3);// add a edge from vertex 1 -> 5 with a weight of 3
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(4,7,6);// add a edge from vertex 4 -> 7 with a weight of 6
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(5,9,11);// add a edge from vertex 5 -> 9 with a weight of 11
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(2,8,12);// add a edge from vertex 2 -> 8 with a weight of 12
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(2,9,13);// add a edge from vertex 2 -> 9 with a weight of 13
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(3,6,5);// add a edge from vertex 3 -> 6 with a weight of 5
    DGptr->addEdge(*Eptr);
//---------------------------------------------------------------------------------
    cout<<endl;
//------------TEST SEARCH EDGE--------------------------------------------
    Eptr = new Edge(1,5,3);
    if(DGptr->searchEdge(*Eptr))
    {
        cout<<"The given Edge Exist"<<endl;
    }
    else
    {
        cout<<"The given Edge does not Exist"<<endl;
    }

    DGptr->removeEdge(*Eptr);//remove edge 1->5

    if(DGptr->searchEdge(*Eptr))
    {
        cout<<"The given Edge Exist"<<endl;
    }
    else
    {
        cout<<"The given Edge does not Exist"<<endl;
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//--------------------TEST SEARCH VERTEX------------------------------------------
    Vptr = new Vertex(6,13);//vertex with id 6
    if(DGptr->searchVertex(*Vptr))//vertex with id 6
    {
        cout<<"The given Vertex Exist"<<endl;
    }
    else
    {
        cout<<"The given Vertex does not Exist"<<endl;
    }

    DGptr->removeVertex(*Vptr);//vertex with id 6
    if(DGptr->searchVertex(*Vptr))//vertex with id 6
    {
        cout<<"The given Vertex Exist"<<endl;
    }
    else
    {
        cout<<"The given Vertex does not Exist"<<endl;
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//--------------------------TEST DISPLAY GIVEN EDGE-------------------------------
    DGptr->display(*Eptr);// show the path of edge which would be 1 -> 5 which was previously eliminated while testing remove edge
    DGptr->addEdge(*Eptr);//to avoid confusion
    Eptr = new Edge(3,6,5);
    DGptr->display(*Eptr);// show the path of edge which would be 3 -> 6 which there isnt because vertex 6 was eliminated before while testing remove vertex
    DGptr->addVertex(*Vptr);//addign back the vertex to the graph
    DGptr->addEdge(*Eptr);// reconnecting the edge form 3->6
    DGptr->display(*Eptr);// now it will show 3->6
    Eptr = new Edge(5,9,11);
    DGptr->display(*Eptr);// show the path of edge which would be 5 -> 9
//---------------------------------------------------------------------------------
    cout<<endl;

    Vptr = new Vertex(4,9);
    DGptr->display(*Vptr);

    DGptr->display();


    return 0;
}
