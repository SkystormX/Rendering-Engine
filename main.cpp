#include <math.h>
#include <vector>
#include "Player.h"
#include "Globals.h"

int main(void){
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);

    if (!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    Player* triangle = new Player();
    triangle->pos = {50,50};
    triangle->color = {255,0,0};
//   Player* triangle2 = new Player();
//     triangle2->pos = {400,50};
//     triangle2->color = {69,69,69};
    entity_pointers.push_back(triangle);
//    entity_pointers.push_back(triangle2);


    double last_time = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        double cur_time = glfwGetTime();
        double dt = cur_time - last_time;
        last_time = cur_time;
        glClear(GL_COLOR_BUFFER_BIT); 

        for (Entity* p : entity_pointers) {
            p->Tick(dt);
        }

        for (Entity* p : entity_pointers) {
            p->Render();
        }
        entity_pointers.remove_if([](Entity* e) { 
            return e->next_tick_destroy; 
        });



        glfwSwapBuffers(window);
        glfwPollEvents(); 


    }

    glfwTerminate();
    return 0;
};