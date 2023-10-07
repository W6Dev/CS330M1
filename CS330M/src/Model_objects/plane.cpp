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
    createBackPlane();
}
void Plane::Init() {
}

void Plane::Update(float deltaTime) {
}

void Plane::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("mod7.vert"), Path("mod7.frag"));

}

void Plane::createMeshes() {
    auto Plane = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements, glm::vec3{.45f, .45f, .45f});
    Plane->Transform = glm::rotate(Plane->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    //Plane->Transform = glm::scale(Plane->Transform, glm::vec3(1.0f, 1.0f, 1.0f));
    auto PlaneMaterial = std::make_shared<Material>(_basicUnlitShader);


    PlaneMaterial->AddTexture(std::make_shared<Texture>(Path("Steel.jpg"), Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::MirroredRepeat,
            .T = Texture::SamplerTileMode::MirroredRepeat,
    }));
    _models.emplace_back(Plane, PlaneMaterial);
}

void Plane::createBackPlane() {
    auto Plane = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements, glm::vec3{0.95f, 0.95f, 0.95f});
    Plane->Transform = glm::rotate(Plane->Transform, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, .0f));
    Plane->Transform = glm::translate(Plane->Transform, glm::vec3(0.0f, 0.0f, 10.0f));
    Plane->Transform = glm::scale(Plane->Transform, glm::vec3(1.0f, .50f, 1.0f));
    auto PlaneMaterial = std::make_shared<Material>(_basicUnlitShader);

    PlaneMaterial->AddTexture(std::make_shared<Texture>(Path("Steel.jpg"), Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::MirroredRepeat,
            .T = Texture::SamplerTileMode::MirroredRepeat,
    }));
    _models.emplace_back(Plane, PlaneMaterial);
}


