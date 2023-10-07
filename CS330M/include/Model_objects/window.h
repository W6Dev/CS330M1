//
// Created by Dsk3 on 9/29/2023.
//

#pragma once

#include "Model_objects/model_objects.h"
#include <memory>
#include <model.h>

class Window : public ModelObjects{
public:
    Window();

    void Init() override;

    void Update(float deltaTime) override;


private:
    void createShaders();
    void createMeshes();
    void createBackWindow();
private:
    std::shared_ptr<Shader> _basicUnlitShader;

};