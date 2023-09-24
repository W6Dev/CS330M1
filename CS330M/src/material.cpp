//
// Created by Dsk3 on 9/15/2023.
//

#include <material.h>
#include <iostream>


Material::Material(std::shared_ptr<Shader> shader) : _shader(std::move(shader)) {
    };



void Material::Bind(const SceneParameters& sceneParams, const glm::mat4& model) {

    _shader->Bind();
    _shader->SetMat4("projection", sceneParams.ProjectionMatrix);
    _shader->SetMat4("view", sceneParams.ViewMatrix);
    _shader->SetMat4("model", model);




    //glUseProgram(_materialProgram);
}







