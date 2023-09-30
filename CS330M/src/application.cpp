#include <application.h>
#include <iostream>
#include <Model_objects\Light.h>
#include <Model_objects\portfolio.h>
#include <Model_objects\plane.h>
#include <Model_objects\pen.h>
#include <Model_objects\Coffee.h>
#include <Model_objects/Watch.h>
#include <Model_objects\model_objects.h>


Application::Application(std::string WindowTitle, int width, int height)
        : _applicationName(WindowTitle), _width(width), _height(height),
          _camera(width, height, {0, 15.f, 20.f}, true),
          _cameraLookSpeed{0.1f, 0.1f} {}

void Application::Run() {
    // open a window
    if (!openWindow()) {
        return;
    };

    setupInputs();

    _running = true;
    // Set up the scene

    // Set Camera Position
    _camera.IncrementZoom(10.f);
    _camera.RotateBy(20.f, -40.f);
    _camera.MoveCamera(Camera::MoveDirection::Forward, 10.f);
    _camera.MoveCamera(Camera::MoveDirection::Left, 5.f);

    setupScene();

    // run application
    while (_running) {
        float currentTime = static_cast<float>(glfwGetTime());
        if (_lastFrameTime == -1.f) {
            _lastFrameTime = currentTime;
        }
        auto deltaTime = currentTime - _lastFrameTime;
        _lastFrameTime = currentTime;

        if (glfwWindowShouldClose(_window)) {
            _running = false;
            break;
        }
        update(deltaTime);
        draw();
    }
    glfwTerminate();
}

bool Application::openWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    _window = glfwCreateWindow(1000, 750, "CS330 Matt Sandoval", nullptr, nullptr);

    if (!_window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

    }

    glfwMakeContextCurrent(_window);

    glfwSetWindowUserPointer(_window, (void *) this);

    glfwSetFramebufferSizeCallback(_window, [](GLFWwindow *window, int width, int height) {
        // Resize the viewport when the window is resized
        glViewport(0, 0, width, height);

        auto app = reinterpret_cast<Application *>(glfwGetWindowUserPointer(window));
        app->_width = width;
        app->_height = height;
        app->_camera.SetSize(width, height);
    });


    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return false;
    }
    glEnable(GL_DEPTH_TEST);
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    /*
    // cull back faces
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    */
    // enable MSAA
    glEnable(GL_MULTISAMPLE);
    return true;

    return true;
}

void Application::setupInputs() {
    // Exit the application when the escape key is pressed
    // Pressing the P key will toggle between perspective and orthographic projection
    glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        auto* app = reinterpret_cast<Application *>(glfwGetWindowUserPointer(window));
        switch (key) {
            case GLFW_KEY_ESCAPE: {
                if (action == GLFW_PRESS) {
                    app->_running = false;
                }
                break;
            }
            case GLFW_KEY_P: {
                if (action == GLFW_PRESS) {

                    app->_camera.SetIsPerspective(!app->_camera.IsPerspective());
                    if (app->_camera.IsPerspective())
                        std::cout << "Perspective Display turned on" << std::endl;
                    else
                        std::cout << "Orthographic Display turned on" << std::endl;

                }
            }
            default: {
            }

        }
    });

    // Input callbacks for mouse movement
    glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double xPos, double yPos) {
        auto app = reinterpret_cast<Application *>(glfwGetWindowUserPointer(window));
        app->mousePositionCallback(xPos, yPos);
    });

    // Input callbacks for mouse scroll
    glfwSetScrollCallback(_window, [](GLFWwindow *window, double xOffset, double yOffset) {
        auto app = reinterpret_cast<Application *>(glfwGetWindowUserPointer(window));
        app->_camera.IncrementZoom(yOffset * 3);
        std::cout << "Scrolling" << std::endl;
    });

    // Input callbacks for mouse button
    glfwSetMouseButtonCallback(_window, [](GLFWwindow *window, int button, int action, int mods) {
        switch (button) {
            case GLFW_MOUSE_BUTTON_LEFT: {
                if (action == GLFW_PRESS) {
                    std::cout << "Left Mouse Button Pressed at: " << std::endl;
                } else {};
                break;
            }
            case GLFW_MOUSE_BUTTON_MIDDLE: {
                if (action == GLFW_PRESS) {
                    std::cout << "Middle Mouse Button Pressed at: " << std::endl;
                } else {};
                break;
            }
            case GLFW_MOUSE_BUTTON_RIGHT: {
                if (action == GLFW_PRESS) {
                    std::cout << "Right Mouse Button Pressed at: " << std::endl;
                } else {};
                break;
            }
            default: {
                std::cout << "Dont know what button you pressed" << std::endl;
            }

        }
    });

}

// Process Keyboard Input
void Application::handleInput(float deltaTime) {
    auto moveAmount = _movementSpeed * deltaTime;
    if (glfwGetKey(_window, GLFW_KEY_W)) {
        _camera.MoveCamera(Camera::MoveDirection::Forward, moveAmount);
        std::cout << "W Pressed" << std::endl;
    }
    if (glfwGetKey(_window, GLFW_KEY_S)) {
        _camera.MoveCamera(Camera::MoveDirection::Backward, moveAmount);
        std::cout << "S Pressed" << std::endl;
    }
    if (glfwGetKey(_window, GLFW_KEY_A)) {
        _camera.MoveCamera(Camera::MoveDirection::Left, moveAmount);
        std::cout << "A Pressed" << std::endl;
    }
    if (glfwGetKey(_window, GLFW_KEY_D)) {
        _camera.MoveCamera(Camera::MoveDirection::Right, moveAmount);
        std::cout << "D Pressed" << std::endl;
    }
    if (glfwGetKey(_window, GLFW_KEY_Q)) {
        _camera.MoveCamera(Camera::MoveDirection::Up, moveAmount);
        std::cout << "Q Pressed" << std::endl;
    }
    if (glfwGetKey(_window, GLFW_KEY_E)) {
        _camera.MoveCamera(Camera::MoveDirection::Down, moveAmount);
        std::cout << "E Pressed" << std::endl;
    }

}

// Build the scene
void Application::setupScene() {



    _objects.emplace_back(std::make_unique<Light>());
    _objects.emplace_back(std::make_unique<Portfolio>());
    _objects.emplace_back(std::make_unique<Plane>());
    _objects.emplace_back(std::make_unique<Pen>());
    _objects.emplace_back(std::make_unique<Coffee>());
    _objects.emplace_back(std::make_unique<Watch>());

}

void Application::update(float deltaTime) {
    glfwPollEvents();
    handleInput(deltaTime);

    for (auto &model: _objects) {
        model->Update(deltaTime);
    }

}


// Draw the scene
bool Application::draw() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = _camera.GetViewMatrix();
    glm::mat4 projection = _camera.GetProjectionMatrix();


    SceneParameters sceneParams{
            .ProjectionMatrix = projection,
            .ViewMatrix = view,
            .CameraPosition = _camera.GetPosition(),
    };


    for (auto &model: _objects) {
        model->ProcessLighting(sceneParams);
    };

    for (auto &obj: _objects) {
        obj->Draw(sceneParams);
    }


    glfwSwapBuffers(_window);

    return false;
}

// Mouse Movement
void Application::mousePositionCallback(double xPos, double yPos) {
    if (!_firstMouse) {
        _lastMousePosition.x = static_cast<float>(xPos);
        _lastMousePosition.y = static_cast<float>(yPos);
        _firstMouse = true;
    }

    glm::vec2 moveAmount{
            _lastMousePosition.x - xPos,
            yPos - _lastMousePosition.y
    };

    _lastMousePosition.x = static_cast<float>(xPos);
    _lastMousePosition.y = static_cast<float>(yPos);

    _camera.RotateBy(moveAmount.x * _cameraLookSpeed.x, moveAmount.y * _cameraLookSpeed.y);
}








