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
    //createShaders();
    //createCase();
    //createBand();
}
void Watch::Init() {

}

void Watch::Update(float deltaTime) {

}

void Watch::Draw(SceneParameters& sceneParams) {
    for(auto& model : _models){
        auto* shader = model.GetShader();
        auto* mesh = model.GetMesh();
        shader->Bind();
        shader->SetMat4("projection", sceneParams.ProjectionMatrix);
        shader->SetMat4("view", sceneParams.ViewMatrix);
        shader->SetMat4("model", Transform * mesh->Transform);

        mesh->Draw();
    }

}

void Watch::createShaders() {
    _basicShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));

    auto bandTexture1 = std::make_shared<Texture>(Path("watch_band.png"));
    auto bandTexture2 = std::make_shared<Texture>(Path("watch_band2.png"));


   // _textureShader->AddTexture(bandTexture1);
    // _textureShader->AddTexture(bandTexture2);



}