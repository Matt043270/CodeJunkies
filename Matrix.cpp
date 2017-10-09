#include "Matrix.h"
#include "Math.h"

#define PI (3.1415926535897932384626433832795)
const float DEG2RAD = PI / 180;


Matrix::Matrix()
{
	float arr[16] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
}

Matrix Matrix::Identity()
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

	temp.arr[0] = temp.arr[5] = temp.arr[10] = temp.arr[15] = 1.0;

	return temp;
}

Matrix Matrix::RotateX(float theta)
{
	float sine = sin(theta);
	float cosine = cos(theta);

	Matrix temp = Identity();

	temp.arr[5] = cosine;
	temp.arr[9] = -sine;
	temp.arr[6] = sine;
	temp.arr[10] = cosine;

	return temp;
}

Matrix Matrix::RotateY(float theta)
{
	float sine = sin(theta);
	float cosine = cos(theta);

	Matrix temp = Identity();

	arr[0] = cosine;
	arr[8] = sine;
	arr[2] = -sine;
	arr[10] = cosine;

	return temp;
}

Matrix Matrix::RotateZ(float theta)
{
	float sine = sin(theta);
	float cosine = cos(theta);
	
	Matrix temp = Identity();

	temp.arr[0] = cosine;
	temp.arr[4] = -sine;
	temp.arr[1] = sine;
	temp.arr[5] = cosine;

	return temp;
}

Matrix Matrix::Scale(float x, float y, float z)
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

	temp.arr[0] = x;
	temp.arr[5] = y;
	temp.arr[10] = z;
	temp.arr[15] = 1.0;

	return temp;
}

Matrix Matrix::Translate(float x, float y, float z)
{
	Matrix temp = Identity();

	arr[12] = x;
	arr[13] = y;
	arr[14] = z;

	return temp;
}

Matrix Matrix::SetOrtho(float left, float right, float bottom, float top, float nearVal, float farVal)
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);


	temp.arr[0] = 2.0 / (right - left);
	temp.arr[5] = 2.0 / (top - bottom);
	temp.arr[10] = -2.0 / (farVal - nearVal);
	temp.arr[15] = 1.0;
	temp.arr[12] = -(right + left) / (right - left);
	temp.arr[13] = -(top + bottom) / (top - bottom);
	temp.arr[14] = -(farVal + nearVal) / (farVal - nearVal);

	return temp;
}

Matrix Matrix::SetFrustrum(float left, float right, float bottom, float top, float nearVal, float farVal)
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);


	temp.arr[0] = 2.0 * nearVal / (right - left);
	temp.arr[5] = 2.0 * nearVal / (top - bottom);
	temp.arr[8] = (right + left) / (right - left);
	temp.arr[9] = (top + bottom) / (top - bottom);
	temp.arr[10] = -(farVal + nearVal) / (farVal - nearVal);
	temp.arr[11] = -1.0;
	temp.arr[14] = -(2.0 * farVal * nearVal) / (farVal - nearVal);

	return temp;
}

Matrix Matrix::SetPerspective(float fovY, float aspect, float front, float back)
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

	float tangent = tanf(fovY / 2 * DEG2RAD);
	float height = front * tangent;
	float width = height * aspect;

	temp = SetFrustrum(-width, width, -height, height, front, back);

	return temp;
}

Matrix Matrix::Viewing(float eyeX, float eyeY, float eyeZ, float centreX, float centreY, float centreZ, float upX, float upY, float upZ)
{
	Matrix temp;
	temp.Set(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);


	float up[] = { upX, upY, upZ };
	float forward[] = {centreX - eyeX, centreY - eyeY, centreZ - eyeZ};

	float length = sqrt(forward[0] * forward[0] + forward[1] * forward[1] + forward[2] * forward[2]);
	forward[0] /= length;
	forward[1] /= length;
	forward[2] /= length;

	float right[] = { forward[1] * up[2] - forward[2] * up[1], forward[2] * up[0] - forward[0] * up[2], forward[0] * up[1] - forward[1] * up[0]};
	length = sqrt(right[0] * right[0] + right[1] * right[1] + right[2] * right[2]);
	right[0] /= length;
	right[1] /= length;
	right[2] /= length;

	up[0] = right[1] * forward[2] - right[2] * forward[1];
	up[1] = right[2] * forward[0] - right[0] * forward[2];
	up[2] = right[0] * forward[1] - right[1] * forward[0];

	temp.arr[0] = right[0];
	temp.arr[4] = right[1];
	temp.arr[8] = right[2];
	temp.arr[1] = up[0];
	temp.arr[5] = up[1];
	temp.arr[9] = up[2];
	temp.arr[2] = -forward[0];
	temp.arr[6] = -forward[1];
	temp.arr[10] = -forward[2];
	temp.arr[15] = 1.0;

	return temp;
}

Matrix Matrix::operator*(Matrix input)
{
	Matrix temp;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0 ; j < 4; j++)
		{
			temp.arr[j * 4 + i] = 0.0;
			for (int k = 0; k < 4; k++)
			{
				temp.arr[j * 4 + i] += (*this).arr[k * 4 + i] * input.arr[j * 4 + k];
			}
		}
	}

	return temp;
}

void Matrix::Set(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p)
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	arr[4] = e;
	arr[5] = f;
	arr[6] = g;
	arr[7] = h;
	arr[8] = i;
	arr[9] = j;
	arr[10] = k;
	arr[11] = l;
	arr[12] = m;
	arr[13] = n;
	arr[14] = o;
	arr[15] = p;
}
