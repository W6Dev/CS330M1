//
// Created by Dsk3 on 9/29/2023.
//

#include <Model_objects\Coffee.h>
#include <types.h>
#include <memory>
#include <material.h>
#include "glm/gtc/matrix_transform.hpp"


Coffee::Coffee() {
    createShaders();
    createMeshes();
}

void Coffee::Init() {
}

void Coffee::Update(float deltaTime) {
}


void Coffee::createShaders() {
    //_basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
    _basicUnlitShader = std::make_shared<Shader>(Path("mod6.vert"), Path("mod6.frag"));
}

void Coffee::createMeshes() {

    auto cupMaterial = std::make_shared<Material>(_basicUnlitShader);

    // Cup
    //7.0, 0.0f, 0.0f)
    auto [ConeVertices, ConeElements] = GenerateCone();
    auto cup = std::make_shared<Mesh>(ConeVertices, ConeElements);
    cup->Transform = glm::translate(cup->Transform, glm::vec3(0.0, 0.0f, 0.0f));
    cup->Transform = glm::rotate(cup->Transform, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    cup->Transform = glm::scale(cup->Transform, glm::vec3(.85f, .85f, .85f));
    _models.emplace_back(cup, cupMaterial);

    // handle
    // 8.9f, 1.20f, 0.0f)
    auto [TorusVertices, TorusElements] = GenerateTorus();
    auto handle = std::make_shared<Mesh>(TorusVertices, TorusElements);
    handle->Transform = glm::translate(handle->Transform, glm::vec3(1.9f, 1.20f, 0.0f));
    handle->Transform = glm::rotate(handle->Transform, glm::radians(0.f), glm::vec3(1.0f, 0.0f, 0.0f));
    handle->Transform = glm::scale(handle->Transform, glm::vec3(.85f, .85f, .85f));
    _models.emplace_back(handle, cupMaterial);
}

