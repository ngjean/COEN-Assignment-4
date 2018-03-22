/*
 * AdjList.h
 *
 *  Created on: Mar 22, 2018
 *      Author: usuario
 */

#ifndef ADJLIST_H_
#define ADJLIST_H_

#include "Vertex.h"

class AdjList {
public:
	AdjList();

	Vertex* heads;

	~AdjList();
};

#endif /* ADJLIST_H_ */
