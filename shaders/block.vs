#version 330 core
layout (location = 0) in vec3 aPos; // <vec2 position, int textureID>
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoords;
out vec3 vColor;
out float TextureID;
uniform mat4 projection;

void main()
{
    TexCoords = aTexCoord;
    vColor = aColor;
    TextureID = aPos.z;
    gl_Position = projection * vec4(aPos.xy, 0.0, 1.0);
}