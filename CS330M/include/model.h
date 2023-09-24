//
// Created by Dsk3 on 9/23/2023.
//

#pragma once
#include <string>
#include <mesh.h>
#include <material.h>


class Model {
public:
    Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material);
    Material* GetMaterial() { return _material.get(); }
    Mesh* GetMesh() { return _mesh.get(); }
private:
    std::shared_ptr<Mesh> _mesh;
    std::shared_ptr<Material> _material;
};
