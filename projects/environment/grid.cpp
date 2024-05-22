#include <iostream>
#include <list>
#include "particle.h"
#include "grid.h"

using namespace std;

class GridEnvironment{ 

    public: 
        // list of items in env (entities not included yet)
        list<Particle> agents; 
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

        list<Particle> returnEntities(){return agents;}

        void step(){

        }

        float calcActionForce(){
            return 0.0; 
        }

        float calcEnvironmentForce(){
            return 0.0; 
        }

        vector<float> getCollisionForce(Particle a, Particle b){
            return {0,0}; 
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