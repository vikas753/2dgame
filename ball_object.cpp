#include "ball_object.h"

BallObject::BallObject(glm::vec2 pos, float radius, glm::vec2 velocity, Texture2D sprite):
    Velocity(velocity),
    Stuck(true),
    GameObject(pos, glm::vec2(radius, radius), sprite)
{
    // do thing
}

glm::vec2 BallObject::Move(float dt, unsigned int window_width)
{
    // if not stuck to player board
    if (!this->Stuck)
    { 
        // move the ball
        this->Position += this->Velocity * dt;
        // check if outside window bounds; if so, reverse velocity and restore at correct position
        if (this->Position.x <= 0.0f)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = 0.0f;
        }
        else if (this->Position.x + this->Size.x >= window_width)
        {
            this->Velocity.x = -this->Velocity.x;
            this->Position.x = window_width - this->Size.x;
        }
        if (this->Position.y <= 0.0f)
        {
            this->Velocity.y = -this->Velocity.y;
            this->Position.y = 0.0f;
        }
      
    }
    return this->Position;
}  