//  AABH.h
//  Header file for the AABB class
//  Dynamic Array used to store the co-ordinates of the bounding boxes used for collsion
//  detection.  The array is only used initially before being copied into AABB Linked Lists.
//  The array is then terminated.
//
//  I created this class originally before using linked lists to store the BB info. But decided
//  to keep it has the stored data can be easily copied across into different linked lists
//  in any prefered order. (i.e. the data is copied into across into linked lists for different
//  quadrants)
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABB_H
#define AABB_H

//--------------------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#include <freeglut.h>

using namespace std;

//--------------------------------------------------------------------------------------

    /**
    @class AABB
    @brief Dynamic array used to store the coordinates of the bounding boxes used for collision detection.

    The array is only used initially before being copied into AABB Linked Lists. The array is then terminated.

    I created this class originally before using linked lists to store the BB info. But decided
    to keep it has the stored data can be easily copied across into different linked lists
    in any prefered order. (i.e. the data is copied into across into linked lists for different
    quadrants)

    @author Shay Leary
    @version 01
    @date MAR05

    @author Team CodeJunkies
    @version 02
    @date 05SEP17

    */
class AABB
{
private:
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
	/// dynamic array to store info
	BoundingBox *m_BBox;
	/// number of BB created (i.e. array size)
	int m_NoOfBoxes;
	/// deletes arrays and clears memory
	void ClearBB(BoundingBox* &tempArray);

	//----------------------------------------------------------------------------------

	/// Privatised copy constructor and assignment operator
	AABB(const AABB &aabb) {};
	AABB &operator = (const AABB &aabb) {};

public:
	AABB() {}
	virtual ~AABB() { ClearBB(m_BBox); }

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Set the maximum X value of the bounding box

        @param tempIndex - The index number of the bounding box
        @param tempX - The maximum X value

        @return void
        */
	void SetMaxX(const int & tempIndex, const GLdouble &tempX) { m_BBox[tempIndex].max.x = tempX; }

        /**
        @brief Set the minimum X value of the bounding box

        @param &tempIndex - The index number of the bounding box
        @param &tempX - The minimum X value

        @return void
        */
	void SetMinX(const int & tempIndex, const GLdouble &tempX) { m_BBox[tempIndex].min.x = tempX; }

        /**
        @brief Set the maximum Y value for the bounding box

        @param &tempIndex - The index number for the bounding box
        @param &tempY - The maximum Y value

        @return void
        */
	void SetMaxY(const int & tempIndex, const GLdouble &tempY) { m_BBox[tempIndex].max.y = tempY; }

        /**
        @brief Set the minimum Y value for the bounding box

        @param &tempIndex - The index number for the bounding box
        @param &tmepY - The minimum Y value

        @return void
        */
	void SetMinY(const int & tempIndex, const GLdouble &tempY) { m_BBox[tempIndex].min.y = tempY; }

        /**
        @brief Set the maximum Z value for the bounding box

        @param &tempIndex - The index number for the bounding box
        @param &tempZ - The maximum Z value

        @return void
        */
	void SetMaxZ(const int & tempIndex, const GLdouble &tempZ) { m_BBox[tempIndex].max.z = tempZ; }

        /**
        @brief Set the minimum Z value for the bounding box

        @param &tempIndex - The index number for the bounding box
        @param &temp Z - The minimum Z value

        @return void
        */
	void SetMinZ(const int & tempIndex, const GLdouble &tempZ) { m_BBox[tempIndex].min.z = tempZ; }

        /**
        @brief Set the number of bounding boxes in the array

        @param &tempSize - The size of the array

        @return void
        */
	void SetNoBoundingBoxes(const int & tempSize);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Return the maximum X value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMaxX(const int & tempIndex) { return m_BBox[tempIndex].max.x; }

        /**
        @brief Return the minimum X value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMinX(const int & tempIndex) { return m_BBox[tempIndex].min.x; }

        /**
        @brief Return the maximum Y value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMaxY(const int & tempIndex) { return m_BBox[tempIndex].max.y; }

        /**
        @brief Return the minimum Y value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMinY(const int & tempIndex) { return m_BBox[tempIndex].min.y; }

        /**
        @brief Return the maximum Z value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMaxZ(const int & tempIndex) { return m_BBox[tempIndex].max.z; }

        /**
        @brief Return the minimum Z value for the bounding box

        @param tempIndex - The index number for the bounding box

        @return GLdouble
        */
	GLdouble GetMinZ(const int & tempIndex) { return m_BBox[tempIndex].min.z; }

        /**
        @brief Return the size of the bounding box array

        @return int
        */
	int GetNoBoundingBoxes() { return m_NoOfBoxes; }
};

#endif
//--------------------------------------------------------------------------------------
