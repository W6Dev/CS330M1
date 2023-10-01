//
// Created by Dsk3 on 9/22/2023.
//
#pragma once
#include <glm/glm.hpp>

class Camera {

public:
    enum class MoveDirection
    {
        Forward,
        Backward,
        Left,
        Right,
        Up,
        Down
    };

    explicit Camera(int width, int height, glm::vec3 initialPosition = glm::vec3{0,0,-20.f},bool isPerspective = true);

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix() const;
    glm::vec3 GetPosition() const { return _position; }
    bool IsPerspective() const {return _isPerspective;}
    void SetIsPerspective(bool isPerspective){_isPerspective = isPerspective;}
    void SetSize(int width, int height)
    {
        _width = width;
        _height = height;
    };
    void MoveCamera(MoveDirection direction, float moveAmount);
    void RotateCamera(float yaw, float pitch);
    void RotateBy(float yaw, float pitch);
    void IncrementZoom(float amount);
private:
    void recalculateVectors();

private:
    bool _isPerspective{true};
    glm::vec3 _position{};
    glm::vec3 _lookDirection{};
    glm::vec3 _upDirection{0.f, 1.f, 0.f};
    float _yaw {-90.f};
    float _pitch{0.f};
    float _fieldOfView{75.f};
    int _width{0};
    int _height{0};
    float _nearPlane{0.1f};
    float _farPlane{100.f};

};
