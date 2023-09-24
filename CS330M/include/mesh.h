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
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices );

    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, const glm::vec3& color);
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec2& uvScale, const glm::vec3& color = {1.f, 1.f, 1.f});


    void Draw() const;

    glm::mat4 Transform{1.0f};
private:
    void init(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);

private:

    uint32_t _elementCount{0};
    GLuint _vertexBufferObject{};
    GLuint _shaderProgram{};
    GLuint _vertexArrayObject{};
    GLuint _elementBufferObject{};


};


