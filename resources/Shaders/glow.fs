#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;

out vec4 finalColor;

void main()
{
    vec4 texColor = texture(texture0, fragTexCoord);
    finalColor = vec4(1.0, 0.0, 0.0, texColor.a); // Red color, preserving alpha
}
