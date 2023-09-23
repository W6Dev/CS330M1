#include <application.h>
#include <iostream>
#include <types.h>
#include <vector>
#include <shader.h>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image.h>


Application::Application(std::string WindowTitle, int width, int height)
        : _applicationName(WindowTitle), _width(width), _height(height),
          _camera(width, height, {0, 8.f, 20.f}, true),
          _cameraLookSpeed{0.1f, 0.1f} {}

void Application::Run() {
    // open a window
    if (!openWindow()) {
        return;
    };

    setupInputs();

    _running = true;
    // Set up the scene
    setupScene();

    // run application
    while (_running) {
        float currentTime = glfwGetTime();
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

    _window = glfwCreateWindow(1000, 800, "CS330 Matt Sandoval", nullptr, nullptr);

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
    return true;
}

void Application::setupInputs() {
    // Exit the application when the escape key is pressed
    // Pressing the P key will toggle between perspective and orthographic projection
    glfwSetKeyCallback(_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
        auto app = reinterpret_cast<Application *>(glfwGetWindowUserPointer(window));
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

    // Create Plane Meshes
   // _meshes.emplace_back(Shapes::PlaneVertices, Shapes::PlaneElements);

    // Create Portfolio Meshes
    // _meshes.emplace_back(Shapes::PortfolioVertices, Shapes::PortfolioElements);

    // Create Pen Meshes
    //_meshes.emplace_back(Shapes::PenVertices, Shapes::PenElements);
    auto pen = std::make_shared<Mesh>(Shapes::PenVertices, Shapes::PenElements);
    pen->Transform = glm::translate(pen->Transform, glm::vec3(.0f, 1.0f, 4.0f));
    pen->Transform = glm::rotate(pen->Transform, glm::radians(285.0f), glm::vec3(.0f, 0.0f, 1.0f));
    pen->Transform = glm::scale(pen->Transform, glm::vec3(.85f, .85f, .85f));
    //_meshes.push_back(*pen);

    // create Coffee Cup Meshes
    auto handle = (GenerateTorus());
    auto handle2 = _preMeshes.emplace_back(handle.first, handle.second);
    handle2.Transform = glm::rotate(handle2.Transform, glm::radians(0.0f), glm::vec3(.0f, 0.0f, 1.0f));
    handle2.Transform = glm::translate(handle2.Transform, glm::vec3(8.9f, 1.20f, 0.0f));
    handle2.Transform = glm::scale(handle2.Transform, glm::vec3(.85f, .85f, .85f));
    //_meshes.push_back(handle2);

    auto cup = (GenerateCone());
    auto cup2 = _preMeshes.emplace_back(cup.first, cup.second);
    cup2.Transform = glm::translate(cup2.Transform, glm::vec3(7.0, 0.0f, 0.0f));
    cup2.Transform = glm::rotate(cup2.Transform, glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    cup2.Transform = glm::scale(cup2.Transform, glm::vec3(.85f, .85f, .85f));
    //_meshes.push_back(cup2);

    // create watch Meshes
    auto watch = (GenerateCylinder());
    auto watch2 = _preMeshes.emplace_back(watch.first, watch.second);
    watch2.Transform = glm::translate(watch2.Transform, glm::vec3(3.0f, 1.0f, 4.0f));
    watch2.Transform = glm::rotate(watch2.Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    watch2.Transform = glm::scale(watch2.Transform, glm::vec3(.85f, .85f, .85f));
    //_meshes.push_back(watch2);

    auto bracelet = (GenerateRectangle());
    auto bracelet2 = _preMeshes.emplace_back(bracelet.first, bracelet.second);
    bracelet2.Transform = glm::translate(bracelet2.Transform, glm::vec3(3.0f, 1.2f, 3.75f));
    bracelet2.Transform = glm::rotate(bracelet2.Transform, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    bracelet2.Transform = glm::scale(bracelet2.Transform, glm::vec3(.85f, .85f, .85f));
    //_meshes.push_back(bracelet2);

    _meshes.emplace_back(Shapes::cubeVertices, Shapes::cubeElements);


    Path shaderPath = std::filesystem::current_path() / "assets" / "shaders";
    _shader = Shader(shaderPath / "basic_shader.vert", shaderPath / "basic_shader.frag");

    // Load a texture
    Path texturePath = std::filesystem::current_path() / "assets" / "textures";
    auto texture1Path = (texturePath / "wall.jpg").string();

    int width, height, numChannels;
    unsigned char *data = stbi_load(texture1Path.c_str(), &width, &height, &numChannels, STBI_rgb_alpha);

    glGenTextures(1, &_texture1);
    glBindTexture(GL_TEXTURE_2D, _texture1);
    if (data){
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); // last argument is the image data

    glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, width, height);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

}

bool Application::update(float deltaTime) {
    glfwPollEvents();
    handleInput(deltaTime);
    return false;
}

// Draw the scene
bool Application::draw() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = _camera.GetViewMatrix();
    glm::mat4 projection = _camera.GetProjectionMatrix();

    _shader.Bind();
    _shader.SetMat4("projection", projection);
    _shader.SetMat4("view", view);

    glBindTexture(GL_TEXTURE_2D, _texture1);

    for (auto &mesh: _meshes) {
        // mesh.Transform = glm::rotate(mesh.Transform, glm::radians(.1f), glm::vec3(0.0f, 1.0f, 0.0f));
        // mesh.Transform = glm::rotate(mesh.Transform, glm::radians(.1f), glm::vec3(1.0f, 0.0f, 0.0f));
        _shader.SetMat4("model", mesh.Transform);
        mesh.Draw();
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








