//
// Created by Dsk3 on 9/23/2023.
//

#pragma once
#include <Model_objects/model_objects.h>
#include <memory>
#include <iostream>
#include <Shader.h>
#include <Mesh.h>
#include <Texture.h>
#include <model.h>

class Watch :public ModelObjects{
public:
    Watch();
    void Init() override;
    void Update(float deltaTime) override;

private:
    void createShaders();
    void createCase();
    void createBand();
private:
    std::shared_ptr<Shader> _basicUnlitShader;
    std::shared_ptr<Shader> _textureShader;

    std::shared_ptr<Mesh> _case;
    std::shared_ptr<Mesh> _band;

    std::vector<Model> _models;


};


