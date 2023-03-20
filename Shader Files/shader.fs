#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D texture2;

vec2 TexCoordHorizontalFlip = vec2(-TexCoord.x, TexCoord.y);

void main()
{
    FragColor = mix(texture(ourTexture, TexCoord), texture(texture2, TexCoordHorizontalFlip), 0.2);
}
