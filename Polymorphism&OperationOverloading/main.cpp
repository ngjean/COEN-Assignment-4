#include <iostream>
#include <windows.h>
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
    Eptr = new Edge(10,17,5);// add a edge from vertex 10 to 16 with a weight of 5
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
    Eptr = new Edge(11,15,5);
    DGptr->display(*Eptr);// show the path of edge which would be 11 -> 15 which was previously eliminated while testing remove edge
    DGptr->addEdge(*Eptr);//to avoid confusion
    Eptr = new Edge(13,16,5);
    DGptr->display(*Eptr);// show the path of edge which would be 13 -> 16 which there isnt because vertex 6 was eliminated before while testing remove vertex
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

    system("PAUSE");
    delete DGptr;
    system("CLS");
    cout<<"START OVERLOADING FUNTION"<<endl<<endl;
//-----------------------TEST OVERLOADING--------------------------------------------------------------------------------------------------
    DirectedGraph DG1, DG2, DG3;
//-----------------------------TEST OVERLOADING OPERATOR '=='-----------------------------------------------------------------------
    if(DG1 == DG2)
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }
    Vptr = new Vertex(1,5);
    DG1.addVertex(*Vptr);
    Vptr = new Vertex(2,3);
    DG1.addVertex(*Vptr);
    Vptr = new Vertex(3,4);
    DG1.addVertex(*Vptr);
    Vptr = new Vertex(4,5);
    DG1.addVertex(*Vptr);
    Vptr = new Vertex(5,10);
    DG1.addVertex(*Vptr);

    Eptr = new Edge(1,2,10);
    DG1.addEdge(*Eptr);
    Eptr = new Edge(2,3,5);
    DG1.addEdge(*Eptr);
    Eptr = new Edge(1,4,10);
    DG1.addEdge(*Eptr);
    Eptr = new Edge(4,3,2);
    DG1.addEdge(*Eptr);
    Eptr = new Edge(3,5,6);
    DG1.addEdge(*Eptr);

    if(DG1 == DG2)
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }
//-----------------------------------------------------------------------------------
    cout<<endl;
//---------------------------TEST OVERLOADING OPERATOR '='-------------------------
    DG2 = DG1;
    if(DG1 == DG2)
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }
    Vptr = new Vertex(100,5);
    DG2.addVertex(*Vptr);
    DG2.display();

    if(DG1 == DG2)
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;
    }
//-----------------------------------------------------------------------------------
    cout<<endl;
//-----------------TEST OVERLOADING OPERATOR '>' and '++'-----------------------------
    if(DG1>DG2)
   {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;
    }

    DG1++;
    if(DG1>DG2)
    {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;
    }
//-----------------------------------------------------------------------------------
    cout<<endl;
//----------------------------TEST OVERLOADING '+' and '='-----------------------------------
   DG3 = (DG1 + DG2);
   DG1.display();
   DG2.display();
   DG3.display();
//-----------------------------------------------------------------------------------
    cout<<endl;
//----------------------------TEST OVERLOADING '<<'-----------------------------------
   cout<<DG1;
   return 0;
}
