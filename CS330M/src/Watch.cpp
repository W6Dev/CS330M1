//
// Created by Dsk3 on 9/23/2023.
//

#include <Model_objects/Watch.h>
#include <Mesh.h>
#include <Model.h>
#include <Texture.h>
#include <shader.h>
#include <memory>

Watch::Watch() {
    createShaders();
    createCase();
    //createBand();
}
void Watch::Init() {

}

void Watch::Update(float deltaTime) {

}


void Watch::createShaders() {
    Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";

    _basicUnlitShader = std::make_shared<Shader>(shaderPath / "basic_lit.vert", shaderPath / "basic_lit.frag");
}

void Watch::createCase() {
    auto watch = std::make_shared<Mesh>(Shapes::PlaneVertices, Shapes::PlaneElements);

    auto planeMaterial = std::make_shared<Material>(_basicUnlitShader);

    _models.emplace_back(watch, planeMaterial);

}

void Watch::createBand() {

}

