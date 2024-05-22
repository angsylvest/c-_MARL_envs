
#include <iostream>
#include <vector>

using namespace std;

class Entity{
    public: 
        // name 
        char** id;
        // properties
        float size;  
        // can be moved/pushed 
        bool moveable;
        // collision possible 
        bool collide; 
        // density 
        float density; 
        // color 
        char** color; 
        // max speed 
        float max_speed; 
        float accel; 
        // state info 
        vector<float> position; 
        vector<float> velocity; 
        // mass 
        float mass;

        float getMass();  
}; 

class Particle{
    public: 
        // agents moveable by default 
        bool moveable; 
        // cannot send comm signals 
        bool silent; 
        // cannot observe world 
        bool blind; 
        // physical motor noise 
        float u_noise; 
        // communication noise 
        float c_noise; 
        // control range 
        float u_range; 
        // state info 
        vector<float> p_pos;  
        vector<float> p_vel;  
        // current action 
        float action; 
        int comm_action; 

        Particle(char** id_val, float x_pos, float y_pos);
        void updatePos(char** id_given,float x_pos, float y_pos);
        void updateVelocity(char** id_given, vector<float> vel);

}; 
