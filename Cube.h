
class Cube
{
    private:
        float cubeX;
        float cubeY;
        float rotAngle;
        int lastFrameTime;

    public:
        Cube();
        void MoveCube();
        void RotateCube();
        void TranslateCube(int key);
        void DrawCube();
};
