#pragma once

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Camera.h>
#include <vector>
#include <Model_objects/model_objects.h>

class Application
{
public:
	Application(std::string WindowTitle, int width, int height);
	void Run();

private:
	bool openWindow();
    bool draw();
    void update(float deltaTime);

    void setupScene();
    void setupInputs();

    void handleInput(float deltaTime);
    void handleMouseInput(double xPos, double yPos);
    void mousePositionCallback(double xPos, double yPos);
    float _movementSpeed{10.f};

private:
	std::string _applicationName{};
    int _width;
    int _height;

	GLFWwindow* _window{nullptr};

    std::vector<std::unique_ptr<ModelObjects>> _objects {};

    Camera _camera;

	bool _running{false};
    bool _firstMouse{false};
    glm::vec2 _lastMousePosition{-1,-1};
    glm::vec2 _cameraLookSpeed{};
    float _lastFrameTime{-1.f};


};