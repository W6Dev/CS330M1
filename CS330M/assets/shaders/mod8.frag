#version 330 core

in vec4 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPosition;
in vec2 texCoord;  // Added

out vec4 FragColor;

struct DirectionalLight {
    vec3 ambient ;
    vec3 diffuse;
    vec3 specular;
    vec3 direction;
};


uniform DirectionalLight dirLight;
uniform vec3 eyePos;
uniform mat4 lightPos;


void main()
{
    vec3 objectColor = vec3(vertexColor);

    // Ambient lighting
    float LightBrightness = .3;
    vec3 ambient = LightBrightness  * objectColor;

    // Diffuse lighting
    vec3 norm = normalize(vertexNormal);
    vec3 lightDir = normalize(vec3(0.0f, 7.0f, -5.0f));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(0.96f, 0.95f, .95f);



    vec3 finalColor = (ambient + diffuse) * objectColor;


    FragColor = vec4(finalColor, 1.0);
}















