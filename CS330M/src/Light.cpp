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
#include <string>
#include <application.h>
#include <iostream>
#include <types.h>


Light::Light() {
    createShaders();
    createMeshes();
}

void Light::Init() {
}

void Light::Update(float deltaTime) {
}

void Light::Draw(SceneParameters& sceneParams) {
    for(auto& model : _models){
        auto* shader = model.GetShader();
        auto* mesh = model.GetMesh();
        shader->Bind();
        shader->SetMat4("projection",sceneParams.ProjectionMatrix);
        shader->SetMat4("view", sceneParams.ViewMatrix);
        shader->SetMat4("model", Transform * mesh->Transform);

        mesh->Draw();
    }
}

void Light::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("basic_lit_color.vert"), Path("basic_lit_color.frag"));
}

void Light::createMeshes() {
    //glm::vec3{1.f, 1.f, 1.f}
    auto cube = std::make_shared<Mesh>(Shapes::cubeVertices, Shapes::cubeElements);
    cube->Transform = glm::scale(cube->Transform, glm::vec3{0.2f, 0.2f, 0.2f});

    // how to fix the line below??
    _models.emplace_back(cube, _basicUnlitShader, nullptr);

}
