#include "Camera.h"

Camera::Camera()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_pitch = 0;
	m_roll = 0;
	m_yaw = 0;
}

void Camera::SetX(float x)
{
	m_x = x;
}

void Camera::SetY(float y)
{
	m_y = y;
}

void Camera::SetZ(float z)
{
	m_z = z;
}

void Camera::SetPitch(float pitch)
{
	m_pitch = pitch;
}

void Camera::SetRoll(float roll)
{
	m_roll = roll;
}

void Camera::SetYaw(float yaw)
{
	m_yaw = yaw;
}

void Camera::SetCameraPos(float x, float y, float z)
{
	SetX(x);
	SetY(y);
	SetZ(z);
}

float Camera::GetX()
{
	return m_x;
}

float Camera::GetY()
{
	return m_y;
}

float Camera::GetZ()
{
	return m_z;
}

float Camera::GetPitch()
{
	return m_pitch;
}

float Camera::GetYaw()
{
	return m_yaw;
}

float Camera::GetRoll()
{
	return m_roll;
}