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
uniform sampler2D basicTexture;  // Added

vec3 roomLight()
{
    vec3 sampledTexture = texture(basicTexture, texCoord).rgb;  // Sample the texture
    vec3 objectColor = vertexColor.xyz * sampledTexture;  // Modulate with vertexColor

    // Ambient lighting
    float LightBrightness = .9;
    vec3 ambient = LightBrightness * vec3(1.0f, 1.0f, 1.0f) * objectColor;

    // Diffuse lighting
    vec3 norm = normalize(vertexNormal);
    vec3 lightDir = normalize(vec3(.1f, 1.0f, 0.0f));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(0.96f, 0.95f, .95f) * objectColor;

    // Specular lighting
    float specularStrength = .8;
    vec3 viewDir = normalize(vec3(-5.f, 40.0f, -0.0f) - vertexPosition);

    vec3 reflectDir = reflect(-lightDir, norm);

    float shininess = 120.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * vec3(1.0f, 1.0f, 1.0f);

    vec3 finalColor = ambient + diffuse + specular;
    FragColor = vec4(finalColor, 1.0);

    return FragColor.rgb;
}


void main()
{
    vec3 roomLighting = roomLight();

    vec3 sampledTexture = texture(basicTexture, texCoord).rgb;  // Sample the texture
    vec3 objectColor = vertexColor.xyz * sampledTexture;  // Modulate with vertexColor

    // Ambient lighting
    float LightBrightness = .99;
    vec3 ambient = LightBrightness * vec3(1.0f, 1.0f, 1.0f) * objectColor;

    // Diffuse lighting
    vec3 norm = normalize(vertexNormal);
    vec3 lightDir = normalize(vec3(0.0f, 7.0f, -5.0f));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * vec3(0.96f, 0.95f, .95f) * objectColor;

    // Specular lighting
    float specularStrength = 0.85;
    vec3 viewDir = normalize(eyePos - vertexPosition);
    vec3 reflectDir = reflect(-lightDir, norm);

    float shininess = 120.0;
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * vec3(.6f, .6, .6f);

    vec3 finalColor = ambient + diffuse + specular;

    finalColor = finalColor * roomLighting;
    FragColor = vec4(finalColor, 1.0);
}
