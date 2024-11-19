#ifndef _GAME_LEVEL_H
#define _GAME_LEVEL_H

#include "game_object.h"
#include "basic_renderer.h"

class GameLevel
{
public:
    // level state
    std::vector<GameObject> Bricks;
    // constructor
    GameLevel() { }
    // loads level from file
    void Load(const char *file, unsigned int levelWidth, unsigned int levelHeight);
    // render level
    void Draw(glm::vec2 position, glm::vec2 size, float rotate);
    // check if the level is completed (all non-solid tiles are destroyed)
    bool IsCompleted();

protected:
    uint32_t quadVAO;
    uint32_t VBO;
    uint32_t lvlWidth;
    uint32_t lvlHeight;
    float vertices[144000];

private:
    // initialize level from tile data
    void init(std::vector<std::vector<unsigned int>> tileData, 
              unsigned int levelWidth, unsigned int levelHeight);
    Shader       shader;
};

#endif // _GAME_LEVEL_H