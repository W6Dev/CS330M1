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
    _basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}

void Plane::createMeshes() {
    auto plane = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements);
    plane->Transform = glm::rotate(plane->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    auto planeMaterial = std::make_shared<Material>(_basicUnlitShader);

    planeMaterial->AddTexture(std::make_shared<Texture>(Path("Steel.jpg")
            , Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::MirroredRepeat,
            .T = Texture::SamplerTileMode::MirroredRepeat,
    }))

    ;

    _models.emplace_back(plane, planeMaterial);

}
