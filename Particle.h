#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
    private:
            /// Lifetime of the particle
        float lifetime;
            /// decay speed of the particle
        float decay;
            /// color values of the particle
        float r,g,b;
            /// position of the particle
        float xpos,ypos,zpos;
            /// speed of the particle
        float xspeed,yspeed,zspeed;
            /// is particle active or not?
        bool active;

    public:
            /**
            @brief Constructor for a particle.
            **/
        void CreateParticle();
            /**
            @brief Evolves the particle parameters over time.
            This method changes the vertical and horizontal position of the particle, its, speed and decay time.
            **/
        void EvolveParticle();
            /**
            @brief Draws the particle on screen.
            Sets the colour mode.
            Sets the drawing primitive.
            Sets the coordinates of each point on the triangle strip
            **/
        void DrawObjects();

            /**
            @brief Getter and setter methods
            **/
        float GetXPos();
        void SetXPos(float xPos);
        void SetYPos(float yPos);
        float GetYPos();
        float GetG();
        void SetG(float myG);
};

#endif