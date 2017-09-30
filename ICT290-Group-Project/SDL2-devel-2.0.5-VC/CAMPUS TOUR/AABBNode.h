//  AABBNODE.h
//  Header file for the AABBNODE class
//  Stores details for each bounding box used for collsion detection.  Each node is stored
//  in each link of the AABB Linked List

//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef AABBNODE_H
#define AABBNODE_H

#include <vector>
#include <freeglut.h>

//--------------------------------------------------------------------------------------
    /**
    @class AABBNode
    @brief Stores details for each bounding box used for collision detection.

    Each node is stored in each link of the AABB Linked List.

    @author Shay Leary
    @version 01
    @date MAR05

    @author Team CodeJunkies
    @version 02
    @date 05SEP16

    */
class AABBNode
{
public:
	AABBNode() { Clear(); }
	virtual ~AABBNode() { Clear(); }

	//----------------------------------------------------------------------------------

        /**
        @brief Resets the node data

        @return void
        */
	void  Clear();

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Returns the maximum X value for the node

        @return GLdouble
        */
	GLdouble GetMaxX() { return m_BBox.max.x; }

        /**
        @brief Returns the minimum X value for the node

        @return GLdouble
        */
	GLdouble GetMinX() { return m_BBox.min.x; }

        /**
        @brief Returns the maximum Y value for the node

        @return GLdouble
        */
	GLdouble GetMaxY() { return m_BBox.max.y; }

        /**
        @brief Returns the minimum Y value for the node

        @return GLdouble
        */
	GLdouble GetMinY() { return m_BBox.min.y; }

        /**
        @brief Returns the maximum Z value for the node

        @return GLdouble
        */
	GLdouble GetMaxZ() { return m_BBox.max.z; }

        /**
        @brief Returns the minimum Z value for the node

        @return GLdouble
        */
	GLdouble GetMinZ() { return m_BBox.min.z; }

        /**
        @brief Returns the address of the link to the next node in the list

        @return AABBNode
        */
	AABBNode *GetNext() const { return m_next; }

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Sets the data for the bounding box node

        @param maxX - The maximum X value for the node
        @param minX - The minimum X value for the node
        @param maxY - The maximum Y value for the node
        @param minY - The minimum Y value for the node
        @param maxZ - The maximum Z value for the node
        @param minZ - The minimum Z value for the node

        @return void
        */
	void SetData(const GLdouble maxX, const GLdouble minX,
		const GLdouble maxY, const GLdouble minY,
		const GLdouble maxZ, const GLdouble minZ);

        /**
        @brief Sets the address of the link to the next node in the list

        @param *next - The address of the link to the next node

        @return void
        */
	void SetNext(AABBNode *next) { m_next = next; }

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
	/// stores above info
	BoundingBox m_BBox;

	//----------------------------------------------------------------------------------

	// Privatised copy constructor and assignment operator
	AABBNode(const AABBNode &newNode) {};
	AABBNode &operator = (const AABBNode &newNode) {};
};

#endif
//--------------------------------------------------------------------------------------
