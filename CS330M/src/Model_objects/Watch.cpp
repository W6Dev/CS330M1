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
    createMeshes();
    createBand();
    createSide();
}
void Watch::Init() {
}

void Watch::Update(float deltaTime) {
}

void Watch::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("Texture.vert"), Path("Texture.frag"));
    //_basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));
}
void Watch::createSide() {

    auto watchMaterial = std::make_shared<Material>(_basicUnlitShader);

    // Watch Face
    auto [CylinderVertices, CylinderElements] = GenerateSide();
    auto watchFace = std::make_shared<Mesh>(CylinderVertices, CylinderElements);
    watchFace->Transform = glm::translate(watchFace->Transform, glm::vec3(3.0f, 1.0f, 4.0f));
    watchFace->Transform = glm::rotate(watchFace->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watchFace->Transform = glm::scale(watchFace->Transform, glm::vec3(.85f, .85f, .85f));

    watchMaterial->AddTexture(std::make_shared<Texture>(Path("Side_case.png")));

    _models.emplace_back(watchFace, watchMaterial);

}


void Watch::createMeshes() {
    // create watch Meshes
    auto watchMaterial = std::make_shared<Material>(_basicUnlitShader);

    // Watch Face
    auto [CylinderVertices, CylinderElements] = GenerateCircle();
    auto watchFace = std::make_shared<Mesh>(CylinderVertices, CylinderElements);
    watchFace->Transform = glm::translate(watchFace->Transform, glm::vec3(3.0f, 1.0f, 4.0f));
    watchFace->Transform = glm::rotate(watchFace->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
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
    auto watchBand = std::make_shared<Mesh>(BandVertices, BandElements);
    watchBand->Transform = glm::translate(watchBand->Transform, glm::vec3(3.0f, 1.2f, 3.75f));
    watchBand->Transform = glm::rotate(watchBand->Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watchBand->Transform = glm::scale(watchBand->Transform, glm::vec3(.85f, .85f, .85f));

    bandMaterial->AddTexture(std::make_shared<Texture>(Path("Link.png"), Texture::SamplerSettings {
            .S = Texture::SamplerTileMode::MirroredRepeat,
            .T = Texture::SamplerTileMode::MirroredRepeat,
    }));
    _models.emplace_back(watchBand, bandMaterial);

}
