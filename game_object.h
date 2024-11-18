#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "texture_class.h"
#include <vector>


class GameObject {
    public:
        void clear();
        GameObject(glm::vec2 pos,glm::vec2 size, uint32_t textureData, glm::vec3 color);
        GameObject(glm::vec2 pos,glm::vec2 size, uint32_t textureData);
        int setArrData(float* vertices,int index);
        glm::vec2 Position;
        glm::vec2 Size;
        glm::vec3 color;
        uint32_t texture;
        bool isSolid;
};

#endif // _GAME_OBJECT_H