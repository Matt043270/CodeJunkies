#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
public:
	Camera();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetRoll(float roll);
	void SetPitch(float pitch);
	void SetYaw(float yaw);

	float GetX();
	float GetY();
	float GetZ();
	float GetRoll();
	float GetPitch();
	float GetYaw();

	void SetCameraPos(float x, float y, float z);
private:

private:
	float m_x, m_y, m_z;
	float m_roll, m_pitch, m_yaw;
};

#endif