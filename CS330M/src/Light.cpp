//
// Created by Dsk3 on 9/23/2023.
//

#include <Model_objects/Light.h>
#include <types.h>
#include <memory>
#include <iostream>
#include <mesh.h>
#include <shader.h>
#include <glm/gtc/matrix_transform.hpp>


Light::Light() {
    createShaders();
    createMeshes();
}

void Light::Init() {
}

void Light::Update(float deltaTime) {
}



void Light::createShaders() {
    Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";
    _basicUnlitShader = std::make_shared<Shader>(shaderPath / "basic_unlit_color.vert", shaderPath / "basic_unlit_color.frag");
}

void Light::createMeshes() {
    auto cube = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements);
    auto cubeMaterial = std::make_shared<Material>(_basicUnlitShader);
    _models.emplace_back(cube, cubeMaterial);
}
