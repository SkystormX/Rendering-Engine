#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>
#define PI 3.141592654
using namespace std;
#pragma once


class Entity{
public:
    virtual void Tick(double dt) =0;
    virtual void Render() =0; 
    
    Entity() {
        static int id = 0;
        id++;
        cout << "Entity created" <<id<< endl;
        next_tick_destroy = false;
    }
    bool next_tick_destroy;
    virtual void Destroy(){
        next_tick_destroy = true;
    }
};

