//  PlainNode.h
//  Header file for the PlainNode class
//  Stores details for each plain.  Each node is stored in each link of the Plain Linked List

//  Shay Leary, April 2005
//--------------------------------------------------------------------------------------

#ifndef PLAINNODE_H
#define PLAINNODE_H

//--------------------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#include <freeglut.h>

using namespace std;


/**
@class PlainNode
@brief Stores the details for each plane.

The details of each plane are stored in a node, which in turn are stored in a linked list.

@author Shay Leary
@version 01
@date APR05

@author Team CodeJunkies
@version 02
@date 05SEP17, added doxygen comments
*/
class PlainNode
{

public:
	PlainNode() { Clear(); }
	virtual ~PlainNode() { Clear(); }

	//----------------------------------------------------------------------------------

	/**
	@brief Resets the node

	@return void
	*/
	void  Clear();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

	/**
	@brief Returns the type of plane

	@return GLdouble - type of plane
	*/
	GLdouble GetType() { return m_type; }

	/**
	@brief Returns the location of the start of the plane - X axis

	@return GLdouble - X axis location
	*/
	GLdouble GetXstart() { return m_xPlainStart; }

	/**
	@brief Returns the location of the end of the plane - X axis

	@return GLdouble - X axis location
	*/
	GLdouble GetXend() { return m_xPlainEnd; }

	/**
	@brief Returns the location of the start of the plane - Y axis

	@return GLdouble - Y axis location
	*/
	GLdouble GetYstart() { return m_yPlainStart; }

	/**
	@brief Returns the location of the end of the plane - Y axis

	@return GLdouble - Y axis location
	*/
	GLdouble GetYend() { return m_yPlainEnd; }

	/**
	@brief Returns the location of the start of the plane - Z axis

	@return GLdouble - Z axis location
	*/
	GLdouble GetZstart() { return m_zPlainStart; }

	/**
	@brief Returns the location of the end of the plane - Z axis

	@return GLdouble - Z axis location
	*/
	GLdouble GetZend() { return m_zPlainEnd; }


	/**
	@brief Returns the address of the next node in the list

	@return PlainNode - The adddress of the next node in the list
	*/
	PlainNode *GetNext() const { return m_next; }



	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	@brief Sets the plane data in the node

	@param tempType - The type of plane
	@param tempXs - The X axis starting location
	@param tempXe - The X axis ending location
	@param tempYs - The Y axis starting location
	@param tempYe - The Y axis ending location
	@param tempZs - The Z axis starting location
	@param tempZe - The Z axis ending location

	@return void
	*/
	void SetData(const int tempType,
		const GLdouble tempXs, const GLdouble tempXe,
		const GLdouble tempYs, const GLdouble tempYe,
		const GLdouble tempZs, const GLdouble tempZe);

	/**
	@brief Sets the address of link in the next node in the list

	@param *next - The next node in the list

	@return void
	*/
	void SetNext(PlainNode *next) { m_next = next; }

private:
	// The address of the next node in the list
	PlainNode *m_next;

	// Stores type of plain:
	// (0: flat plane)
	// (1: incline from z to y)
	// (2: incline from x to y)
	GLdouble m_type;


	// stores start and end co-ordinates of plane on x, y and z axis
	GLdouble m_xPlainStart, m_xPlainEnd;
	GLdouble m_yPlainStart, m_yPlainEnd;
	GLdouble m_zPlainStart, m_zPlainEnd;

	//----------------------------------------------------------------------------------

	// Privatised copy constructor and assignment operator
	PlainNode(const PlainNode &newNode) {};
	PlainNode &operator = (const PlainNode &newNode) {};
};

#endif

//--------------------------------------------------------------------------------------