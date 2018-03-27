#include <iostream>
#include <windows.h>
#include "Vertex.h"
#include "Edge.h"
#include "DirectedGraph.h"
using namespace std;

int main()
{
    DirectedGraph *DGptr; // declaration of pointer
    Vertex *Vptr;// declaration of pointer
    Edge *Eptr;// declaration of pointer

    DGptr = new DirectedGraph(); //create object DirectedGraph
//----------------------------------ADD VERTEX TO GRAPH---------------------------------
    Vptr = new Vertex(0,0); // create vertex with id 0 and value 0
    if(DGptr->addVertex(*Vptr))//if added correctly o if it was able to add
    {
        cout<<"Vertex "<<Vptr->getId()<<" with a value of "<<Vptr->getValue()<<" added successfully"<<endl; // display text + some value return by the funtion call
    }
    else
    {
        cout<<"VERTEX ALREADY EXIST. FAIL TO ADD VERTEX "<<endl; // display text
    }

    for(int inum = 0 ; inum <= 10; inum++) // add vertex with ID 10-20
    {
        Vptr = new Vertex(inum+10, 2*inum+1);
        DGptr->addVertex(*Vptr);
    }
//---------------------------------------------------------------------------------
    cout<<endl;
//-------------------ADD EDGE TO GRAPH---------------------------------------------
    Eptr = new Edge(10,17,5);//create object edge
    if(DGptr->addEdge(*Eptr))// add a edge from vertex 10 -> 17 with a weight of 5 return true if added succefully
    {
        cout<<"Edge add successfully"<<endl; // display text
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl; // display text
    }
    Eptr = new Edge(19,100,5);//create object edge
    if(DGptr->addEdge(*Eptr))// add a edge from vertex 19 -> 100 with a weight of 5 which vertex 100 doesnt exsist
    {
        cout<<"Edge add successfully"<<endl;//display text
    }
    else
    {
        cout<<"FAIL TO ADD EDGE"<<endl; // display text
    }
    Eptr = new Edge(11,15,3);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 11 -> 15 with a weight of 3return true if added succefully

    Eptr = new Edge(14,17,6);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 14 -> 17 with a weight of 6 return true if added succefully

    Eptr = new Edge(15,19,11);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 15 -> 19 with a weight of 11 return true if added succefully

    Eptr = new Edge(12,18,12);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 12 -> 18 with a weight of 12 return true if added succefully

    Eptr = new Edge(12,19,13);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 12 -> 19 with a weight of 13 return true if added succefully

    Eptr = new Edge(13,16,5);//create object edge
    DGptr->addEdge(*Eptr);// add a edge from vertex 13 -> 16 with a weight of 5 return true if added succefully
//---------------------------------------------------------------------------------
    cout<<endl;
//------------TEST SEARCH EDGE--------------------------------------------
    Eptr = new Edge(11,15,3);//create object edge
    if(DGptr->searchEdge(*Eptr))// add a edge fro vertex 11 -> 15 with a weight of 3 return true if added succefully
    {
        cout<<"The given Edge Exist"<<endl;//display text
    }
    else
    {
        cout<<"The given Edge does not Exist"<<endl;//display text
    }
    Eptr = new Edge(11,15,3);//create object edge
    DGptr->removeEdge(*Eptr);//remove edge 11->15

    if(DGptr->searchEdge(*Eptr)) //check if given edge is in graph
    {
        cout<<"The given Edge Exist"<<endl;//display text
    }
    else
    {
        cout<<"The given Edge does not Exist"<<endl;//display text
    }
//---------------------------------------------------------------------------------
    cout<<endl; // skip a line
//--------------------TEST SEARCH VERTEX------------------------------------------
    Vptr = new Vertex(16,13);//create object vertex
    if(DGptr->searchVertex(*Vptr))//seach if vertex with id 16 exist return true if it exist
    {
        cout<<"The given Vertex Exist"<<endl;//display text
    }
    else
    {
        cout<<"The given Vertex does not Exist"<<endl; // display text
    }

    DGptr->removeVertex(*Vptr);//remove vertex with id 16
    if(DGptr->searchVertex(*Vptr))//seach if vertex with id 16 exist return true if it exist
    {
        cout<<"The given Vertex Exist"<<endl;//display text
    }
    else
    {
        cout<<"The given Vertex does not Exist"<<endl;//display text
    }
//---------------------------------------------------------------------------------
    cout<<endl;//skip a line
//--------------------------TEST DISPLAY GIVEN EDGE-------------------------------
    Eptr = new Edge(11,15,5);//create object edge
    DGptr->display(*Eptr);// show the path of edge which would be 11 -> 15 which was previously eliminated while testing remove edge
    DGptr->addEdge(*Eptr);//to avoid confusion re add remove edge

    Eptr = new Edge(13,16,5);;//create object edge
    DGptr->display(*Eptr);// show the path of edge which would be 13 -> 16 which there isnt because vertex 6 was eliminated before while testing remove vertex
    Vptr = new Vertex(16,13);//create object vertex
    DGptr->addVertex(*Vptr);//addign back the vertex to the graph
    Eptr = new Edge(11,15,5);//create object edge
    DGptr->addEdge(*Eptr);// reconnecting the edge form 3->6
    DGptr->display(*Eptr);// now it will show 3->6

    Eptr = new Edge(15,19,11);;//create object edge
    DGptr->display(*Eptr);// show the path of edge which would be 5 -> 9
//---------------------------------------------------------------------------------
    cout<<endl;//skip a line
//------------------TEST DISPLAY VERTEX-------------------------------------------
    Vptr = new Vertex(14,9);//create object
    DGptr->display(*Vptr);//display vertex with id 14 all it connection and vertext connected to him
//---------------------------------------------------------------------------------
    cout<<endl;//skip a line
//-------------------TEST DISPLAY ------------------------------------------------
    Eptr = new Edge(14,18,15);//create object
    DGptr->addEdge(*Eptr);//add edge to the graph for complexity
    Eptr = new Edge(18,19,15);//create object
    DGptr->addEdge(*Eptr);//add edge to the graph for complexity
    Eptr = new Edge(19,20,15);//create object
    DGptr->addEdge(*Eptr);//add edge to the graph for complexity

    DGptr->display();//call the funtion display
//---------------------------------------------------------------------------------
    cout<<endl;//skip a line
//-----------------TEST toString---------------------------------------------------
    cout<<DGptr->toString()<<endl; // call funtion toString() which return a string
//---------------------------------------------------------------------------------
//-----------------------test clean----------------------------------------------
    DGptr->clean(); // call funtion clean()
    DGptr->display();//call funtion display()
    cout<<endl;//skip a line
//---------------------------------------------------------------------------------------
    system("PAUSE");//pause for a while until press any key
    delete DGptr; // free up space
    system("CLS"); // clear screen
    cout<<"START OVERLOADING FUNTION"<<endl<<endl;//display text
//-----------------------TEST OVERLOADING--------------------------------------------------------------------------------------------------
    DirectedGraph DG1, DG2, DG3; // create object static
//-----------------------------TEST OVERLOADING OPERATOR '=='-----------------------------------------------------------------------
    if(DG1 == DG2) // compare DG1 to DG2
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;//display text
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;// display text
    }
    //-----------ADD VERTEX TO GRAPH--------------
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
    //-------------- ADD EDGE TO GRAPH----------------
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
    //-------------------------------------------------------
    if(DG1 == DG2)//compare DG1 to DG2
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;//display text
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;//display text
    }
//-----------------------------------------------------------------------------------
    cout<<endl;//skip a line
//---------------------------TEST OVERLOADING OPERATOR '='-------------------------
    DG2 = DG1;// make DG2 equal to DG1
    if(DG2 == DG1)//compare DG2 to DG1
    {
        cout<<"GRAPH#1 and GRAPH#2 are equal"<<endl;//display text
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;//display text
    }
    Vptr = new Vertex(100,5);// create object
    DG2.addVertex(*Vptr);//add vertex to DG2

    if(DG1 == DG2)//compare DG2 to DG1
    {
        cout<<"GRAPH#1 is equal to GRAPH#2"<<endl;//display text
    }
    else
    {
        cout<<"GRAPH#1 is NOT equal to GRAPH#2"<<endl;//display text
    }
//-----------------------------------------------------------------------------------
    cout<<endl;//skip a line
//-----------------TEST OVERLOADING OPERATOR '>' and '++'-----------------------------
    if(DG1>DG2)// return true if sum of DG1 edge is greater than sum of DG2 edge
   {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;//display text
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;//display text
    }

    DG1++;// add 1 to all the edge in DG1
    if(DG1>DG2)
    {
        cout<<"GRAPH#1 is greater to GRAPH#2"<<endl;//display text
    }
    else
    {
        cout<<"Either GRAPH#2 is greater or equal to GRAPH#1"<<endl;//display text
    }
//-----------------------------------------------------------------------------------
    cout<<endl;//skip a line
//----------------------------TEST OVERLOADING '+' and '='-----------------------------------
   DG3 = (DG1 + DG2); // make DG3 equal to the sumation of vertex and edge of DG1 and DG2
   DG1.display();//dsiplay DG1 graph
   DG2.display();//dsiplay DG2 graph
   DG3.display();//dsiplay DG3 graph
//-----------------------------------------------------------------------------------
    cout<<endl;//skip a line
//----------------------------TEST OVERLOADING '<<'-----------------------------------
   cout<<DG1;// display DG1 graph

   return 0;
}
