/*
Programmer:NGJEAN
Program:
Date:
*/
using namespace std;
#include<iostream>
#include"Edge.h"

int main()
{
	Edge edge1;
	Edge edge2(1,2,15);
	Edge edge3(edge2);
	
	edge1.print();
	edge2.print();
	edge3.print();
	
	return 0;
}
