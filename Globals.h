#pragma once
#include <GLFW/glfw3.h>
#include <list>
#define PI 3.141592654
#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 786
#define WINDOW_NAME "Rendering Engine"

//#include "Entity.h"
class Entity;

GLFWwindow* window;
std::list<Entity*> entity_pointers;
