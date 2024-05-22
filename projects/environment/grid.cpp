#include <iostream>
#include <list>
#include <random>
#include "particle.h"
#include "grid.h"

using namespace std;

class GridEnvironment{ 

    public: 
        // list of items in env (entities not included yet)
        list<Particle>** agents; 
        // communication channel dim 
        int dim_c; 
        // pos dimensionality 
        int dim_pos = 2; 
        // color dimensionality
        int color_dim = 3; 
        // sim timestep 
        float dt = 0.1; 
        // physical dampling
        int damping = 0.25; 
        // contact force params 
        float contact_force = 0.01;
        float contact_margin = 0.001;  
        // other gen params
        int num_rows; 
        int num_cols; 
        int** arrayxy;
        int num_agents; 
        vector<float> forces; 

        // constructor 
        GridEnvironment(int rows, int cols) {
            num_rows = rows;
            num_cols = cols;
            arrayxy = new int*[num_rows];  // Allocate memory for rows

            for (int i = 0; i < num_rows; ++i) {
                arrayxy[i] = new int[num_cols];  // Allocate memory for each row's columns
            }

        }

        ~GridEnvironment() {
            // Free memory when the object is destroyed
            for (int i = 0; i < num_rows; ++i) {
                delete[] arrayxy[i];
            }
            delete[] arrayxy;
        }

        // list<Particle> returnEntities(){return agents;}

        void step(list<vector<float>> actions, list<Particle>* agents){
            // apply action force 
            list<float> force_array; 
            force_array = calcActionForce(agents);

            // apply env force 
            list<Particle>& agent_a = *agents; // dereferences 

            // TODO: need to fix, will cause errors 
            list<float> fl_out = applyEnvironmentForce(agent_a, force_array);  

            updateAgentState(agent_a); 

        }

        // gather agent action forces 
        list<float> calcActionForce(list<Particle>* agents){
            list<float> force_array;  // allocate memory
            list<Particle>& agents_actual = *agents; // dereferences 
            float noise = 0;   

            std::random_device rd;
            std::mt19937 gen(rd());

            int ind = 0; 
        
            for (list<Particle>::iterator it = agents_actual.begin(); it != agents_actual.end(); ++it){
                Particle& agent = *it;
                std::normal_distribution<float> dist(0.0f, agent.u_noise);

                if (agent.moveable){
                    if (agent.u_noise){
                    noise = dist(gen); 
                    }
                    float force = agent.action + noise; 
                    force_array.push_back(force); 
                    ind += 1; 
                }
            }

            return force_array; 
        }

        std::list<float> applyEnvironmentForce(list<Particle>& entities, list<float> p_force) {
            // Simple collision response
            auto it_force = p_force.begin();  // Iterator for p_force list

            for (auto it_a = entities.begin(); it_a != std::prev(entities.end()); ++it_a) {
                for (auto it_b = std::next(it_a); it_b != entities.end(); ++it_b) {
                    vector<float> forces = getCollisionForce(&(*it_a), &(*it_b));
                    if (!forces.empty()) {  // Check if forces vector is not empty
                        // Update forces in p_force list using iterators
                        *it_force++ += forces[0];  // Add force to the current position in p_force
                        *it_force++ += forces[1];  // Add force to the next position in p_force
                    }
                }
            }

            return p_force;
        }


        vector<float> getCollisionForce(Particle* a, Particle* b){
            Particle& agent_a = *a; // dereferences 
            Particle& agent_b = *b; // dereferences 
            
            if (!agent_a.collide || !agent_b.collide) {
                return {0, 0}; 
            }

            // Compute actual distance between entities
            std::vector<float> delta_pos;
            for (size_t i = 0; i < agent_a.position.size(); ++i) {
                delta_pos.push_back(agent_a.position[i] - agent_b.position[i]);
            }

            float dist = 0.0f;
            for (float delta : delta_pos) {
                dist += delta * delta;
            }
            dist = std::sqrt(dist);

            // Minimum allowable distance
            float dist_min = agent_a.size + agent_b.size;

            // Softmax penetration
            float k = contact_margin;
            float penetration = std::log1p(std::exp(-(dist - dist_min) / k) * k);

            // Compute force
            std::vector<float> force;
            for (size_t i = 0; i < delta_pos.size(); ++i) {
                force.push_back(contact_force * delta_pos[i] / dist * penetration);
            }

            return force;
        }


        void updateAgentState(list<Particle> agents){

        }

        void printGrid(){
            // Populate and print the 2D array 
            for (int i = 0; i < num_rows; ++i) {
                for (int j = 0; j < num_cols; ++j) {
                    arrayxy[i][j] = 0;  // Assign a value
                    cout << arrayxy[i][j] << " ";  // Print the value
                }
                cout << endl;  // Move to the next row
            }
        }
}; 

int main(){
    cout << "GRID\n" << endl; 
    GridEnvironment grid = GridEnvironment(5, 5); 
    grid.printGrid();
    return 0;  


}

extern "C" {
    GridEnvironment* init(int rows, int cols) {
        return new GridEnvironment(rows, cols);
    }

    void printGrid(GridEnvironment* grid) {
        grid->printGrid();
    }

    void destroyGrid(GridEnvironment* grid) {
        delete grid;
    }
}