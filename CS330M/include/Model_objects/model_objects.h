//
// Created by Dsk3 on 9/23/2023.
//
#pragma once
#include <glm/glm.hpp>
#include <types.h>

class ModelObjects {
public:
    ~ModelObjects() = default;
    virtual void Init() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw(SceneParameters& sceneParams) = 0;

public:
    glm::mat4 Transform {1.0f};
};