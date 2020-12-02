#include <iostream>
#include <string>
#include "matrix.h"
#include "matrixMath.h"


int main(int argc, char** argv){
    int sparse_array_one[4][4] =
    {{0, 0, 0, 6},
    {9, 0, 2, 4},
    {1, 0, 4, 3},
    {0, 0, 0, 0}};

    int sparse_array_two[4][4] =
    {{0, 0, 0, 0},
    {3, 0, 2, 4},
    {3, 0, 2, 0},
    {0, 0, 9, 0}};

    Matrix matrix_one = Matrix();
    Matrix matrix_two = Matrix();
    Matrix matrix_three = Matrix();

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(sparse_array_one[i][j] != 0){
                matrix_one.push_back(sparse_array_one[i][j], i, j);
            }
            if(sparse_array_two[i][j] != 0){
                matrix_two.push_back(sparse_array_two[i][j], i, j);
            }            
        }
    }

    matrix_three.add_matrix(matrix_one, matrix_two);

    

    /*std::string my_string_one = matrix_one.to_string();
    std::string my_string_two = matrix_two.to_string();

    std::cout << "matrix one: " << my_string_one << std::endl;
    std::cout << "matrix two: " << my_string_two << std::endl;

    int size_one = matrix_one.get_size();
    int size_two = matrix_two.get_size();

    std::cout << "This is the amount of non-zero elements in sparse matrix one: " << size_one << std::endl;
    std::cout << "This is the amount of non-zero elements in sparse matrix two: " << size_two << std::endl;*/
}



    
    
    //12/2/2020 3:33 am
    //added a add fucntion in matrix.cpp, we can try to fit it in a math.h file for the matrices, seems to work for all values that are not in the first column or last row
    //of the two matrices. For everything else it adds correctly, but for values in the first column/first row it simply
    //lists both values seperately. Probabaly something in the first if statement. 


}


