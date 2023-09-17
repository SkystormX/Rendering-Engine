#!/usr/bin/env bash
g++ $(pkg-config gl glew glfw3 --libs --cflags) main.cpp -o out