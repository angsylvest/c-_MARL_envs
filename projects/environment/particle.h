
#include <iostream>
#include <vector>

using namespace std;

class Particle{
    public: 
        char** id; 
        bool collide; 
        vector<float> position; 
        float mass; 

    Particle(char** id_val, float x_pos, float y_pos, float mass_given);

    void updatePos(char** id_given,float x_pos, float y_pos);

    void updateVector(vector<float> force);

}; 
