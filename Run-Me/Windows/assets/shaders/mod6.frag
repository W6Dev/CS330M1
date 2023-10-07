#version 330 core

in vec4 vertexColor;
in vec3 vertexNormal;
in vec3 vertexPosition;

out vec4 FragColor;

uniform vec3 eyePos;

void main() {
    vec3 objectColor = vertexColor.rgb;

    float LightBrightness = .35;
    vec3 ambient = LightBrightness * objectColor;

    // Diffuse lighting
    vec3 norm = normalize(vertexNormal);
    vec3 lightDir = normalize(vec3(0.0f, 10.0f, -10.0f));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(0.96f, 0.95f, .95f) * objectColor;

    // Specular lighting
    float specularStrength = .45;
    vec3 viewDir = normalize(eyePos - vertexPosition);
    vec3 reflectDir = reflect(-lightDir, norm);
    float shininess = 180.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * vec3(.9f, .9, .7f);

    vec3 finalColor = ambient + diffuse + specular;

    FragColor = vec4(finalColor, 1.0);
}














