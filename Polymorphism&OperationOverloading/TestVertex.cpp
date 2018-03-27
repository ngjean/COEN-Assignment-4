/*
Programmer:Jean Carlos Ng Lee
ID: 40026914
Programmer: Gabriel Giordano
ID: 40065284
*/
#include<iostream>
#include"Vertex.h"
using namespace std;

int main()
{
	Vertex vertex1(1,25);//create vertex with ID 1 and value 25
	Vertex vertex2(2,15);//create vertex with ID 2 and value 15
	Vertex vertex3(vertex1);//create vertex with the same value as vertex1

	cout<<"the Id of this Vertex is "<<vertex1.getId()<<endl;//display info
	cout<<"the value value of this Vertex is "<<vertex1.getValue()<<endl;//display info
	vertex1.setValue(100);//change value of vertex 1
	cout<<"the value value of this Vertex is "<<vertex1.getValue()<<endl;//display info

	cout<<"the ammount of connecting from this vertex is "<<vertex1.getIconnect()<<endl;//display info
	cout<<"the ammount of connection from other vertex to this vertex is "<<vertex1.getIconnect()<<endl;//display info
	cout<<"Therefore this is lone vertex"<<endl;//display info



	return 0;
}
