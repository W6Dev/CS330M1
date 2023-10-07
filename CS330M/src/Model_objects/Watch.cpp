//
// Created by Dsk3 on 9/23/2023.
//
#include <Model_objects/Watch.h>
#include <types.h>
#include <memory>
#include <material.h>
#include "glm/gtc/matrix_transform.hpp"

Watch::Watch() {
    createShaders();
    createFace();
    createBand();
    createSide();
}
void Watch::Init() {
}

void Watch::Update(float deltaTime) {

}

void Watch::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("mod7.vert"), Path("mod7.frag"));
    //_basicUnlitShader = std::make_shared<Shader>(Path("texture.vert"), Path("texture.frag"));
}
void Watch::createSide() {

    auto watchMaterial = std::make_shared<Material>(_basicUnlitShader);

    // Watch Case Side
    auto [CylinderVertices, CylinderElements] = GenerateSide();
    auto watchCase = std::make_shared<Mesh>(CylinderVertices, CylinderElements);
    watchCase->Transform = glm::translate(watchCase->Transform, glm::vec3(3.0f, 1.43f, 4.0f));
    watchCase->Transform = glm::rotate(watchCase->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watchCase->Transform = glm::scale(watchCase->Transform, glm::vec3(.85f, .85f, .35f));
    watchMaterial->AddTexture(std::make_shared<Texture>(Path("Side_case.png")));
    _models.emplace_back(watchCase, watchMaterial);
}



void Watch::createFace() {
    // create watch face
    auto watchMaterial = std::make_shared<Material>(_basicUnlitShader);

    // Watch Face
    auto [CylinderVertices, CylinderElements] = GenerateCircle();
    auto watchFace = std::make_shared<Mesh>(CylinderVertices, CylinderElements);
    watchFace->Transform = glm::translate(watchFace->Transform, glm::vec3(3.0f, 1.4f, 4.0f));
    watchFace->Transform = glm::rotate(watchFace->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watchFace->Transform = glm::rotate(watchFace->Transform, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    watchFace->Transform = glm::rotate(watchFace->Transform, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    watchFace->Transform = glm::scale(watchFace->Transform, glm::vec3(.85f, .85f, .85f));

    watchMaterial->AddTexture(std::make_shared<Texture>(Path("Watch_Face.png"), Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::ClampToEdge,
            .T = Texture::SamplerTileMode::ClampToEdge,
    }));
    _models.emplace_back(watchFace, watchMaterial);
}

void Watch::createBand() {
    // Watch Band
    auto bandMaterial = std::make_shared<Material>(_basicUnlitShader);

    auto [BandVertices, BandElements] = GenerateRectangle();
    auto watchBand = std::make_shared<Mesh>(BandVertices, BandElements, glm::vec3{0.5f,.5f,.5f});
    watchBand->Transform = glm::translate(watchBand->Transform, glm::vec3(3.0f, 1.2f, 3.75f));
    watchBand->Transform = glm::rotate(watchBand->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watchBand->Transform = glm::scale(watchBand->Transform, glm::vec3(.85f, .85f, .85f));

    bandMaterial->AddTexture(std::make_shared<Texture>(Path("Link.png"), Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::MirroredRepeat,
            .T = Texture::SamplerTileMode::MirroredRepeat,
    }));
    _models.emplace_back(watchBand, bandMaterial);

}
