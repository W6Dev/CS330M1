//
// Created by Dsk3 on 9/23/2023.
//

#pragma once
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <mesh.h>
#include <shader.h>
#include <Camera.h>
#include <Texture.h>

class Model {
public:
    Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture);
    Shader* GetShader() { return _shader.get(); }
    Mesh* GetMesh() { return _mesh.get(); }
private:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Shader> _shader;
    std::shared_ptr<Texture> _texture;
};
