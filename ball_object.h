#ifndef _BALL_OBJECT_H
#define _BALL_OBJECT_H

#include "game_object.h"

class BallObject : public GameObject
{
    public:
        // ball state	
        float     Radius;
        bool      Stuck;
        glm::vec2 Velocity;

        BallObject();
        BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite);

        glm::vec2 Move(float dt, unsigned int window_width);
        void      Reset(glm::vec2 position, glm::vec2 velocity);
}; 

#endif