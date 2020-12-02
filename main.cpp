#include <iostream>
#include <string>
#include "matrix.h"


int main(int argc, char** argv){
    int sparse_matrix[4][4] =
    {{0, 0, 0, 6},
    {9, 0, 2, 4},
    {1, 0, 4, 3},
    {0, 0, 0, 0}};

    Matrix matrix = Matrix();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(sparse_matrix[i][j] != 0){
                matrix.push_back(sparse_matrix[i][j], i, j);
                std::cout << "pushed baby" << std::endl;
                std::string mystring = matrix.to_string();
                std::cout << mystring << std::endl;
            }
            
        }
    }











}


