//
// Created by Dsk3 on 9/23/2023.
//

#include <Model_objects/plane.h>
#include <types.h>
#include <memory>
#include <material.h>
#include "glm/gtc/matrix_transform.hpp"

Plane::Plane() {
    createShaders();
    createMeshes();
}

void Plane::Init() {
}

void Plane::Update(float deltaTime) {
}
void Plane::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("mod6.vert"), Path("mod6.frag"));
}

void Plane::createMeshes() {
    auto plane = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements, glm::vec3{.72f, .78f, .71f});
    plane->Transform = glm::rotate(plane->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    //plane->Transform = glm::scale(plane->Transform, glm::vec3(1.0f, 1.0f, 1.0f));
    auto planeMaterial = std::make_shared<Material>(_basicUnlitShader);
    _models.emplace_back(plane, planeMaterial);
}