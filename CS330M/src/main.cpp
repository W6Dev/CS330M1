#include <iostream>
#include <application.h>
int main(int argc, char** argv)
{
	Application app("CS330 Matt Sandoval", 800, 600);
	app.Run();
	return 0;
}

// The following tutorial was used to help design the application architecture:
// https://www.youtube.com/playlist?list=PLI5uOhAD-G-PxbJ_Wq4nY0a8bWRSJMQij

// The Primary shape functions are based on the following tutorial:
// http://songho.ca/opengl/gl_sphere.html
// http://songho.ca/opengl/gl_cylinder.html
// https://electronut.in/torus/

// The following tutorial was used to help with the camera:
// https://learnopengl.com/Getting-started/Camera
