//  PlainLinkedList.h
//  Header file for the PlainLinkedList class
//  Linked List used to store nodes (PlainNode) which contain the co-ordinates of the 
//  of each plain used in the program.
//
//	The program will split the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINLINKED_LIST_H
#define PLAINLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "PlainNode.h"

//--------------------------------------------------------------------------------------


/**
@class PlainLinkedList
@brief Linked list used to store nodes

Linked list is used to store PlainNodes which contain the coordinates of each plane
used in the program.

The program will split the world into four quadrents and creates a linked list to
store the bounding box details for each

@author Shay Leary
@version 01
@date APR05

@author Team CodeJunkies
@version 02
@date 05SEP17

*/

class PlainLinkedList
{
public:
	// constructor creates pointer to first node
	PlainLinkedList() { m_first = new PlainNode; }

	virtual ~PlainLinkedList() { Clear(); }

	//----------------------------------------------------------------------------------

	/**
	@brief Clears linked list and frees memory

	@return void
	*/
	void Clear();

	/**
	@brief Adds a node to the start of the linked list

	@param tempType - The type of plane (0 - flat plane, 1 - YZ angled plane, 2 - XY angled plane)
	@param tempXs - The starting value on the X axis
	@param tempXe - The ending value on the X axis
	@param tempYs - The starting value on the Y axis
	@param tempYe - The ending value on the Y axis
	@param tempZs - The starting value on the Z axis
	@param tempZe - The starting value on the Z axis

	@return void
	*/
	bool AddToStart(const int tempType,
		const GLdouble tempXs, const GLdouble tempXe,
		const GLdouble tempYs, const GLdouble tempYe,
		const GLdouble tempZs, const GLdouble tempZe);

	/**
	@brief Sets the values of the node data

	@param ptrCount - The number of the node position
	@param tempType - The type of plane (0 - flat plane, 1 - YZ angled plane, 2 - XY angled plane)
	@param tempXs - The starting value on the X axis
	@param tempXe - The ending value on the X axis
	@param tempYs - The starting value on the Y axis
	@param tempYe - The ending value on the Y axis
	@param tempZs - The starting value on the Z axis
	@param tempZe - The starting value on the Z axis

	@return void
	*/
	void SetData(const int &ptrCount, const int tempType,
		const GLdouble tempXs, const GLdouble tempXe,
		const GLdouble tempYs, const GLdouble tempYe,
		const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/**
	@brief Return the plane type

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetType(int ptrCount);

	/**
	@brief Return the starting X value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetXstart(int ptrCount);

	/**
	@brief Return the ending X value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetXend(int ptrCount);

	/**
	@brief Return the starting Y value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetYstart(int ptrCount);

	/**
	@brief Return the ending Y value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetYend(int ptrCount);

	/**
	@brief Return the starting Z value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetZstart(int ptrCount);

	/**
	@brief Return the ending Z value

	@param ptrCount - The position of the node in the linked list

	@return GLdouble
	*/
	GLdouble GetZend(int ptrCount);

	/**
	@brief Return the size of the linked list

	@return int
	*/
	int GetListSize();

	/**
	@brief Return the address of the link to the next node in the list

	@return PlainNode
	*/
	PlainNode *GetNext() const { return m_first->GetNext(); }

	/**
	@brief Return the address of the link to the first node in the list

	@return PlainNode
	*/
	PlainNode *GetFirst() const { return m_first; }


	//--------------------------------------------------------------------------------------

private:
	// pointer to first node in list
	PlainNode *m_first;

	// used to clear memory
	/**
	@brief Deletes node and clears memory

	@param before - The node to be deleted

	@return void
	*/
	void Delete(PlainNode *before);

	// Privatised copy constructor and assignment operator
	PlainLinkedList(const PlainLinkedList &array) {};
	PlainLinkedList &operator = (const PlainLinkedList &array) {};
};

#endif

//--------------------------------------------------------------------------------------