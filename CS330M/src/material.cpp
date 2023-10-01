//
// Created by Dsk3 on 9/15/2023.
//
#include <iostream>
#include <material.h>

Material::Material(std::shared_ptr<Shader> shader) : _shader { std::move(shader) } {}

void Material::AddTexture(const std::shared_ptr<Texture> &texture) {
    _textures.emplace_back(texture);
}

void Material::Bind(const SceneParameters& sceneParams, const glm::mat4& model) {
    _shader->Bind();

    _shader->SetMat4("projection", sceneParams.ProjectionMatrix);
    _shader->SetMat4("view", sceneParams.ViewMatrix);

    // Set Camera Position
    _shader->SetVec3("eyePos", sceneParams.CameraPosition);

    _shader->SetMat4("model", model);

    // Set Lighting
    for (auto i = 0; i < sceneParams.Lights.size(); i++) {
        std::string uniformName = "lightPos";
        uniformName += std::to_string(i);
        _shader->SetVec3(uniformName, sceneParams.Lights[i]);
    }



    for (auto i = 0; i < _textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        _textures[i]->Bind();
    }

}

