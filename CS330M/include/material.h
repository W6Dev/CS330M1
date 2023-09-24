//
// Created by Dsk3 on 9/15/2023.
//
#pragma once
#include <filesystem>

#include <shader.h>
#include <types.h>


using Path = std::filesystem::path;

class Material {
public:
    explicit Material(std::shared_ptr<Shader> shader);

    void Bind(const SceneParameters& sceneParameters, const glm::mat4& model);

    Shader* GetShader() { return _shader.get(); }


private:
    GLint getUniformLocation(const std::string& uniformName);
    std::shared_ptr<Shader> _shader { nullptr };

private:
    GLuint _materialProgram{};
};


