//
// Created by Dsk3 on 9/23/2023.
//

#include <model.h>
Model::Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
: _mesh(mesh), _shader(shader), _texture(texture) {}



