//
// Created by Dsk3 on 9/23/2023.
//
#pragma once
#include <glm/glm.hpp>
#include <model.h>
#include <types.h>
#include <memory>
#include <iostream>

class ModelObjects {
public:
    ~ModelObjects() = default;
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(const SceneParameters& sceneParams)
            {
                for(auto& model : _models){
                    auto* mesh = model.GetMesh();
                    model.GetMaterial()->Bind(sceneParams, Transform * mesh->Transform);
                    mesh->Draw();
                }
            };

    virtual void ProcessLighting(SceneParameters& sceneParams){};

public:
    glm::mat4 Transform {1.0f};
    std::vector<Model> _models;

};