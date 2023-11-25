#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "Globals.h"
#include "Entity.h"
#include "Ball.h"
using namespace std;

class Player : public Entity{
private:
    double last_ball_time;
public:
    glm::dvec2 pos, vel; 
    double velocity;
    double angular_velocity;
    double theta;
    glm::ivec3 color;
    

    Player() {
        velocity = 300;
        angular_velocity = 180;
        theta = 0;
        pos = {0,0};
        vel = {0,0};  
    }

    glm::dvec2 GetForwardVector(){
        return glm::dvec2(sin(theta*(PI/180)),cos(theta*(PI/180)));
    }

    Ball* ball;
    void Tick(double dt){

        // if (pos.x > WINDOW_WIDTH+50){
        //     pos.x=-50;
        // }
        // if (pos.x < -50){
        //     pos.x=WINDOW_WIDTH+50;
        // }

        // if (pos.y > WINDOW_HEIGHT+25){
        //     pos.y=-25;
        // }
        // if (pos.y < -25){
        //     pos.y=WINDOW_HEIGHT+25;
        // }


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
        
        if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS){
            if ((glfwGetTime()-last_ball_time) > 1){
                last_ball_time = glfwGetTime();
                cout << "Test" << endl;
                Ball* b = new Ball();
                b->color = {255,0,0};
                b->pos = pos;
                b->vel = 100.0*GetForwardVector();
                entity_pointers.push_back(b);


            }

        }


    }
    void Render(){
        glLoadIdentity();
        glOrtho(0.0,WINDOW_WIDTH,0, WINDOW_HEIGHT, -1.0, 1.0);
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
