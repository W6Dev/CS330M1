//
// Created by Dsk3 on 9/15/2023.
//

#include <shader.h>
#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource) {
    load(vertexSource, fragmentSource);

}

Shader::Shader(const Path& vertexPath, const Path& fragmentPath) {
    try {
        // load sources from files
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;

        // open vertex and fragment shader file on disk
        vShaderFile.open(ShaderPath / vertexPath);
        fShaderFile.open(ShaderPath / fragmentPath);

        std::stringstream vShaderStream, fShaderStream;

        // store the contents in their respective string streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // close the files
        vShaderFile.close();
        fShaderFile.close();

        // load our shader using the source stored in our string streams
        load(vShaderStream.str(), fShaderStream.str());
    } catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
}

void Shader::Bind() const {
    // Bind the shader
    glUseProgram(_shaderProgram);

    SetInt("tex0", 0);
    SetInt("tex1", 1);
}


void Shader::AddTexture(const std::shared_ptr<Texture>& texture) {
    _textures.emplace_back(texture);
}

void Shader::SetVec3(const std::string &uniformName, const glm::vec3 &vec3) const {
    auto uniformLoc = getUniformLocation(uniformName);

    if (uniformLoc != -1) {
        glUniform3fv(uniformLoc, 1, glm::value_ptr(vec3));
    }
}

void Shader::SetMat4(const std::string& uniformName, const glm::mat4 &mat4) const {
    // Upload Mat4 to named uniform of same type.
    auto uniformLoc = getUniformLocation(uniformName);

    if (uniformLoc != -1) {
        glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(mat4));
    }
}

void Shader::SetInt(const std::string &uniformName, int value) const {
    // Upload integer to named uniform of same type.
    auto uniformLoc = getUniformLocation(uniformName);

    if (uniformLoc != -1) {
        glUniform1i(uniformLoc, value);
    }
}

void Shader::SetFloat(const std::string &uniformName, float value) const {
    // Upload integer to named uniform of same type.
    auto uniformLoc = getUniformLocation(uniformName);

    if (uniformLoc != -1) {
        glUniform1f(uniformLoc, value);
    }
}

GLint Shader::getUniformLocation(const std::string &uniformName) const {
    // Return the named uniform location in the compiled shader program
    return glGetUniformLocation(_shaderProgram, uniformName.c_str());
}

void Shader::load(const std::string &vertexSource, const std::string &fragmentSource) {
    const char* vShaderCode = vertexSource.c_str();
    const char* fShaderCode = fragmentSource.c_str();

    // Compile vertex shader
    auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Compile fragment shader
    auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Attach vertex and fragment shader to new shader program and link together
    _shaderProgram = glCreateProgram();
    glAttachShader(_shaderProgram, vertexShader);
    glAttachShader(_shaderProgram, fragmentShader);
    glLinkProgram(_shaderProgram);

    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::LINK_FAILED\n" << infoLog << std::endl;
    }

    // Now that linking is complete, original shaders no longer needed so can be deleted.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


