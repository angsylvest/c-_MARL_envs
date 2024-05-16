#include <iostream>

using namespace std;

class GridEnvironment{ 

    public: 
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