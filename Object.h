#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>
#define PI 3.141592654
using namespace std;
class Object{
public:
    glm::dvec2 pos, vel; 
    double velocity;
    double angular_velocity;
    double theta;
    glm::ivec3 color;

    Object() {
        static int objectid = 0;
        objectid++;
        velocity = 300;
        angular_velocity = 180;
        theta = 0;
        pos = {0,0};
        vel = {0,0};
        cout << "object created" <<objectid<< endl;
        
    }

    glm::dvec2 GetForwardVector(){
        return glm::dvec2(sin(theta*(PI/180)),cos(theta*(PI/180)));
    }


    void Tick(GLFWwindow* window,double dt){

        if (pos.x > 640+50){
            pos.x=-50;
        }
        if (pos.x < -50){
            pos.x=640+50;
        }

        if (pos.y > 480+25){
            pos.y=-25;
        }
        if (pos.y < -25){
            pos.y=480+25;
        }


        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
            pos += velocity*GetForwardVector()*dt;
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            theta -= angular_velocity*dt;

        }
        
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            theta += angular_velocity*dt;

        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            pos -= velocity*GetForwardVector()*dt;
        }

        glLoadIdentity();
        glOrtho(0.0,640,0, 480, -1.0, 1.0);
        glTranslated(pos.x,pos.y,0);
        glRotated(theta,0,0,-1);


        glColor3ub(color.x,color.y,color.z);
        glBegin(GL_TRIANGLES);
        glVertex2d(-25, -25);
        glVertex2d(0.0f, 50);
        glVertex2d(25, -25);
        glEnd();  




    }
};