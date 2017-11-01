//  collsion.h
//  Header file for the collision class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef COLLISION_H
#define COLLISION_H

//--------------------------------------------------------------------------------------

#include "AABB.h"
#include "AABBLinkedList.h"

//--------------------------------------------------------------------------------------

/**
@class Collision
@brief Handles the collisions and bounding boxes

@author Shay Leary
@version 01
@date MAR05

@author Team CodeJunkies
@version 02
@date 05SEP17

*/
class Collision
{
public:

	Collision() {}
	virtual ~Collision() {}

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

	/**
	@brief Sets the initial maximum X value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The maximum X value for the bounding box

	@return void
	*/
	void SetAABBMaxX(const int & tempIndex, const double &tempX) { m_AABB.SetMaxX(tempIndex, tempX); }

	/**
	@brief Sets the initial minimum X value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The minimum X value for the bounding box

	@return void
	*/
	void SetAABBMinX(const int & tempIndex, const double &tempX) { m_AABB.SetMinX(tempIndex, tempX); }

	/**
	@brief Sets the initial maximum Y value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The maximum Y value for the bounding box

	@return void
	*/
	void SetAABBMaxY(const int & tempIndex, const double &tempY) { m_AABB.SetMaxY(tempIndex, tempY); }

	/**
	@brief Sets the initial minimum Y value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The minimum Y value for the bounding box

	@return void
	*/
	void SetAABBMinY(const int & tempIndex, const double &tempY) { m_AABB.SetMinY(tempIndex, tempY); }

	/**
	@brief Sets the initial maximum Z value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The maximum Z value for the bounding box

	@return void
	*/
	void SetAABBMaxZ(const int & tempIndex, const double &tempZ) { m_AABB.SetMaxZ(tempIndex, tempZ); }

	/**
	@brief Sets the initial minimum Z value for the bounding box

	@param tempIndex - The index number of the bounding box
	@param tempX - The minimum Z value for the bounding box

	@return void
	*/
	void SetAABBMinZ(const int & tempIndex, const double &tempZ) { m_AABB.SetMinZ(tempIndex, tempZ); }

	// sets the actual world co-ordinates

	/**
	@brief Sets the size of the world on the X axis

	@param tempX - The size of the X axis

	@return void
	*/
	void SetWorldX(const double &tempX) { m_worldSizeX = tempX; }

	/**
	@brief Sets the size of the world on the Z axis

	@param tempZ - The size of the Z axis

	@return void
	*/
	void SetWorldZ(const double &tempZ) { m_worldSizeZ = tempZ; }

	// set number of bounding boxes
	/**
	@brief Sets the number of bounding boxes

	@param tempSize - The number of bounding boxes

	@return void
	*/
	void SetNoBoundingBoxes(const int & tempSize) { m_AABB.SetNoBoundingBoxes(tempSize); }

	//----------------------------------------------------------------------------------
	//  Returns Methods
	//----------------------------------------------------------------------------------


	/**
	@brief Returns the maximum X value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMaxX(const int & tempIndex) { return m_AABB.GetMaxX(tempIndex); }

	/**
	@brief Returns the minimum X value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMinX(const int & tempIndex) { return m_AABB.GetMinX(tempIndex); }

	/**
	@brief Returns the maximum Y value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMaxY(const int & tempIndex) { return m_AABB.GetMaxY(tempIndex); }

	/**
	@brief Returns the minimum Y value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMinY(const int & tempIndex) { return m_AABB.GetMinY(tempIndex); }

	/**
	@brief Returns the maximum Z value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMaxZ(const int & tempIndex) { return m_AABB.GetMaxZ(tempIndex); }

	/**
	@brief Returns the minimum Z value for the bounding box

	@param tempIndex - The index number of the bounding box

	@return double
	*/
	double GetAABBMinZ(const int & tempIndex) { return m_AABB.GetMinZ(tempIndex); }

	/**
	@brief Returns the number of bounding boxes

	@return int
	*/
	int GetNoBoundingBoxes() { return m_AABB.GetNoBoundingBoxes(); }

	/**
	@brief Returns true if a collision has occured

	@param endX - Value of the x axis
	@param endY - Value of the Y axis
	@param endZ - Value of the Z axis

	@return bool
	*/
	bool Collide(double endX, double endY, double endZ);

	/**
	@brief Read the bounding box information from the dynamic array, and creates a linked list

	@return void
	*/
	void CreateLinkedList();

private:
	// initially stores BB info in AABB (dynamic array) before copying to Linked List
	AABB m_AABB;

	// lists to store bounding box info in each quadrant
	AABBLinkedList m_list[4];

	// Stores the list size of each linked list
	// Set to 4 has the world is split into 4 quadrants
	int m_listSize[4];

	// stores world co-ordinates
	double m_worldSizeX;
	double m_worldSizeZ;

	// checks if collsion occurred (called from Collide)
	bool CheckCollision(int index, double endX, double endY, double endZ);

	//----------------------------------------------------------------------------------

	// Privatised copy constructor and assignment operator
	Collision(const Collision &coll) {};
	Collision &operator = (const Collision &coll) {};
};

#endif
//--------------------------------------------------------------------------------------