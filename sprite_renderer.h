#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "shader_class.h"
#include "resource_manager.h"

class SpriteRenderer
{
    public:
        SpriteRenderer(const Shader &shader);
        ~SpriteRenderer();

        void DrawSprite(const Texture2D &texture, glm::vec2 position, 
            glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, 
            glm::vec3 color = glm::vec3(1.0f));
    private:
        Shader       shader; 
        unsigned int quadVAO;

        void initRenderData();
};

#endif // SPRITE_RENDERER_H