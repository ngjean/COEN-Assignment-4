/*
Programmer:Jean Carlos Ng Lee
ID: 40026914
Programmer: Gabriel Giordano
ID: 40065284
*/
using namespace std;
#include<iostream>
#include"Edge.h"

int main()
{
	Edge edge1;//create object edge
	Edge edge2(1,2,15);//create object edge fomr 1-> 2 with a weight of 15
	Edge edge3(edge2);//create and object with the same value of edge2

	edge1.print();//call print funtion
	edge2.print();//call print funtion
	edge3.print();//call print funtion

	return 0;
}
