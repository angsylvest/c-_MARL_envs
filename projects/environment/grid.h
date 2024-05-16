#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

class GridEnvironment {
public:
    int num_rows;
    int num_cols;
    int** arrayxy;

    // constructor 
    GridEnvironment(int rows, int cols);

    // destructor
    ~GridEnvironment();

    void printGrid();
};

#endif
