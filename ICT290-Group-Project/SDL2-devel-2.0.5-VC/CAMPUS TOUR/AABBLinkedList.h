//  AABBLinkedList.h
//  Header file for the AABBLinkedList class
//  Linked List used to store nodes (AABBNode) which contain the co-ordinates of the 
//  boundings boxes which are used for the collsion detection.
//
//	The program splits the world into four quadrants and creates a linked list to
//  store the bounding box details for each
//
//  Author:  Shay Leary
//  March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBLINKED_LIST_H
#define AABBLINKED_LIST_H

//--------------------------------------------------------------------------------------

#include "AABBNode.h"
#include <freeglut.h>

//--------------------------------------------------------------------------------------
/**
@class AABBLinkedList
@brief Linked list used to store the bounding box nodes

Linked list used to store nodes (AABBNode) which contain the co-ordinates of the bounding
boxes which are used for the collision detection

The program splits the world into four quadrants and creates a linked list to store the
bounding box details for each.

@author Shay Leary
@version 01
@date MAR05

@author Team CodeJunkies
@version 02
@date 05SEP17, added doxygen comments

*/
class AABBLinkedList
{
public:
	// constructor creates pointer to first node
	AABBLinkedList() { m_first = new AABBNode; }

	virtual ~AABBLinkedList() { Clear(); }

	//----------------------------------------------------------------------------------

	/**
	@brief Clears the linked list and frees memory

	@return void
	*/
	void Clear();

	/**
	@brief Adds a node to the start of the linked list

	@param maxX - The maximum value on the X axis
	@param minX - The minimum value on the X axis
	@param maxY - The maximum value on the Y axis
	@param minY - The minimum value on the Y axis
	@param maxZ - The maximum value on the Z axis
	@param minZ - The minimum value on the Z axis

	@return bool
	*/
	bool AddToStart(GLdouble maxX, GLdouble minX, GLdouble maxY,
		GLdouble minY, GLdouble maxZ, GLdouble minZ);

	/**
	@brief Sets the values of the node

	@param &ptrCount - The position of the node in the list
	@param maxX - The maximum value on the X axis
	@param minX - The minimum value on the X axis
	@param maxY - The maximum value on the Y axis
	@param minY - The minimum value on the Y axis
	@param maxZ - The maximum value on the Z axis
	@param minZ - The minimum value on the Z axis

	@return void
	*/
	void SetData(const int &ptrCount,
		const GLdouble maxX, const GLdouble minX,
		const GLdouble maxY, const GLdouble minY,
		const GLdouble maxZ, const GLdouble minZ);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/**
	@brief Return the maximum X value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMaxX(int ptrCount);

	/**
	@brief Return the minimum X value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMinX(int ptrCount);

	/**
	@brief Return the maximum Y value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMaxY(int ptrCount);

	/**
	@brief Return the minimum Y value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMinY(int ptrCount);

	/**
	@brief Return the maximum Z value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMaxZ(int ptrCount);

	/**
	@brief Return the minimum Z value of the node

	@param ptrCount - The position of the node in the list

	@return GLdouble
	*/
	GLdouble GetMinZ(int ptrCount);

	/**
	@brief Return the size of the list

	@return int
	*/
	int GetListSize();

	/**
	@brief Returns the address of the link to the next node in the list

	@return AABBNode
	*/
	AABBNode *GetNext() const { return m_first->GetNext(); }

	/**
	@brief Return the address of the link to the first node in the list

	@return AABBNode
	*/
	AABBNode *GetFirst() const { return m_first; }

	//--------------------------------------------------------------------------------------

private:
	// pointer to first node in list
	AABBNode *m_first;

	// used to clear memory
	void Delete(AABBNode *before);

	// Privatised copy constructor and assignment operator
	AABBLinkedList(const AABBLinkedList &ll) {};
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif

//--------------------------------------------------------------------------------------