//
// Created by Dsk3 on 9/23/2023.
//

#include <Model_objects/Light.h>
#include <types.h>
#include <memory>
#include <material.h>
#include "glm/gtc/matrix_transform.hpp"


Light::Light() {
    createShaders();
    createMeshes();
}

void Light::Init() {
}

void Light::Update(float deltaTime) {
}


void Light::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Light::createMeshes() {
    auto cube = std::make_shared<Mesh>(Shapes::cubeVertices, Shapes::cubeElements);
    auto cubeMaterial = std::make_shared<Material>(_basicUnlitShader);
    _models.emplace_back(cube, cubeMaterial);

}
