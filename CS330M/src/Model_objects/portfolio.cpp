//
// Created by Dsk3 on 9/29/2023.
//

#include "Model_objects/portfolio.h"
#include "types.h"
#include <memory>
#include "material.h"
#include "glm/gtc/matrix_transform.hpp"

Portfolio::Portfolio() {
    createShaders();
    createMeshes();
}

void Portfolio::Init() {
}

void Portfolio::Update(float deltaTime) {
}

void Portfolio::createShaders() {
    _basicUnlitShader = std::make_shared<Shader>(Path("mod6.vert"), Path("mod6.frag"));
   // _basicUnlitShader = std::make_shared<Shader>(Path("basic_lit.vert"), Path("basic_lit.frag"));

}

void Portfolio::createMeshes() {
    auto portfolio = std::make_shared<Mesh>(Shapes::PortfolioVertices, Shapes::PortfolioElements);
    auto portfolioMaterial = std::make_shared<Material>(_basicUnlitShader);
    _models.emplace_back(portfolio, portfolioMaterial);

}
