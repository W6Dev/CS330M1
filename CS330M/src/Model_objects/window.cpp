//
// Created by Dsk3 on 9/23/2023.
//
#include <Model_objects/window.h>
#include <types.h>
#include <memory>
#include <material.h>
#include "glm/gtc/matrix_transform.hpp"

Window::Window() {
    createShaders();
    createMeshes();
}
void Window::Init() {
}

void Window::Update(float deltaTime) {
}

void Window::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("texture.vert"), Path("texture.frag"));
}

void Window::createMeshes() {
    auto Window = std::make_shared<Mesh>(Shapes::WindowVertices, Shapes::WindowElements, glm::vec3{.45f, .45f, .45f});
    Window->Transform = glm::rotate(Window->Transform, glm::radians(180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    Window->Transform = glm::rotate(Window->Transform, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    Window->Transform = glm::translate(Window->Transform, glm::vec3(0.0f, 10.0f, 15.0f));
    //Window->Transform = glm::scale(Window->Transform, glm::vec3(1.0f, 1.0f, 1.0f));
    auto WindowMaterial = std::make_shared<Material>(_basicUnlitShader);

    WindowMaterial->AddTexture(std::make_shared<Texture>(Path("Window.jpg")));
    _models.emplace_back(Window, WindowMaterial);
}

