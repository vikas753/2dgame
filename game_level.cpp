#include "resource_manager.h"
#include "game.h"
#include "game_object.h"
#include "game_level.h"
#include <fstream>
#include <sstream>
#include <iostream>

void GameLevel::Load(const char *file, unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->Bricks.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;
    std::ifstream fstream(file);
    std::vector<std::vector<unsigned int>> tileData;
    if (fstream)
    {
        while (std::getline(fstream, line)) // read each line from level file
        {
            std::istringstream sstream(line);
            std::vector<unsigned int> row;
            while (sstream >> tileCode) // read each word separated by spaces
                row.push_back(tileCode);
            tileData.push_back(row);
        }
        if (tileData.size() > 0)
            this->init(tileData, levelWidth, levelHeight);
    }
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, 
                     unsigned int lvlWidth, unsigned int lvlHeight)
{

    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(lvlWidth), 
        static_cast<float>(2*lvlHeight), 0.0f, -1.0f, 1.0f);
    // set render-specific controls
    this->shader = ResourceManager::GetShader("block");

    this->shader.SetMatrix4("projection", projection);
    this->lvlWidth = lvlWidth;
    this->lvlHeight = lvlHeight;

    // calculate dimensions
    unsigned int height = tileData.size();
    unsigned int width  = tileData[0].size();
    float unit_width    = lvlWidth / static_cast<float>(width);
    float unit_height   = lvlHeight / height;
    // initialize level tiles based on tileData		
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            // check block type from level data (2D level array)
            if (tileData[y][x] == 1) // solid
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                GameObject obj(pos, size, 
                    1, 
                    glm::vec3(0.8f, 0.8f, 0.7f)
                );
                obj.isSolid = true;
                this->Bricks.push_back(obj);
            }
            else if (tileData[y][x] > 1)	
            {
                glm::vec3 color = glm::vec3(1.0f); // original: white
                if (tileData[y][x] == 2)
                    color = glm::vec3(0.2f, 0.6f, 1.0f);
                else if (tileData[y][x] == 3)
                    color = glm::vec3(0.0f, 0.7f, 0.0f);
                else if (tileData[y][x] == 4)
                    color = glm::vec3(0.8f, 0.8f, 0.4f);
                else if (tileData[y][x] == 5)
                    color = glm::vec3(1.0f, 0.5f, 0.0f);

                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                this->Bricks.push_back(
                    GameObject(pos, size, 0, color)
                );
            }
        }
    }  
}

void GameLevel::Draw(glm::vec2 position, glm::vec2 size, float rotate)
{
    auto total_vertices = 0;
    int index = 0;
    for(auto gameObject : this->Bricks)
    {
        int num_vertices = 0;
        index = gameObject.setArrData((float*)&vertices[0],index);
    }
    total_vertices = index;

    #ifdef VERTEX_DEBUG
    std::cout << " Size of vetex vector : " << total_vertices * sizeof(float) << std::endl;

    for(int i=0;i<total_vertices;i++)
    {
        std::cout << vertices[i] << ",";
    }
    #endif

    this->shader.Use();

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &this->VBO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, total_vertices * sizeof(float), (void*)&vertices[0], GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));


    glActiveTexture(GL_TEXTURE0 + ResourceManager::GetTexture("block_solid").ID);
    ResourceManager::GetTexture("block_solid").Bind();
    glActiveTexture(GL_TEXTURE0 + ResourceManager::GetTexture("block").ID);
    ResourceManager::GetTexture("block").Bind();

    glBindVertexArray(this->quadVAO);

    glDrawArrays(GL_TRIANGLES, 0, (total_vertices/8));

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
    // Unbind the arrays immediately as GPU already knows format etc..,
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
