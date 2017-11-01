#include "InputManager.h"

InputManager * InputManager::m_instance;

InputManager::InputManager()
{

}

void InputManager::Initialize()
{
	for (int i = 0; i < 550; i++)
	{
		m_keys[i] = IM_KEY_RELEASED;
	}
}

KeyState InputManager::GetKeyState(int key)
{
	if (m_keys[key] == IM_KEY_PRESSED)
	{
		m_keys[key] = IM_KEY_REPEAT;
		return IM_KEY_PRESSED;
	}
	return m_keys[key];
}

void InputManager::KeyCallback(int key, bool press)
{
	
	m_keys[key] = press ? IM_KEY_PRESSED : IM_KEY_RELEASED;
	std::cout << key << " - " << m_keys[key] << std::endl;
}
