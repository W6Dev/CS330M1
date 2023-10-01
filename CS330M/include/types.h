//
// Created by Dsk3 on 9/15/2023.
//

#pragma once

#include <array>
#include <glm/glm.hpp>
#include <utility>
#include <numbers>
#include <cmath>
#include <vector>


struct Vertex {
    glm::vec3 Position{0.f, 0.f, 0.f};
    glm::vec3 Color{1.f, 1.f, 1.f};
    glm::vec3 Normal{0.f, 0.f, 0.f};
    glm::vec2 Uv{0.f, 0.f};

};



struct SceneParameters{
    glm::mat4 ProjectionMatrix{1.f};
    glm::mat4 ViewMatrix{1.f};
    glm::vec3 CameraPosition {};



    std::vector<glm::vec3> Lights{};
};

constexpr uint8_t MAX_LIGHTS = 10;
constexpr double PI = std::numbers::pi;

struct Shapes {
    static inline void UpdateNormals(Vertex& p1, Vertex& p2, Vertex& p3) {
        glm::vec3 U = p2.Position - p1.Position;
        glm::vec3 V = p3.Position - p1.Position;

        auto normal = glm::cross(U, V);

        p1.Normal = normal;
        p2.Normal = normal;
        p3.Normal = normal;
    }

    static inline std::vector<Vertex> cubeVertices
            {
                    // front face
                    {
                            .Position = {-0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },
                    // right face
                    {
                            .Position = {0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },


                    // back face
                    {
                            .Position = {0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },

                    // left face
                    {
                            .Position = {-0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },
                    // Top face
                    {
                            .Position = {-0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {-0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {0.5f, 0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {0.5f, 0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },
                    // Bottom Face
                    {
                            .Position = {0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 1.f},
                    },
                    {
                            .Position = {0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {0.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, -0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 0.f},
                    },
                    {
                            .Position = {-0.5f, -0.5f, 0.5f},
                            .Color = {1.f, 1.f, 1.f},
                            .Uv = {1.f, 1.f},
                    },
            };


    static inline std::vector<uint32_t> cubeElements{
            {
                    0, 1, 3, 1, 2, 3, //front face
                    4, 5, 7, 5, 6, 7, //right face
                    8, 9, 11, 9, 10, 11, //back face
                    12, 13, 15, 13, 14, 15, //left face
                    16, 17, 19, 17, 18, 19, //top face
                    20, 21, 23, 21, 22, 23 //bottom face
            }
    };

    static inline std::vector<Vertex> PlaneVertices
    {
            // Top face
            {
                    {.Position = {-20.5f, 10.0f, 0.0f},
                            .Color = {1.0f, 1.0f, 1.0f}},
                    {.Position = {20.5f, 10.0f, 0.0f},
                            .Color = {1.0f, 1.0f, 1.0f}},
                    {.Position = {-20.5f, -10.0f, 0.0f},
                            .Color = {1.0f, 1.0f, 1.0f}},
                    {.Position = {20.5f, -10.0f, 0.0f},
                            .Color = {1.0f, 1.0f, 1.0f}},
            }
    };

    static inline std::vector<uint32_t> PlaneElements{
            {
                    0, 1, 2 , 1, 3, 2 //top face
              }
    };

    static inline std::vector<Vertex> PortfolioVertices
            {
                    // Back cover ======================================
                    // front face
                    {
                            .Position = {-4.8f, 0.2f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.2f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    // right face
                    {
                            .Position = {5.0f, 0.2f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.2f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },


                    // back face
                    {
                            .Position = {5.0f, 0.2f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },

                    // left face
                    {
                            .Position = {-4.8f, 0.2f, -6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, 6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    // Top face
                    {
                            .Position = {-4.8f, 0.2f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {5.0f, 0.2f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {5.0f, 0.2f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Bottom Face
                    {
                            .Position = {5.0f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {5.0f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },

                    // Front cover ======================================
                    // front face
                    {
                            .Position = {-4.8f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},

                    },
                    {
                            .Position = {-4.8f, 0.8f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},

                    },
                    {
                            .Position = {5.0f, 0.8f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},

                    },
                    {
                            .Position = {5.0f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},

                    },
                    // right face
                    {
                            .Position = {5.0f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.8f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.8f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },


                    // back face
                    {
                            .Position = {5.0f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {5.0f, 0.8f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },

                    // left face
                    {
                            .Position = {-4.8f, 1.0f, -6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, -6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, 6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 1.0f, 6.0f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    // Top face
                    {
                            .Position = {-4.8f, 1.0f, -6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},

                    },
                    {
                            .Position = {-4.8f, 1.0f, 6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},

                    },
                    {
                            .Position = {5.0f, 1.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},


                    },
                    {
                            .Position = {5.0f, 1.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},

                    },
                    // Bottom Face
                    {
                            .Position = {5.0f, 0.8f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {5.0f, 0.8f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Paper ======================================
                    // front face
                    {
                            .Position = {-4.8f, 0.8f, 5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, 5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {4.8f, 0.2f, 5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {4.8f, 0.8f, 5.8f},
                            .Color = {0.93f, 0.77f, 0.57f},
                    },
                    // right face
                    {
                            .Position = {4.8f, 0.8f, 5.8f},
                            .Color = {0.93f, 0.77f, 0.57f},
                    },
                    {
                            .Position = {4.8f, 0.2f, 5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {4.8f, 0.2f, -5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {4.8f, 0.8f, -5.8f},
                            .Color = {0.93f, 0.77f, 0.57f},
                    },


                    // back face
                    {
                            .Position = {4.8f, 0.8f, -5.8f},
                            .Color = {0.93f, 0.77f, 0.57f},
                    },
                    {
                            .Position = {4.8f, 0.2f, -5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, -5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, -5.8f},
                            .Color = {1.f, 0.95f, 0.71f},
                    },

                    // left face
                    {
                            .Position = {-4.8f, 0.8f, -5.8f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, -5.8f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, 5.8},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, 5.8f},
                            .Color = {0.f, 1.f, 1.0f},
                    },
                    // Top face
                    {
                            .Position = {-4.8f, 0.8f, -5.8f},
                            .Color = {1.f, 1.f, 0.0f},
                    },
                    {
                            .Position = {-4.8f, 0.8f, 5.8f},
                            .Color = {1.f, 1.f, 0.0f},
                    },
                    {
                            .Position = {4.8f, 0.8f, 5.8f},
                            .Color = {1.f, 1.f, 0.0f},
                    },
                    {
                            .Position = {4.8f, 0.8f, -5.8f},
                            .Color = {1.f, 1.f, 0.0f},
                    },
                    // Bottom Face
                    {
                            .Position = {4.8f, 0.2f, 5.8f},
                            .Color = {1.f, 0.f, 1.0f},
                    },
                    {
                            .Position = {4.8f, 0.2f, -5.8f},
                            .Color = {1.f, 0.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, -5.8f},
                            .Color = {1.f, 0.f, 1.0f},
                    },
                    {
                            .Position = {-4.8f, 0.2f, 5.8f},
                            .Color = {1.f, 0.f, 1.0f},
                    },
                    // Back spine ======================================
                    // front face -4.8
                    {
                            .Position = {-5.0f, 1.14f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 1.14f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    // right face
                    {
                            .Position = {-4.8f, 1.14f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 1.14f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },


                    // back face
                    {
                            .Position = {-4.8f, 1.14f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-5.0f, 1.14f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },

                    // left face
                    {
                            .Position = {-5.0f, 1.14f, -6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-5.0f, 1.14f, 6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},
                    },
                    // Top face
                    {
                            .Position = {-5.0f, 1.14f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-5.0f, 1.14f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 1.14f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 1.14f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Bottom Face
                    {
                            .Position = {-4.8f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.8f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-5.0f, 0.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Top Spine ======================================
                    // front face -4.8
                    {
                            .Position = {-4.99f, 1.15f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.15f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    // right face
                    {
                            .Position = {-3.3f, 1.15f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.0f, 6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.15f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },


                    // back face
                    {
                            .Position = {-3.3f, 1.15f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-3.3f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },
                    {
                            .Position = {-4.99f, 1.15f, -6.0f},
                            .Color = {0.6f, 0.2f, 0.f},
                    },

                    // left face
                    {
                            .Position = {-4.99f, 1.15f, -6.0f},
                            .Color = {0.80f, 0.47f, 0.13f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, 6.0f},
                            .Color = {0.80f, 0.47f, 0.13f},
                    },
                    {
                            .Position = {-4.99f, 1.15f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Top face
                    {
                            .Position = {-4.99f, 1.15f, -6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},
                    },
                    {
                            .Position = {-4.99f, 1.15, 6.0f},
                            .Color = {0.78f, 0.38f, 0.08f},
                    },
                    {
                            .Position = {-3.3f, 1.15f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-3.3f, 1.15f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    // Bottom Face
                    {
                            .Position = {-3.3f, 1.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-3.3f, 1.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, -6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },
                    {
                            .Position = {-4.99f, 1.0f, 6.0f},
                            .Color = {0.80f, 0.50f, 0.20f},
                    },


            };


    static inline std::vector<uint32_t> PortfolioElements{
            {
                    // Back cover ======================================
                    0, 1, 3, 1, 2, 3, //front face
                    4, 5, 7, 5, 6, 7, //right face
                    8, 9, 11, 9, 10, 11, //back face
                    12, 13, 15, 13, 14, 15, //left face
                    16, 17, 19, 17, 18, 19, //top face
                    20, 21, 23, 21, 22, 23, //bottom face

                    // Front cover ======================================
                    24, 25, 27, 25, 26, 27,//front face
                    28, 29, 31, 29, 30, 31,//right face
                    32, 33, 35, 33, 34, 35,//back face
                    36, 37, 39, 37, 38, 39,//left face
                    40, 41, 43, 41, 42, 43,//top face
                    44, 45, 47, 45, 46, 47,//bottom face

                    // Paper ==========================
                    48, 49, 51, 49, 50, 51,//front face
                    52, 53, 55, 53, 54, 55,//right face
                    56, 57, 59, 57, 58, 59,//back face
                    60, 61, 63, 61, 62, 63,//left face
                    64, 65, 67, 65, 66, 67,//top face
                    68, 69, 71, 69, 70, 71,//bottom face

                    // Back spline ==================
                    72, 73, 75, 73, 74, 75,//front face
                    76, 77, 79, 77, 78, 79,//right face
                    80, 81, 83, 81, 82, 83,//back face
                    84, 85, 87, 85, 86, 87,//left face
                    88, 89, 91, 89, 90, 91,//top face
                    92, 93, 95, 93, 94, 95, //bottom face

                    // top spline ======
                    96, 97, 99, 97, 98, 99,//front face
                    100, 101, 103, 101, 102, 103,//right face
                    104, 105, 107, 105, 106, 107,//back face
                    108, 109, 111, 109, 110, 111,//left face
                    112, 113, 115, 113, 114, 115,//top face
                    116, 117, 119, 117, 118, 119,//bottom face
            }
    };

    static inline std::vector<Vertex> PenVertices{
            //===================================================
            // PEN
            //===================================================
            // Pen Body ======================================
            // front face
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {1.f, 0.f, 0.f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {1.f, 0.f, 0.f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {1.f, 0.f, 0.f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {1.f, 0.f, 0.f},
            },
            // right face
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },


            // back face
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.f, 0.f, 1.0f},
            },
            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.f, 0.f, 1.0f},
            },
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.f, 0.f, 1.0f},
            },
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.f, 0.f, 1.0f},
            },

            // left face
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            // Top face
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            // Bottom Face
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },
            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },

            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {0.18f, 0.18f, 0.18f},
            },



            // Pen Clicker ================================
            // front face
            {
                    .Position = {-0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, -0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, -0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            // right face
            {
                    .Position = {0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, -0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, 0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },


            // back face
            {
                    .Position = {0.1f, 0.1f, -4.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.1f, -0.1f, -4.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.1f, -0.1f, -4.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.1f, 0.1f, -4.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },

            // left face
            {
                    .Position = {-0.1f, 0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, -0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, -0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            // Top face
            {
                    .Position = {-0.1f, 0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, 0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, 0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            // Bottom Face
            {
                    .Position = {-0.1f, -0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {-0.1f, -0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },
            {
                    .Position = {0.1f, -0.1f, -4.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },

            {
                    .Position = {0.1f, -0.1f, 0.0f},
                    .Color = {0.60f, 0.60f, 0.60f},
            },



            // Pen Ring ======================================
            // front face
            {
                    .Position = {-0.2f, 0.2f, 0.20f},
                    .Color = {0.f, 1.f, 0.f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.20f},
                    .Color = {0.f, 1.f, 0.f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.20f},
                    .Color = {0.f, 1.f, 0.f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.20f},
                    .Color = {1.f, 0.f, 0.f},
            },
            // right face
            {
                    .Position = {0.2f, 0.2f, 0.20f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.20f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },


            // back face
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {1.f, 0.f, 1.0f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {1.f, 0.f, 1.0f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {1.f, 0.f, 1.0f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {1.f, 0.f, 1.0f},
            },

            // left face
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.20f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.20f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            // Top face
            {
                    .Position = {-0.2f, 0.2f, 0.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.20f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.20f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            // Bottom Face
            {
                    .Position = {-0.2f, -0.2f, 0.20f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },

            {
                    .Position = {0.2f, -0.2f, 0.20f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },



            // Pen clip======================================
            // front face
            {
                    .Position = {-0.08f, -0.2f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.08f, -0.4f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.4f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.2f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            // right face
            {
                    .Position = {0.08f, -0.2f, -2.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.08f, -0.4f, -2.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.08f, -0.4f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.08f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },


            // back face
            {
                    .Position = {0.08f, -0.2f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.4f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.08f, -0.4f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.08f, -0.2f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },

            // left face
            {
                    .Position = {-0.08f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.08f, -0.4f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.08f, -0.4f, -2.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.08f, -0.2f, -2.0f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            // Top face
            {
                    .Position = {-0.08f, -0.2f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.08f, -0.2f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.2f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.2f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            // Bottom Face
            {
                    .Position = {-0.08f, -0.4f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {-0.08f, -0.4f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },
            {
                    .Position = {0.08f, -0.4f, -3.5f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },

            {
                    .Position = {0.08f, -0.4f, -2.0f},
                    .Color = {0.50f, 0.50f, 0.50f},
            },


            // Pen clicker ring ================================
            // front face
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            // right face
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.1f, -0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.1f, 0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },

            // back face
            {
                    .Position = {0.1f, 0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {0.1f, -0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.1f, -0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.1f, 0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },

            // left face
            {
                    .Position = {-0.1f, 0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.1f, -0.1f, -3.7f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.40f, 0.40f, 0.40f},
            },
            // Top face
            {
                    .Position = {-0.1f, 0.1f, -3.7f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            {
                    .Position = {-0.2f, 0.2f, -3.5f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            {
                    .Position = {0.2f, 0.2f, -3.5f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            {
                    .Position = {0.1f, 0.1f, -3.7f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            // Bottom Face
            {
                    .Position = {-0.2f, -0.2f, -3.5f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            {
                    .Position = {-0.1f, -0.1f, -3.7f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },
            {
                    .Position = {0.1f, -0.1f, -3.7f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },

            {
                    .Position = {0.2f, -0.2f, -3.5f},
                    .Color = {0.30f, 0.30f, 0.30f},
            },



            // Pen pyramid ================================
            // front face
            {
                    .Position = {-0.2f, 0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            // right face
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.2f, -0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },

            {
                    .Position = {0.2f, 0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },



            // back face
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },

            // left face
            {
                    .Position = {-0.2f, 0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.2f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },
            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {0.13f, 0.13f, 0.13f},
            },

            // Top face
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },
            {
                    .Position = {0.2f, 0.2f, 0.2f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },
            {
                    .Position = {-0.2f, 0.2f, 0.2f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },

            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },


            // Bottom Face
            {
                    .Position = {0.2f, -0.2f, 0.2f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },
            {
                    .Position = {-0.2f, -0.2f, 0.2f},
                    .Color = {0.23f, 0.23f, 0.23f},
            },


            // Pen tip pyramid ================================
            // front face
            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {1.f, 1.f, 1.f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {1.f, 1.f, 1.f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {1.f, 1.f, 1.f},
            },
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {1.f, 1.f, 1.f},
            },
            // right face
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {0.f, 1.f, 0.f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {0.f, 1.f, 0.f},
            },
            {
                    .Position = {0.0f, 0.0f, 1.6f},
                    .Color = {0.f, 1.f, 0.f},
            },



            // left face
            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {0.f, 1.f, 1.0f},
            },
            {
                    .Position = {0.0f, 0.00f, 1.6f},
                    .Color = {0.f, 1.f, 1.0f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {0.f, 1.f, 1.0f},
            },


            // Top face
            {
                    .Position = {0.0f, 0.0f, 1.6f},
                    .Color = {1.f, 1.f, 0.0f},
            },
            {
                    .Position = {-0.1f, 0.1f, 1.3f},
                    .Color = {1.f, 1.f, 0.0f},
            },
            {
                    .Position = {0.1f, 0.1f, 1.3f},
                    .Color = {1.f, 1.f, 0.0f},
            },

            // Bottom Face
            {
                    .Position = {0.0f, 0.0f, 1.6f},
                    .Color = {1.f, 0.f, 1.0f},
            },
            {
                    .Position = {-0.1f, -0.1f, 1.3f},
                    .Color = {1.f, 0.f, 1.0f},
            },
            {
                    .Position = {0.1f, -0.1f, 1.3f},
                    .Color = {1.f, 0.f, 1.0f},
            },




    };


    static inline std::vector<uint32_t> PenElements{
            {
                    // Pen Body ======================================
                    0, 1, 3, 1, 2, 3, //front face
                    4, 5, 7, 5, 6, 7, //right face
                    8, 9, 11, 9, 10, 11, //back face
                    12, 13, 15, 13, 14, 15, //left face
                    16, 17, 19, 17, 18, 19, //top face
                    20, 21, 23, 21, 22, 23, //bottom face

                    // Clicker ======================================
                    24, 25, 27, 25, 26, 27,//front face
                    28, 29, 31, 29, 30, 31,//right face
                    32, 33, 35, 33, 34, 35,//back face
                    36, 37, 39, 37, 38, 39,//left face
                    40, 41, 43, 41, 42, 43,//top face
                    44, 45, 47, 45, 46, 47,//bottom face
                    // Ring ==========================
                    48, 49, 51, 49, 50, 51,//front face
                    52, 53, 55, 53, 54, 55,//right face
                    56, 57, 59, 57, 58, 59,//back face
                    60, 61, 63, 61, 62, 63,//left face
                    64, 65, 67, 65, 66, 67,//top face
                    68, 69, 71, 69, 70, 71,//bottom face

                    // clip ==================
                    72, 73, 75, 73, 74, 75,//front face
                    76, 77, 79, 77, 78, 79,//right face
                    80, 81, 83, 81, 82, 83,//back face
                    84, 85, 87, 85, 86, 87,//left face
                    88, 89, 91, 89, 90, 91,//top face
                    92, 93, 95, 93, 94, 95, //bottom face

                    // clicker ring ======
                    96, 97, 99, 97, 98, 99,//front face
                    100, 101, 103, 101, 102, 103,//right face
                    104, 105, 107, 105, 106, 107,//back face
                    108, 109, 111, 109, 110, 111,//left face
                    112, 113, 115, 113, 114, 115,//top face
                    116, 117, 119, 117, 118, 119,//bottom face

                    // Pen pyramid ================================
                    120, 121, 123, 121, 122, 123,//front face
                    124, 125, 127, 125, 126, 127,//right face
                    128, 129, 131, 129, 130, 131,//back face
                    132, 133, 135, 133, 134, 135,//left face
                    136, 137, 139, 137, 138, 139,//top face
                    140, 141, 143, 141, 142, 143,//bottom face

                    // pen tip pyramid ================================
                    144, 145, 147, 145, 146, 147,//front face
                    148, 150, 149, // right face
                    153, 152, 151,
                    154, 156, 155,
                    157, 158, 159

            },
    };

};


//=====================
// Generate a Watch Side
static std::pair<std::vector<Vertex>, std::vector<uint32_t>> GenerateSide(
        float radius = 0.75f, uint32_t sectors = 50, uint32_t stacks = 50) {

    std::vector<Vertex> vertices{};
    std::vector<uint32_t> indices{};
   double centerIndex = .05;

    float sectorStep = 2 * PI / sectors;

    std::vector<float> unitCircleVertices;
    for (uint32_t i = 0; i <= sectors; ++i) {
        double sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle)); // x
        unitCircleVertices.push_back(sin(sectorAngle)); // y
        unitCircleVertices.push_back(0);                // z
    }

    // Side vertices
    for (int i = 0; i < 2; ++i) {
        float h = -0.0f + i; // z value, -0.5 to 0.5
        for (uint32_t j = 0, k = 0; j <= sectors; ++j, k += 3) {
            vertices.push_back(Vertex{
                    .Position = {unitCircleVertices[k] * radius, unitCircleVertices[k + 1] * radius, h},
                    .Color = {0.80f, 0.80f, 0.80f},
                    .Uv = {j / static_cast<float>(sectors), i }
            });
        }
    }

    // Side indices
    for (uint32_t i = 0, k1 = 0, k2 = sectors + 1; i < sectors; ++i, ++k1, ++k2) {
        indices.insert(indices.end(), {k1, k1 + 1, k2, k2, k1 + 1, k2 + 1});
    }

    return {vertices, indices};
}

// Generate a Cylinder
static std::pair<std::vector<Vertex>, std::vector<uint32_t>> GenerateCircle(
        float radius = 0.75f, uint32_t sectors = 50, uint32_t stacks = 50) {

    std::vector<Vertex> vertices{};
    std::vector<uint32_t> indices{};
    unsigned int centerIndex = 0;

    float sectorStep = 2 * PI / sectors;

    std::vector<float> unitCircleVertices;
    for (uint32_t i = 0; i <= sectors; ++i) {
        double sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle)); // x
        unitCircleVertices.push_back(sin(sectorAngle)); // y
        unitCircleVertices.push_back(0);                // z
    }

    centerIndex = static_cast<int>(vertices.size());
    // Base and top vertices with indices
   // for (int i = 1; i < 1; ++i) {
        float h = 0.0f ;
        centerIndex = static_cast<int>(vertices.size());
        vertices.push_back(Vertex{
                .Position = {0, 0, h},
                .Color = {1.0f, 0.44f, 0.10f},
                .Uv = {.50, .50}
        });

        for (uint32_t j = 0, k = 0; j < sectors; ++j, k += 3) {
            vertices.push_back(Vertex{
                    .Position = {unitCircleVertices[k] * radius, unitCircleVertices[k + 1] * radius, h},
                    .Color = {0.89f, 0.44f, 0.10f},
                    .Uv = {unitCircleVertices[k]* .5f + .5f, unitCircleVertices[k + 1]* .5f + .5f},

            });
        }

        // Indices for the base and top
        for (uint32_t j = 0, k = centerIndex + 1; j < sectors; ++j, ++k) {
            if (j < sectors - 1) {
                indices.insert(indices.end(), {centerIndex, k, k + 1});
            } else { // last triangle
                indices.insert(indices.end(), {centerIndex, k, centerIndex + 1});
            }
        }
   // }

    return {vertices, indices};
}



// Generate a Cone
static std::pair<std::vector<Vertex>, std::vector<uint32_t>> GenerateCone(
        float baseRadius = 1.5f, float topRadius = 1.75f, uint32_t sectors = 50, uint32_t stacks = 50) {

    std::vector<Vertex> vertices{};
    std::vector<uint32_t> indices{};

    float sectorStep = 2 * PI / sectors;

    std::vector<float> unitCircleVertices;
    for (uint32_t i = 0; i <= sectors; ++i) {
        float sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle)); // x
        unitCircleVertices.push_back(sin(sectorAngle)); // y
        unitCircleVertices.push_back(0);                // z
    }

    float heights[2] = {0.f, 2.75f};
    float radii[2] = {baseRadius, topRadius};

    // Side vertices
    for (int i = 0; i < 2; ++i) {
        float h = heights[i];
        for (uint32_t j = 0, k = 0; j <= sectors; ++j, k += 3) {
            vertices.push_back(Vertex{
                    .Position = {unitCircleVertices[k] * radii[i], unitCircleVertices[k + 1] * radii[i], h},
                    .Color = {0.33f, 0.39f, 0.62f}
            });
        }
    }

    // Side indices
    for (uint32_t i = 0, k1 = 0, k2 = sectors + 1; i < sectors; ++i, ++k1, ++k2) {
        indices.insert(indices.end(), {k1, k1 + 1, k2, k2, k1 + 1, k2 + 1});
    }

    // Base and top vertices with indices
    for (int i = 0; i < 2; ++i) {
        float h = heights[i];
        unsigned int centerIndex = static_cast<int>(vertices.size());
        vertices.push_back(Vertex{
                .Position = {0, 0, h},
                .Color = {0.96f, 0.96f, 0.86f}
        });

        for (uint32_t j = 0, k = 0; j < sectors; ++j, k += 3) {
            vertices.push_back(Vertex{
                    .Position = {unitCircleVertices[k] * radii[i], unitCircleVertices[k + 1] * radii[i], h},
                    .Color = {.89f, .66f, .41f}
            });
        }

        // Indices for the base and top
        for (uint32_t j = 0, k = centerIndex + 1; j < sectors; ++j, ++k) {
            if (j < sectors - 1) {
                indices.insert(indices.end(), {centerIndex, k, k + 1});
            } else { // last triangle
                indices.insert(indices.end(), {centerIndex, k, centerIndex + 1});
            }
        }
    }

    return {vertices, indices};
}

// Generate a Torus
static std::pair<std::vector<Vertex>, std::vector<uint32_t>> GenerateTorus(
        float majorRadius = 0.6f, float minorRadius = 0.15f, uint32_t sectors = 50, uint32_t rings = 50) {


    std::vector<Vertex> vertices{};
    std::vector<uint32_t> indices{};
    float ringStep = 2 * PI / rings;
    float sectorStep = 2 * PI / sectors;

    // Compute torus vertices
    for (uint32_t i = 0; i <= rings; ++i) {
        double ringAngle = i * ringStep;
        double cosRing = cos(ringAngle);
        double sinRing = sin(ringAngle);

        for (uint32_t j = 0; j <= sectors; ++j) {
            double sectorAngle = j * sectorStep;
            double cosSector = cos(sectorAngle);
            double sinSector = sin(sectorAngle);
            double x = (majorRadius + minorRadius * cosSector) * cosRing;
            double y = (majorRadius + minorRadius * cosSector) * sinRing;
            double z = minorRadius * sinSector;

            vertices.push_back(Vertex{
                    .Position = {x, y, z},
                    .Color = {0.33f, 0.39f, 0.62f},
                    .Uv = {static_cast<float>(i) / rings, static_cast<float>(j) / sectors}

            });
        }
    }

    // Compute torus indices
    for (uint32_t i = 0; i < rings; ++i) {
        for (uint32_t j = 0; j < sectors; ++j) {
            uint32_t k1 = i * (sectors + 1) + j;
            uint32_t k2 = k1 + sectors + 1;

            indices.insert(indices.end(), {k1, k1 + 1, k2, k2, k1 + 1, k2 + 1});
        }
    }
    return {vertices, indices};
}

// Generate a Rectangle
static std::pair<std::vector<Vertex>, std::vector<uint32_t>>
GenerateRectangle(float width = 1.0f, float height = 4.50f, float depth = .15f) {
    float halfWidth = width / 2.0f;
    float halfHeight = height / 2.0f;
    float halfDepth = depth / 2.0f;

    std::vector<Vertex> vertices{};
    std::vector<uint32_t> indices{};

    // Define the four vertices of the rectangle using push_back
    // bottom
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });
    // right face
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });
    // back face
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 12.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 12.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });
    // left face
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });
    // front face
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });
    // top face
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 0.0f}
    });
    vertices.push_back(Vertex{
            .Position = {halfWidth, -halfHeight, -depth},
            .Color = {00.80f, 0.80f, 0.80f},
            .Uv = {0.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, -depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 1.0f}
    });
    vertices.push_back(Vertex{
            .Position = {-halfWidth, -halfHeight, depth},
            .Color = {0.80f, 0.80f, 0.80f},
            .Uv = {1.0f, 0.0f}
    });

    // Define the indices for the rectangle using push_back
    // front face
    indices = {
            0, 1, 3, 1, 2, 3, //front face
            4, 5, 7, 5, 6, 7, //right face
            8, 9, 11, 9, 10, 11, //back face
            12, 13, 15, 13, 14, 15, //left face
            16, 17, 19, 17, 18, 19, //top face
            20, 21, 23, 21, 22, 23, //bottom face
    };
    return {vertices, indices};
}