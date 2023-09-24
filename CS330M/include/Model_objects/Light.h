//
// Created by Dsk3 on 9/23/2023.
//
#pragma once

#include "Model_objects/model_objects.h"
#include <memory>
#include <shader.h>
#include <mesh.h>
#include <model.h>

class Light : public ModelObjects{
public:
    Light();

    void Init() override;

    void Update(float deltaTime) override;

    void Draw(SceneParameters& sceneParams) override;

private:
    void createShaders();
    void createMeshes();
private:
    std::shared_ptr<Shader> _basicUnlitShader;
    std::shared_ptr<Mesh> _lightMesh;

    std::vector<Model> _models;
};


