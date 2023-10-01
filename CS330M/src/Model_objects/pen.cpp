//
// Created by Dsk3 on 9/29/2023.
//


#include <Model_objects\pen.h>
#include <types.h>
#include <memory>
#include "material.h"
#include "glm/gtc/matrix_transform.hpp"

Pen::Pen() {
    createShaders();
    createMeshes();
}

void Pen::Init() {
}

void Pen::Update(float deltaTime) {
}

void Pen::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("mod6.vert"), Path("mod6.frag"));
    //_basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Pen::createMeshes() {
    auto pen = std::make_shared<Mesh>(Shapes::PenVertices, Shapes::PenElements);
    auto penMaterial = std::make_shared<Material>(_basicUnlitShader);
    pen->Transform = glm::translate(pen->Transform, glm::vec3(.0f, 1.10f, 4.0f));
    pen->Transform = glm::rotate(pen->Transform, glm::radians(280.0f), glm::vec3(.0f, 0.0f, 1.0f));
    pen->Transform = glm::scale(pen->Transform, glm::vec3(.85f, .85f, .85f));
    _models.emplace_back(pen, penMaterial);

}

void Pen::ProcessLighting(SceneParameters &sceneParams) {
    return;
}

