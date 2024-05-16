
#include <iostream>
#include <vector>

using namespace std;

class Particle{
    public: 
        char** id; 
        bool collide; 
        vector<float> position; 
        float mass; 

    Particle(char** id_val, float x_pos, float y_pos, float mass_given){
        id = id_val;
        position = {x_pos, y_pos}; 
        mass = mass_given; 
    }

    void updatePos(char** id_given,float x_pos, float y_pos){
        if (id_given == id){
            position = {x_pos, y_pos}; 
        }
    }

    void updateVector(vector<float> force){
        // Calculate acceleration: a = F / m
        vector<float> acceleration = {force[0] / mass, force[1] / mass};

        // Update velocity: v = v0 + a * t (t = 1 second here)
        float velocity_x = acceleration[0];
        float velocity_y = acceleration[1];

        // Update position: r = r0 + v * t + 0.5 * a * t^2 (t = 1 second here)
        position[0] += velocity_x + 0.5 * acceleration[0];
        position[1] += velocity_y + 0.5 * acceleration[1];
    }

}; 
