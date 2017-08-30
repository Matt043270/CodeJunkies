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
#include<stdlib.h>
#include "AABBNode.h"
#include <freeglut.h>

//--------------------------------------------------------------------------------------

class AABBLinkedList
{
public:
	// constructor creates pointer to first node
	AABBLinkedList() {m_first = new AABBNode;}

	virtual ~AABBLinkedList() {Clear();}

	//----------------------------------------------------------------------------------

	// clears linked list and frees memory

		/**
		@brief Frees memory by deleting pointer members.
		Calls Delete.
		Called by the Destructor.
		*/
	void Clear();

	// add a node to the start of the linked list

		/**
		@brief Adds a new node, with values equal to parameters
		to the start of the list

		@param GLdouble, GLdouble, GLdouble, 
		GLdouble, GLdouble, GLdouble,

		@retval bool
		
		*/
	bool AddToStart (GLdouble maxX, GLdouble minX, GLdouble maxY,
				     GLdouble minY, GLdouble maxZ, GLdouble minZ);
	
		/**
		@brief Sets the node, position given by ptrCount,
		to the values of the rest of the params

		@param const int, const GLdouble, const GLdouble,
		const GLdouble, const GLdouble,  const GLdouble, 
		const GLdouble
	
		*/
	void SetData(const int &ptrCount,
				 const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMaxX (int ptrCount);

		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMinX (int ptrCount);

		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMaxY (int ptrCount);
		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMinY (int ptrCount);

		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMaxZ (int ptrCount);

		/**
		@brief Returns the max X value of the given node

		@param int
		@retval GLdouble
		*/
	GLdouble GetMinZ (int ptrCount);
	
	/**
	@brief returns the size of the list as an int

	@retval int
	*/
	int GetListSize ();
	
	// Return the address of the link to the next node in the list

		/**
		@brief returns the adderss of the link to the 
		next node in the list

		@retval AABBNode*
		*/
    AABBNode *GetNext () const {return m_first->GetNext();}
	/**
	@briefReturn the address of the link to the first node in the list

	@retval AABBNode*
	*/
	AABBNode *GetFirst() const {return m_first;}

//--------------------------------------------------------------------------------------

private:
		/// pointer to first node in list
	AABBNode *m_first;

	
		/**
		@brief deletes the node pointed to by param

		@param AABBNode*
		*/
	void Delete (AABBNode *before);

	
		/**
		@brief privatised copy constructor
		*/
	AABBLinkedList (const AABBLinkedList &ll) {};

		/**
		@brief privatised assignment operator
		*/
	AABBLinkedList &operator = (const AABBLinkedList &ll) {};
};

#endif

//--------------------------------------------------------------------------------------