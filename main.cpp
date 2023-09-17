#include <GLFW/glfw3.h>
#include <math.h>
#define PI 3.141592654
#include "Object.h"
#include <vector>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    Object triangle;
    triangle.pos = {50,50};
    triangle.color = {255,0,0};
    Object triangle2;
    triangle2.pos = {400,50};
    triangle2.color = {69,69,69};


    double last_time = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        double cur_time = glfwGetTime();
        double dt = cur_time - last_time;
        last_time = cur_time;
        glClear(GL_COLOR_BUFFER_BIT); 
        triangle.Tick(window,dt);

        triangle2.Tick(window,dt);
        
        glfwSwapBuffers(window);
        glfwPollEvents(); 


    }

    glfwTerminate();
    return 0;
}