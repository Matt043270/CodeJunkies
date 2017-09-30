//  camera.h
//  Header file for the camera class
//	Allows the camera to be navigated around the world.
//	Also sets Plains, Bounding Boxes and view Maps
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------
#ifndef CAMERA_H
#define CAMERA_H

#define PI 3.1415962654

#include "collision.h"
#include "cameraMap.h"
#include "PlainLinkedList.h"
#include "EasySound.h"

//--------------------------------------------------------------------------------------
    /**
    @class Camera
    @brief Allows the camera to be navigated around the world.

    Also sets the planes, bounding boxes and view maps

    @author Shay Leary
    @version 01
    @date MAR05

    @author Team CodeJunkies
    @version 02
    @date 05SEP17, added doxygen comments

    */
class Camera
{
public:

	Camera();
	virtual ~Camera() { es->Unload(stepSound); }

	//----------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------
	//  Set Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Sets the initial maximum X value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempX - The maximum X value for the bounding box

        @return void
        */
	void SetAABBMaxX(const int & tempIndex, const GLdouble &tempX) { m_colDetect.SetAABBMaxX(tempIndex, tempX); }

        /**
        @brief Sets the initial minimum X value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempX - The minimum X value for the bounding box

        @return void
        */
	void SetAABBMinX(const int & tempIndex, const GLdouble &tempX) { m_colDetect.SetAABBMinX(tempIndex, tempX); }

        /**
        @brief Sets the initial maximum Y value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempY - The maximum Y value for the bounding box

        @return void
        */
	void SetAABBMaxY(const int & tempIndex, const GLdouble &tempY) { m_colDetect.SetAABBMaxY(tempIndex, tempY); }

        /**
        @brief Sets the initial minimum Y value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempY - The minimum Y value for the bounding box

        @return void
        */
	void SetAABBMinY(const int & tempIndex, const GLdouble &tempY) { m_colDetect.SetAABBMinY(tempIndex, tempY); }

        /**
        @brief Sets the initial maximum Z value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempZ - The maximum Z value for the bounding box

        @return void
        */
	void SetAABBMaxZ(const int & tempIndex, const GLdouble &tempZ) { m_colDetect.SetAABBMaxZ(tempIndex, tempZ); }

        /**
        @brief Sets the initial minimum Z value for the bounding box.

        @param tempIndex - The index number for the bounding box
        @param tempZ - The minimum Z value for the bounding box

        @return void
        */
	void SetAABBMinZ(const int & tempIndex, const GLdouble &tempZ) { m_colDetect.SetAABBMinZ(tempIndex, tempZ); }


        /**
        @brief Sets the rotate speed of the camera.

        @param tempSpeed - The speed of the camera rotation

        @return void
        */
	void SetRotateSpeed(const GLdouble &tempSpeed) { m_rotateSpeed = tempSpeed; }

        /**
        @brief Sets the move speed of the camera.

        @param tempSpeed - The speed of the camera movement

        @return void
        */
	void SetMoveSpeed(const GLdouble &tempSpeed) { m_moveSpeed = tempSpeed; }

	// COLLSION DETECTION FUNCTIONS

        /**
        @brief Sets collision detection

        @param tempCol - sets collision to true or false

        @return void
        */
	void SetCollisionDetectionOn(const bool &tempCol) { m_CollisionDetectionOn = tempCol; }

        /**
        @brief Sets the number of bounding boxes

        @param tempSize - the number of bounding boxes

        @return void
        */
	void SetNoBoundingBoxes(const int & tempSize) { m_colDetect.SetNoBoundingBoxes(tempSize); }

	/**
        @brief Sets the co-orddinates of the world

        @param tempX - Sets the size of the world on the X axis
        @param tempZ - Sets the size pf the world on the Z axis

        @return void
        */
	void SetWorldCoordinates(const GLdouble &tempX, const GLdouble &tempZ);

        /**
        @brief Initiates bounding boxes for the world

        Creates a linked list for each quadrant of the world and places the bounding box
        data in each, then clears and deletes AABB array.

        @return void
        */
	void InitiateBoundingBoxes() { m_colDetect.CreateLinkedList(); }

	// sets the co-ordinate of each plain
        /**
        @brief Sets the coordinates for each plane

        @param tempType - The type of plane (0 - Flat plane, 1 - Angled Z to Y, 2 - Angled X to Y)
        @param tempXs - The start value on the X axis
        @param tempXe - The end value on the X axis
        @param tempYs - The start value on the Y axis
        @param tempYe - The end value on the Y axis
        @param tempZs - The start value on the Z axis
        @param tempZe - The end value on the Z axis

        @return void
        */
	void SetPlains(const int tempType,
		const GLdouble tempXs, const GLdouble tempXe,
		const GLdouble tempYs, const GLdouble tempYe,
		const GLdouble tempZs, const GLdouble tempZe);

	//----------------------------------------------------------------------------------
	//  Get Methods
	//----------------------------------------------------------------------------------

        /**
        @brief Returns the camera's X value

        @return GLdouble
        */
	GLdouble GetLR() { return m_x; }

        /**
        @brief Returns the camera's Y value

        @return GLdouble
        */
	GLdouble GetUD() { return m_y; }

        /**
        @brief Returns the camera's Z value

        @return GLdouble
        */
	GLdouble GetFB() { return m_z; }

        /**
        @brief Returns the maximum X value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMaxX(const int & tempIndex) { return m_colDetect.GetAABBMaxX(tempIndex); }

        /**
        @brief Returns the minimum X value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMinX(const int & tempIndex) { return m_colDetect.GetAABBMinX(tempIndex); }

        /**
        @brief Returns the maximum Y value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMaxY(const int & tempIndex) { return m_colDetect.GetAABBMaxY(tempIndex); }

        /**
        @brief Returns the minimum Y value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMinY(const int & tempIndex) { return m_colDetect.GetAABBMinY(tempIndex); }

        /**
        @brief Returns the maximum Z value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMaxZ(const int & tempIndex) { return m_colDetect.GetAABBMaxZ(tempIndex); }

        /**
        @brief Returns the minimum Z value of the bounding box

        @param tempIndex - The index reference of the bounding box

        @return GLdouble
        */
	GLdouble GetAABBMinZ(const int & tempIndex) { return m_colDetect.GetAABBMinZ(tempIndex); }

        /**
        @brief Sets the position of the camera

        @param tempX - The X value of the camera
        @param tempY - The Y value of the camera
        @param tempZ - The Z value of the camera
        @param tempAngle - The angle of the camera viewing

        @return void
        */
	void Position(GLdouble const & tempX,
		GLdouble const & tempY,
		GLdouble const & tempZ,
		GLdouble const & tempAngle);

        /**
        @brief Checks whether the camera is working

        @return void
        */
	void CheckCamera();

        /**
        @brief Moves the camera along the Z axis

        @param tempMove - The amount to move the camera

        @return void
        */
	void DirectionFB(int const & tempMove);

        /**
        @brief Moves the camera along the X axis

        @param tempMove - The amount to move the camera

        @return void
        */
	void DirectionLR(int const & tempMove);

        /**
        @brief Moves the camera along the Y axis

        @param tempMove - The amount to move the camera

        @return void
        */
	void DirectionUD(int const & tempMove);

        /**
        @brief Rotates the camera horizontally

        @param tempMove - The amount to rotate the camera

        @return void
        */
	void DirectionRotateLR(GLdouble const & tempMove);

        /**
        @brief Rotates the camera vertically

        @param tempMove - The amount to rotate the camera

        @return void
        */
	void DirectionLookUD(int const & tempMove);

        /**
        @brief Displays the map

        @param screenWidth - The width of the map
        @param screenHeight - The height of the map
        @param tempImage - The image to display

        @return void
        */
	void DisplayMap(const int & screenWidth, const int & screenHeight,
		const GLuint & tempImage);

        /**
        @brief Displays the welcome or exit screen

        @param screenWidth - The width of the welcome screen
        @param screenHeight - The height of the welcome screen
        @param tempExit - Determine if welcome or exit screen to be displayed
        @param tempImage - The image to be displayed

        @return void
        */
	void DisplayWelcomeScreen(const int & screenWidth, const int & screenHeight,
		const int & tempExit, const GLuint & tempImage);

        /**
        @brief Displays the "Area not modelled" notice

        @param screenWidth - The width of the display
        @param screenHeight - The height of the display
        @param tempImage - The image to be displayed

        @return void
        */
	void DisplayNoExit(const int & screenWidth, const int & screenHeight,
		const GLuint & tempImage);

private:

	///steep incline increments
	GLdouble m_incrementX;
	GLdouble m_incrementZ;
	int m_No_Plains;
	int m_plainNo;
	GLdouble m_plainHeight;

	/// rotation variables
	GLdouble m_rotateAngleLR;
	GLdouble m_deltaAngleLR;
	GLdouble m_rotateAngleUD;
	GLdouble m_deltaAngleUD;

	/// movement variables
	GLdouble m_x, m_y, m_z, m_zLast, m_xLast;
	GLdouble m_lookX, m_lookY, m_lookZ;
	GLdouble m_lookXX, m_lookYY, m_lookZZ;
	GLdouble m_deltaMoveLR;
	GLdouble m_deltaMoveFB;
	GLdouble m_deltaMoveUD;
	GLdouble m_direction;

	/// movement speed (step size)
	GLdouble m_rotateSpeed;
	GLdouble m_moveSpeed;

        /**
        @brief Check whether the camera is able to move along the X axis

        @return bool
        */
	bool MoveFBOK();

        /**
        @brief Check whether the camera is able to move along the Z axis

        @return bool
        */
	bool MoveLROK();

        /**
        @brief Check whether the camera is able to move along the Y axis

        @return bool
        */
	bool MoveUDOK();

        /**
        @brief Check whether the camera is able to rotate horizontally

        @return bool
        */
	bool RotateLROK();

        /**
        @brief Check whether the camera is able to rotate vertically

        @return bool
        */
	bool LookUDOK();

        /**
        @brief Move the camera along the X axis

        @return void
        */
	void MoveFB();

        /**
        @brief Move the camera along the Z axis

        @return void
        */
	void MoveLR();

        /**
        @brief Move the camera along the Y axis

        @return void
        */
	void MoveUD();

        /**
        @brief Rotate the camera horiontally

        @return void
        */
	void RotateLR();

        /**
        @brief Rotate the camera vertically

        @return void
        */
	void LookUD();

        /**
        @brief Overloaded function for setting plane

        @param moveX - The amount to move along the X axis
        @param moveZ - The amount to move along the Z axis

        @return void
        */
	void SetPlains(const int & moveX, const int & moveZ);

        /**
        @brief Resets the camera

        @return void
        */
	void ResetXYZ();

        /**
        @brief Displays the new camera view

        @return void
        */
	void callGLLookAt();

	bool m_CollisionDetectionOn;

	/// objects
	Collision m_colDetect;
	CameraMap m_map;
	PlainLinkedList m_Plain;

	// These functions were set up to climb stairs, but are not used.
	// The Plain object is used instead
	void ClimbSteps(GLdouble stepStart, GLdouble stepFinish, GLdouble stepHeight, GLdouble stepWidth, int noSteps);
	void CheckSteps();

	CEasySound *es;
	CSound* stepSound;

	//----------------------------------------------------------------------------------

	// Privatised copy constructor and assignment operator
	Camera(const Camera &cam) {};
	Camera &operator = (const Camera &cam) {};
};

#endif
