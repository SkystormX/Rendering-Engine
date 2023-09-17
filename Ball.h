#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "Globals.h"
#include "Entity.h"
using namespace std;

void drawCircle(float cx, float cy, float r, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
glm::ivec3 HSLtoRGB(float h, float s, float l) {
    // Ensure h is in the range [0, 360]
    while (h < 0) h += 360;
    while (h >= 360) h -= 360;

    // Normalize s and l to the range [0, 1]
    s = glm::clamp(s, 0.0f, 1.0f);
    l = glm::clamp(l, 0.0f, 1.0f);

    float c = (1.0f - glm::abs(2.0f * l - 1.0f)) * s;
    float x = c * (1.0f - glm::abs(glm::mod(h / 60.0f, 2.0f) - 1.0f));
    float m = l - c / 2.0f;

    float r, g, b;
    if (h < 60) {
        r = c;
        g = x;
        b = 0;
    } else if (h < 120) {
        r = x;
        g = c;
        b = 0;
    } else if (h < 180) {
        r = 0;
        g = c;
        b = x;
    } else if (h < 240) {
        r = 0;
        g = x;
        b = c;
    } else if (h < 300) {
        r = x;
        g = 0;
        b = c;
    } else {
        r = c;
        g = 0;
        b = x;
    }

    // Scale and convert to integer RGB values
    glm::ivec3 rgbColor;
    rgbColor.r = static_cast<int>((r + m) * 255);
    rgbColor.g = static_cast<int>((g + m) * 255);
    rgbColor.b = static_cast<int>((b + m) * 255);

    return rgbColor;
}
class Ball : public Entity{
public:
    glm::dvec2 pos, vel; 
    glm::ivec3 color;
    double radius;
    double lifespan;
    Ball() {
        pos = {0,0};
        vel = {0,0};
        radius = 15;  
        lifespan = 3;
    }

    void Tick(double dt){
        if (pos.x > WINDOW_WIDTH+(2*radius)){
            pos.x=-(2*radius);
        }
        if (pos.x < -(2*radius)){
            pos.x=WINDOW_WIDTH+(2*radius);
        }

        if (pos.y > WINDOW_HEIGHT+(2*radius)){
            pos.y=-(2*radius);
        }
        if (pos.y < -(2*radius)){
            pos.y=WINDOW_HEIGHT+(2*radius);
        }        
        pos += vel*dt;
        double hue = fmod(glfwGetTime()*36, 360);
        color = HSLtoRGB (hue,0.5,0.5);
        
        lifespan -= dt;
        if (lifespan < 0){
            Destroy();
        }
    }
    void Render(){
        glLoadIdentity();
        glOrtho(0.0,WINDOW_WIDTH,0, WINDOW_HEIGHT, -1.0, 1.0);
        glTranslated(pos.x,pos.y,0);
    


        glColor3ub(color.x,color.y,color.z);
        drawCircle(0,0,radius,500);

    }
};
