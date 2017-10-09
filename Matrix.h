class Matrix
{
public:
	Matrix();
	Matrix Identity();
	Matrix RotateX(float theta);
	Matrix RotateY(float theta);
	Matrix RotateZ(float theta);
	Matrix Scale(float x, float y, float z);
	Matrix Translate(float x, float y, float z);
	Matrix SetOrtho(float left, float right, float bottom, float top, float nearVal, float farVal);
	Matrix SetFrustrum(float left, float right, float bottom, float top, float nearVal, float farVal);
	Matrix SetPerspective(float fovY, float aspect, float front, float back);
	Matrix Viewing(float eyeX, float eyeY, float eyeZ, float centreX, float centreY, float centreZ, float upX, float upY, float upZ);
	Matrix operator*(Matrix input);
	void Set(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
	float arr[16];
};

