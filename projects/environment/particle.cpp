
#include <iostream>

using namespace std;

class Particle{
    public: 
        char** id; 
        bool collide; 
        float x; 
        float y; 

    Particle(char** id_val, float x_pos, float y_pos){
        id = id_val;
        x = x_pos; 
        y = y_pos; 
    }

    void updatePos(char** id_given,float x_pos, float y_pos){
        if (id_given == id){
            x = x_pos; 
            y = y_pos; 
        }
    }

}; 
