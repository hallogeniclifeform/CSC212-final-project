#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

int main(int argc, char *argv[]) {

    int rows = std::stoi(argv[1]);
    int cols = std::stoi(argv[2]);
    int random;
    std::srand(std::stoi(argv[4]));

    std::vector< std::vector<int> > matrix;
    std::vector<int> row;

    std::string out_fname = argv[3];
    std::ofstream out_file(out_fname);

    for (int i=0; i<rows; i++) {
        row.clear();
        for (int j=0; j<cols; j++) {
            random = (rand() % 85) + 1;
            if (random > 9) {
                row.push_back(0);
            } else {
                row.push_back(random);
            }
        }
        matrix.push_back(row);
    }

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            out_file << matrix[i][j] << " ";
        }
        out_file << std::endl;
    }
        

    return 0;
}