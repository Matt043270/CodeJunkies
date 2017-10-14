/**
 * @class InputManager
 *
 * @version 1
 */

//--------------------------------------------------------------------------------------

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

//--------------------------------------------------------------------------------------

#include <freeglut.h>

class InputManager
{
	private:
	
			/// Amount to rotate on the x-axis
		float imXrot; 
			/// Amount to rotate on the y-axis
		float imYrot; 
			/// Value of the difference between the current and last x position
		int imDiffx; 
			/// Value of the difference between the current and last y position
		int imDiffy; 
			/// Maximum camera vertical angle
		float imMaxAngle; 
			/// Minimum camera vertical angle
		float imMinAngle; 
			/// Last mouse x-position
		float imLastx; 
			/// Last mouse y-position*/
		float imLasty; 
			/// Flag for whether or not the mouse button is clicked (true = mouse clicked, false = mouse not clicked
		bool imMouseClicked; 
			/// Tracks the states of keyboard keys (true = key pressed, false = key not pressed)
		bool imKeyStates[256]; 
			/// Tracks the states of special arrow keys (true = key pressed, false = key not pressed)
		bool imSpecialKeyStates[4]; 
		

			/**
             * @brief Handles all key presses.
             *
			 * Handles all key presses by tracking their current state and 
			 * taking the appropriate action if the key is currently in the 
			 * down position.
			 *
             * @param none
			 * @return void
             */
		void KeyOperations(void);


	public:
			/**
             * @brief Default constructor creates a new camera object
			 *
			 * @param none
             */
		InputManager();

			/**
             * @brief Function to be passed as glutSpecialFunc()
			 *
			 * @param int key - the key that was pressed
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void SpecialKey(int key, int x, int y);

			/**
             * @brief Function to be passed as glutSpecialUpFunc()
			 *
			 * @param int key - the key that was released
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void SpecialKeyUp(int key, int x, int y);

			/**
             * @brief Function to be passed as glutKeyboardFunc()
			 *
			 * @param unsigned char key - the key that was pressed
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void Keyboard(unsigned char key, int x, int y);

			/**
             * @brief Function to be passed as glutKeyboardUpFunc()
			 *
			 * @param unsigned char key - the key that was released
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void KeyboardUp(unsigned char key, int x, int y);

			/**
             * @brief Function to be passed as glutMouseFunc()
			 *
			 * @param int button - the mouse button clicked
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void Mouse(int button, int state, int x, int y);

			/**
             * @brief Function to be passed as glutMotionFunc()
			 *
			 * @param int x - the mouse x position
			 * @param int y - the mouse y position
			 * @return void
             */
		void MouseMotion(int x, int y);
			
};
#endif //end of InputManager class
