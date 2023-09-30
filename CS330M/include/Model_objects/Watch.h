//
// Created by Dsk3 on 9/23/2023.
//

#pragma once

#include "Model_objects/model_objects.h"
#include <memory>
#include <model.h>

class Watch : public ModelObjects{
public:
    Watch();

    void Init() override;

    void Update(float deltaTime) override;



private:
    void createShaders();
    void createFace();
    void createBand();
    void createSide();
private:
    std::shared_ptr<Shader> _basicUnlitShader;

};


