#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class GridEnvironment {
public:
    list<Particle> agents; 
    // communication channel dim 
    int dim_c; 
    // pos dimensionality 
    int dim_pos; 
    // color dimensionality
    int color_dim; 
    // sim timestep 
    float dt; 
    // physical dampling
    int damping; 
    // contact force params 
    float contact_force;
    float contact_margin;  
    // other gen params
    int num_rows; 
    int num_cols; 
    int** arrayxy;

    // constructor 
    GridEnvironment(int rows, int cols);
    // destructor
    ~GridEnvironment();
    void printGrid();
    list<Particle> returnEntities(); 
    void step(); 
    float calcActionForce(); 
    float calcEnvironmentForce(); 
    vector<float> getCollisionForce(Particle a, Particle b); 
    void updateAgentState(list<Particle> agents); 


};

#endif
