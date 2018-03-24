//============================================================================
// Name        : Polymorphism&OperationOverloading.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
//#include "Vertex.h"
#include "DirectedGraph.h"

using namespace std;

int main() {

	/*Vertex v1(40065184,81);
	Vertex v2(98,27);
	Vertex v3(144,64);

	vector <Vertex> myVector;


		myVector.push_back(v1);
		myVector.push_back(v2);
		myVector.push_back(v3);

	cout << "John Doe"<< endl;
	cout << "My Vector size is: " << myVector.size()<< endl;
	for (size_t i= 0; i < myVector.size() ; i++){

		cout << myVector[i].getValue()<< endl;
		//cout << myVector[1].getValue()<< endl;
	}

	myVector.erase(myVector.begin() + 2);
	cout << endl << "Erasing the third element.";
	cout << endl << "Now the size is: "<< myVector.size()<< endl;
	*/

	DirectedGraph d1;
	Vertex v1(1,84),v2(2,45),v3(3,76),v4(4,12),v5(5,92);
	//cout << "the id of v1 is "<<v1.getId()<<" and its value is "<< v1.getValue();

	Edge a(1,2,40),b(1,4,50),c(2,3,30),d(4,3,60),e(3,5,20);

	d1.addVertex(v1);
	d1.addVertex(v2);
	d1.addVertex(v3);
	d1.addVertex(v4);
	d1.addVertex(v5);

	d1.addEdge(a);
	d1.addEdge(b);
	d1.addEdge(c);
	d1.addEdge(d);
	d1.addEdge(e);

	cout << "The display of v3: "<< endl;
	d1.display(v3);
	cout << endl;

    return 0;
}
