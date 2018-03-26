#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "DirectedGraph.h"
using namespace std;

int main()
{
    DirectedGraph *DGptr,*DGptr2;
    Vertex *Vptr;
    Edge *Eptr;

    DGptr = new DirectedGraph();
//----------------------------------ADD VERTEX TO GRAPH---------------------------------
    Vptr = new Vertex(0,0);
    if(DGptr->addVertex(*Vptr))
    {
        cout<<"Vertex "<<Vptr->getId()<<" with a value of "<<Vptr->getValue()<<" added successfully"<<endl;
    }
    else
    {
        cout<<"VERTEX ALREADY EXIST. FAIL TO ADD VERTEX "<<endl;
    }

    for(int inum = 0 ; inum <= 10; inum++) // add vertex with ID 1-10
    {
        Vptr = new Vertex(inum+10, 2*inum+1);
        DGptr->addVertex(*Vptr);
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//-------------------ADD EDGE TO GRAPH---------------------------------------------
    Eptr = new Edge(10,16,5);// add a edge from vertex 10 to 16 with a weight of 5
    if(DGptr->addEdge(*Eptr))
    {
        cout<<"Edge add successfully"<<endl;
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl;
    }
    Eptr = new Edge(19,100,5);// add a edge from vertex 19 -> 100 with a weight of 5 which vertex 100 doesnt exsist
    if(DGptr->addEdge(*Eptr))
    {
        cout<<"Edge add successfully"<<endl;
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl;
    }
    Eptr = new Edge(11,15,3);// add a edge from vertex 11 -> 15 with a weight of 3
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(14,17,6);// add a edge from vertex 14 -> 17 with a weight of 6
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(15,19,11);// add a edge from vertex 15 -> 19 with a weight of 11
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(12,18,12);// add a edge from vertex 12 -> 18 with a weight of 12
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(12,19,13);// add a edge from vertex 12 -> 19 with a weight of 13
    DGptr->addEdge(*Eptr);

    Eptr = new Edge(13,16,5);// add a edge from vertex 13 -> 16 with a weight of 5
    DGptr->addEdge(*Eptr);
//---------------------------------------------------------------------------------
    cout<<endl;
//------------TEST SEARCH EDGE--------------------------------------------
    Eptr = new Edge(11,15,3);
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
    Vptr = new Vertex(16,13);//vertex with id 6
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
    Eptr = new Edge(13,16,5);
    DGptr->display(*Eptr);// show the path of edge which would be 3 -> 6 which there isnt because vertex 6 was eliminated before while testing remove vertex
    DGptr->addVertex(*Vptr);//addign back the vertex to the graph
    DGptr->addEdge(*Eptr);// reconnecting the edge form 3->6
    DGptr->display(*Eptr);// now it will show 3->6
    Eptr = new Edge(15,19,11);
    DGptr->display(*Eptr);// show the path of edge which would be 5 -> 9
//---------------------------------------------------------------------------------
    cout<<endl;
//------------------TEST DISPLAY VERTEX-------------------------------------------
    Vptr = new Vertex(14,9);
    DGptr->display(*Vptr);
//---------------------------------------------------------------------------------
    cout<<endl;
//-------------------TEST DISPLAY ------------------------------------------------
    Eptr = new Edge(14,18,15);
    DGptr->addEdge(*Eptr);
    Eptr = new Edge(18,19,15);
    DGptr->addEdge(*Eptr);
    Eptr = new Edge(19,20,15);
    DGptr->addEdge(*Eptr);

    DGptr->display();
//---------------------------------------------------------------------------------
    cout<<endl;
//-----------------TEST toString---------------------------------------------------
    cout<<DGptr->toString()<<endl;
//---------------------------------------------------------------------------------
    cout<<endl;




//-----------------------TEST OVERLOADING--------------------------------------------------------------------------------------------------
    DGptr2 = new DirectedGraph();
    DirectedGraph DG3;
//-----------------------------TEST OVERLOADING OPERATOR '=='--------------------------------
    if(DGptr == DGptr2) // GRAPH 2 doesnt have any vertex or edge // TEST '=='
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }
//-----------------------------------------------------------------------------------
    cout<<endl;
//---------------------------TEST OVERLOADING OPERATOR '>'----------------------------
    if(DGptr>DGptr2)// GRAPH 2 doesnt have any vertex or edge
    {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//----------------------------TEST OVERLOADING OPERATOR '='------------------------
    DGptr2 = DGptr; //  GRAPH#2 = GRAPH#1 // TEST '='
    if(DGptr == DGptr2)
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }

    if(DGptr>DGptr2)
    {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//-------------------TEST OVERLOADING OPERATOR '++' ------------------------------
    DGptr=DGptr++;//add 1 to all its edge of DGptr
    if(DGptr>DGptr2)
    {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//----------------------------TEST OVERLOADING '+'-----------------------------------


    return 0;
}
