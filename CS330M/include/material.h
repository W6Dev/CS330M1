//
// Created by Dsk3 on 9/15/2023.
//
#pragma once
#include <filesystem>
#include <shader.h>
#include <types.h>

class Material {
public:
    explicit Material(std::shared_ptr<Shader> shader);

    void AddTexture(const std::shared_ptr<Texture>& texture);
    void Bind(const SceneParameters& sceneParameters, const glm::mat4& model);

    Shader* GetShader() { return _shader.get(); }


private:

    std::shared_ptr<Shader> _shader { nullptr };
    std::vector<std::shared_ptr<Texture>> _textures {};

private:

};

