//
// Created by Dsk3 on 9/15/2023.
//

#include <mesh.h>
#include <types.h>
#include <iostream>


Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<uint32_t> &elements) {
    init(vertices, elements);
}

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<uint32_t> &elements, const glm::vec3 &color) {
    for (auto& vertex : vertices) {
        vertex.Color = color;
    }

    init(vertices, elements);
}


Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<uint32_t> &elements, const glm::vec2 &uvScale,
           const glm::vec3 &color) {

    for (auto& vertex : vertices) {
        vertex.Color = color;
        vertex.Uv.x *= uvScale.x;
        vertex.Uv.y *= uvScale.y;
    }

    init(vertices, elements);
}

void Mesh::Draw() const {
    // Bind vertex array
    glBindVertexArray(_vertexArrayObject);

    // draw the number of elements defined by _elementCount pointed to by the vertex array object
    glDrawElements(GL_TRIANGLES, static_cast<int>(_elementCount), GL_UNSIGNED_INT, nullptr);
}

void Mesh::init(std::vector<Vertex>& vertices, std::vector<uint32_t>& elements) {
    for (auto i = 0; i < elements.size(); i += 3) {
        auto p1Index = elements[i];
        auto p2Index = elements[i + 1];
        auto p3Index = elements[i + 2];

        //Shapes::UpdateNormals(vertices[p1Index], vertices[p2Index], vertices[p3Index]);
    }

    // Generate a vertex array, a vertex buffer, and an element (index) buffer
    glGenVertexArrays(1, &_vertexArrayObject);
    glGenBuffers(1, &_vertexBufferObject);
    glGenBuffers(1, &_elementBufferObject);

    // Bind the vertex array so all subsequent state data is bound to this VAO
    glBindVertexArray(_vertexArrayObject);

    // Bind the vertex buffer and upload the data
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), vertices.data(), GL_STATIC_DRAW);

    // Bind the index buffer and upload the data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(elements.size() * sizeof(uint32_t)), elements.data(), GL_STATIC_DRAW);

    // define vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Position)));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Color)));
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Normal)));
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Uv)));

    // Enable the vertex attributes
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);

    // cache the number of elements in the element array, needed when drawing
    _elementCount = elements.size();
}