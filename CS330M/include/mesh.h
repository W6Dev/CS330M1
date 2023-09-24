//
// Created by Dsk3 on 9/15/2023.
//

#pragma once
#include <vector>
#include <types.h>
#include <string>
#include <glad/glad.h>
#include <shader.h>



class Mesh {
public:
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices);
    //Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, std::vector<Shader>& shaders);

    void Draw();

    glm::mat4 Transform{1.0f};

private:

    uint32_t _elementCount{};
    GLuint _vertexBufferObject{};
    GLuint _shaderProgram{};
    GLuint _vertexArrayObject{};
    GLuint _elementBufferObject{};


};


