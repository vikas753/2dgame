#version 330 core
in vec2 TexCoords;
in vec3 vColor;
in float TextureID;

uniform sampler2D texture_block;
uniform sampler2D texture_block_solid;
uniform float textureBaseId;
out vec4 color;

void main()
{
    color = vec4(vColor.x, vColor.y ,vColor.z, 1.0f) * mix(texture(texture_block, TexCoords) , texture(texture_block_solid, TexCoords) , (TextureID - textureBaseId));
}