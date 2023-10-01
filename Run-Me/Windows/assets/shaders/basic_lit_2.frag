#version 330 core

struct DirLight {
    vec3 Position;
    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;

    float DiffuseIntensity;
    float SpecularIntensity;
    float AmbientIntensity;
};
struct PointLight {
    vec3 Position;

    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;

    float Constant;
    float Linear;
    float Quadratic;
};

struct MaterialProperties {
    float Roughness;
    float Shininess;
};

out vec4 FragColor;

in vec4 vertexColor;
in vec3 fragNormal;
in vec3 fragPosition;

in vec2 texCoord;

// These values will be used for textures in the future.
uniform sampler2D tex0;      // GL_TEXTURE0

uniform vec3 eyePos;
uniform MaterialProperties materialProperties;

#define MAX_POINT_LIGHTS 4
uniform PointLight pointLights[MAX_POINT_LIGHTS];

#define MAX_DIR_LIGHTS 4
uniform DirLight dirLights[MAX_DIR_LIGHTS];

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir) {
    vec3 ambient = light.AmbientIntensity * light.Ambient;

    vec3 lightDir = normalize(light.Position - fragPosition);

    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * light.Diffuse * light.DiffuseIntensity;

    vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), materialProperties.Roughness);
    vec3 specular = materialProperties.Shininess * spec * light.Specular;

    vec3 dirLightColor = (diffuse + specular + ambient);

    return dirLightColor;
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 viewDir) {
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * light.Ambient;

    // diffuse color
    vec3 lightDir = normalize(light.Position - fragPosition);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = diff * light.Diffuse;

    vec3 reflectDir = reflect(-lightDir, normal);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), materialProperties.Roughness);
    vec3 specular = materialProperties.Shininess * spec * light.Specular;

    float distance = length(light.Position - fragPosition);
    float attenuation = 1.0 / (light.Constant + (light.Linear * distance) + light.Quadratic * (distance * distance));

    return (diffuse + specular + ambient);
}

void main() {
    vec3 objectColor = vec3(vertexColor * texture(tex0, texCoord));

    vec3 norm = normalize(fragNormal);
    vec3 viewDir = normalize(eyePos - fragPosition);

    vec3 result = vec3(0,0,0);

    for (int i = 0; i < MAX_DIR_LIGHTS; i++) {
        result += CalcDirLight(dirLights[i], norm, viewDir);
    }

    for (int i = 0; i < MAX_POINT_LIGHTS; i++) {
        result += CalcPointLight(pointLights[i], norm, viewDir);
    }

    vec3 finalColor = result * objectColor;
    FragColor = vec4(finalColor, 1.0);
}