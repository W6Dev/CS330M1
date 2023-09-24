//
// Created by Dsk3 on 9/15/2023.
//
#pragma once
#include <filesystem>
#include <string>
#include <GLAD/glad.h>
#include <glm/glm.hpp>
#include <shader.h>
#include <types.h>

using Path = std::filesystem::path;

class Shader {
public:


    Shader() = default;
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    Shader(const Path& vertexPath, const Path& fragmentPath);


    void Bind();

    void SetMat4(const std::string& uniformName ,const glm::mat4& mat4);
    void SetInt(const std::string& uniformName, int value);

    void SetVec3(const std::string& uniformName, const glm::vec3& vec3) const;
    void SetMat4(const std::string& uniformName, const glm::mat4& mat4) const;
    void SetInt(const std::string& uniformName, int value) const;
    void SetFloat(const std::string& uniformName, float value) const;


private:
    void load(const std::string& vertexSource, const std::string& fragmentSource);
    GLint getUniformLocation(const std::string& uniformName);

private:
    GLuint _shaderProgram{};
};


