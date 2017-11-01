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

	void Initialize();

	KeyState GetKeyState(int key);

	void KeyCallback(int key, bool press);

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