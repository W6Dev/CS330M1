//
// Created by Dsk3 on 9/15/2023.
//

#pragma once
#include <vector>
#include <types.h>
#include <glad/glad.h>

class Mesh {
public:
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec3& color);
    Mesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements, const glm::vec2& uvScale, const glm::vec3& color = {1.f, 1.f, 1.f});

    void Draw() const;

    glm::mat4 Transform {1.f};

private:
    void init(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements);

private:

    uint32_t _elementCount {0};
    GLuint _vertexBufferObject {};
    GLuint _shaderProgram {};
    GLuint _vertexArrayObject {};
    GLuint _elementBufferObject {};
};

