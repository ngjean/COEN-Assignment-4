/*
Programmer:NGJEAN
Program:
Date:
*/
#include<iostream>
#include"Vertex.h"
using namespace std;

int main()
{
	Vertex vertex1(1,25);
	Vertex vertex2(2,15);
	Vertex vertex3(vertex1);
	
	cout<<"the Id of this Vertex is "<<vertex1.getId()<<endl;
	cout<<"the value value of this Vertex is "<<vertex1.getValue()<<endl;
	vertex1.setValue(100);
	cout<<"the value value of this Vertex is "<<vertex1.getValue()<<endl;
	
	cout<<"the ammount of connecting from this vertex is "<<vertex1.getIconnect()<<endl;
	cout<<"the ammount of connection from other vertex to this vertex is "<<vertex1.getIconnect()<<endl;
	cout<<"Therefore this is lone vertex"<<endl;
	
	
	
	return 0;
}
