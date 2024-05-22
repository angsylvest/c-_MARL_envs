#include <iostream>
#include <vector>
#include "particle.h"

using namespace std;

// class for agent in multi-particle environment 

class Entity {
        public: 
            // name 
            char** id;
            // properties
            float size = 0.050;  
            // can be moved/pushed 
            bool moveable = true;
            // collision possible 
            bool collide = true; 
            // density 
            float density = 25.0; 
            // color 
            char** color; 
            // max speed 
            float max_speed = 5.0; 
            float accel; 
            // state info 
            vector<float> position; 
            vector<float> velocity; 
            // mass 
            float mass = 1.0; 

        float getMass(){
            return mass; 
        }
}; 


class Particle : public Entity{
    public: 
        // agents moveable by default 
        bool moveable = true; 
        // cannot send comm signals 
        bool silent = false; 
        // cannot observe world 
        bool blind = false; 
        // physical motor noise 
        float u_noise; 
        // communication noise 
        float c_noise; 
        // control range 
        float u_range = 1.0; 
        // state info 
        vector<float> p_pos;  
        vector<float> p_vel;  
        // current action 
        float action; 
        int comm_action; 


        Particle(char** id_val, float x_pos, float y_pos){
            id = id_val;
            position = {x_pos, y_pos}; 
            velocity = {0,0}; 
        
        }

        // update pos of agent given action 
        void updatePos(char** id_given,float x_pos, float y_pos){
            if (id_given == id){
                position = {x_pos, y_pos}; 
            }
        }

        // update velocity instance var 
        void updateVelocity(char** id_given, vector<float> vel){
            if (id_given == id){
                velocity = vel; 
            }
        }

}; 
