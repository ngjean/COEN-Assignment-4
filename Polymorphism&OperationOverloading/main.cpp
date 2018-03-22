#include <iostream>

using namespace std;

int main()
{
    
    
    return 0;
}



// The Little Program to Test Vectors

#include <iostream>
#include <vector>
#include "Vertex.h"
using namespace std;

int main() {

	Vertex v1(40065184,81);
	Vertex v2(98,27);
	Vertex v3(144,64);

	vector <Vertex> myVector;


		myVector.push_back(v1);
		myVector.push_back(v2);
		myVector.push_back(v3);

	cout << "Gabriel Giordano"<< endl;
	cout << myVector.size()<< endl;
	for (int i= 0; i <=2 ; i++){

		cout << myVector[i].getValue()<< endl;
		//cout << myVector[1].getValue()<< endl;
	}

	myVector.erase(myVector.begin() + 2);
	cout << endl << "Now te size is: "<< myVector.size()<< endl;
	myVector.shrink_to_fit();
	cout << endl << "Now te size after srinking is: "<< myVector.size()<< endl;
	cout << endl << "The value of v3 is: "<<v3.getValue();

	return 0;

}

