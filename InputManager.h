#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <iostream>

enum KeyState
{
	IM_KEY_PRESSED,
	IM_KEY_RELEASED,
	IM_KEY_REPEAT
};

class InputManager
{
private:
	InputManager();
	static InputManager * m_instance;
public:

		/**
		 * Initializes the input manager for use.
		 */
	void Initialize();

		/**
		 * Returns the key state of the given key
		 * @param[in] The key to check
		 * @retval KeyState The state of the key
		 */
	KeyState GetKeyState(int key);

		/**
		 * The key callback that sets the values of the input manager
		 * @param[in] key THe key that changed states
		 * @param[in] press If the key was pressed or not
		 */
	void KeyCallback(int key, bool press);

		/**
		 * Returns a pointer to the instance of the input manager, a singleton class.
		 * @retval InputManager* THe pointer of the InputManager.
		 */
	static InputManager * GetInstance()
	{
		if (!m_instance)
		{
			m_instance = new InputManager;
		}
		return m_instance;
	}
private:
	KeyState m_keys[550];
};


#endif