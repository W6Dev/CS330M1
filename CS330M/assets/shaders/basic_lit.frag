#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
in vec2 texCoord;


uniform sampler2D tex;

void main()
{
    float amientStrength = 0.1;
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec3 ambient = amientStrength * lightColor;

    vec3 objectColor = vertexColor.xyz;

    vec3 finilColor = ambient * objectColor;

    FragColor = vec4(finilColor, 1.0);


}