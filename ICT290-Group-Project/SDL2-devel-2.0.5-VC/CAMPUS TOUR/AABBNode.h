//  AABBNODE.h
//  Header file for the AABBNODE class
//  Stores details for each bounding box used for collsion detection.  Each node is stored
//  in each link of the AABB Linked List

//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBNODE_H
#define AABBNODE_H
#include<stdlib.h>
#include <vector>
#include <freeglut.h>

//--------------------------------------------------------------------------------------


	/**
	@class AABBNode
	@brief Represents a single node for use by AABBLinkedList.
	Provides the basic functions for a node. Get and set methods
	for its data members and get and set methods for 
	pointers to the next node.

	@author Shay Leary
	@version 1
	@date March 2005

	@todo Represents a node in a linked list.
	@bug No bugs.  We hope.  Blame Shay.

	*/
class AABBNode
{
public:
	AABBNode () {Clear();}
    virtual ~AABBNode () {Clear();}

	//----------------------------------------------------------------------------------

		/**
		@brief  Used by the destructor.
		sets member m_next to NULL
		*/
	void  Clear   ();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

		/**
		@brief returns value of member variable m_BBox.max.x

		@retval GLdouble
		*/
	GLdouble GetMaxX () {return m_BBox.max.x;}

		/**
		@brief returns value of member variable m_BBox.min.x

		@retval GLdouble
		*/
	GLdouble GetMinX () {return m_BBox.min.x;}

		/**
		@brief returns value of member variable m_BBox.max.y

		@retval GLdouble
		*/
	GLdouble GetMaxY () {return m_BBox.max.y;}

		/**
		@brief returns value of member variable m_BBox.min.y

		@retval GLdouble
		*/
	GLdouble GetMinY () {return m_BBox.min.y;}

		/**
		@brief returns value of member variable m_BBox.max.z

		@retval GLdouble
		*/
	GLdouble GetMaxZ () {return m_BBox.max.z;}

		/**
		@brief returns value of member variable m_BBox.min.z

		@retval GLdouble
		*/
	GLdouble GetMinZ () {return m_BBox.min.z;}

	

    

		/**
		@brief returns a pointer to the next node

		@retval AABBNode
		*/
    AABBNode *GetNext () const {return m_next;}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

		/**
		@brief  Sets member m_mBBox with the data provided

		@param const GLdouble, const GLdouble, const GLdouble, 
		const GLdouble, const GLdouble, const GLdouble
		*/
	void SetData(const GLdouble maxX, const GLdouble minX,
				 const GLdouble maxY, const GLdouble minY,
				 const GLdouble maxZ, const GLdouble minZ);

    

		/**
		@brief  Sets the member m_next to the value of the parameter.

		@param AABBNode (a pointer to thenext node)
		*/
    void SetNext (AABBNode *next) {m_next = next;}

private:
		/// The address of the next node in the list
    AABBNode *m_next;

		/// stores x,y,z co-ordinates
	struct XYZ 
	{ 
		GLdouble x, y, z; 
	}; 
		/// stores max and min values of co-ordinates
	struct BoundingBox 
	{ 
		XYZ max; 
		XYZ min; 
	}; 
		/// complex member variable that stores the data of the node
	BoundingBox m_BBox;

	//----------------------------------------------------------------------------------

		/// Privatised copy constructor
    AABBNode (const AABBNode &newNode) {};
		///Privatised assignment operator
    AABBNode &operator = (const AABBNode &newNode) {};
};

#endif
//--------------------------------------------------------------------------------------