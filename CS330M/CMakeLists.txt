set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Run-Me/${CMAKE_SYSTEM_NAME})



add_subdirectory(external/cmakelibs/glfw)
add_subdirectory(external/shared/glm)
add_subdirectory(external/shared/stb_image)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE GLAD_SOURCES external/shared/glad/*.c)


add_executable(${PROJECT_NAME} ${SOURCES} ${GLAD_SOURCES} include/types.h src/mesh.cpp include/mesh.h src/shader.cpp include/shader.h src/Camera.cpp include/Camera.h external/shared/stb_image/stb/stb_image.h external/shared/stb_image/stb.cpp src/Texture.cpp include/Texture.h src/model.cpp include/model.h src/Model_objects/Light.cpp include/Model_objects/Light.h include/Model_objects/model_objects.h src/Model_objects/Watch.cpp include/Model_objects/Watch.h src/Model_objects/portfolio.cpp include/Model_objects/portfolio.h src/Model_objects/plane.cpp include/Model_objects/plane.h src/Model_objects/pen.cpp include/Model_objects/pen.h src/Model_objects/Coffee.cpp include/Model_objects/Coffee.h)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        include/
        external/shared/glad/include/
        glfw
        glm
        stb
        )
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        PRIVATE
        glfw
        OpenGL::GL
        glm
        stb
        )

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)