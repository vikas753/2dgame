#include "game_object.h"
#include "resource_manager.h"
#include "game_level.h"


GameObject::GameObject(glm::vec2 pos,glm::vec2 size, uint32_t textureData, glm::vec3 color):
    Position(pos),
    Size(size),
    texture(textureData),
    color(color)
{
    // do thing
}

GameObject::GameObject(glm::vec2 pos,glm::vec2 size, uint32_t textureData):
    Position(pos),
    Size(size),
    texture(textureData)
{
    // do thing
}

int GameObject::setArrData(float* vertices,int index)
{

    vertices[index++] = (float)(Position.x); vertices[index++] = (float)(Position.y); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)0.0f; vertices[index++] = (float)1.0f;

    vertices[index++] = (float)(Position.x + Size.x); vertices[index++] = (float)(Position.y); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)1.0f; vertices[index++] = (float)0.0f;

    vertices[index++] = (float)(Position.x); vertices[index++] = (float)(Position.y + (Size.y)); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)1.0f; vertices[index++] = (float)1.0f;

    vertices[index++] = (float)(Position.x + (Size.x)); vertices[index++] = (float)(Position.y + (Size.y)); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)0.0f; vertices[index++] = (float)1.0f;

    vertices[index++] = (float)(Position.x); vertices[index++] = (float)(Position.y + (Size.y)); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)1.0f; vertices[index++] = (float)1.0f;

    vertices[index++] = (float)(Position.x + (Size.x)); vertices[index++] = (float)(Position.y); vertices[index++] = (float)texture;
    vertices[index++] = (float)color.x; vertices[index++] = (float)color.y; vertices[index++] = (float)color.z; vertices[index++] = (float)1.0f; vertices[index++] = (float)0.0f;

    return index;
}