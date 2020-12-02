#include <iostream>
#include <string>
#include "matrix.h"
#include "matrixMath.h"

Matrix add_matrix(Matrix mat1, Matrix mat2);

int main(int argc, char** argv){
    int sparse_array_one[5][4] =
    {{0, 0, 0, 6},
    {9, 0, 2, 4},
    {1, 0, 4, 3},
    {0, 0, 0, 0},
    {2, 3, 4, 5}};

    int sparse_array_two[4][4] =
    {{0, 0, 0, 0},
    {3, 0, 2, 4},
    {3, 0, 2, 0},
    {0, 0, 9, 0}
    };

    Matrix matrix_one = Matrix(5, 4);
    Matrix matrix_two = Matrix(4, 4);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            if(sparse_array_one[i][j] != 0){
                matrix_one.push_back(sparse_array_one[i][j], i, j);
            }
            if(sparse_array_two[i][j] != 0){
                matrix_two.push_back(sparse_array_two[i][j], i, j);
            }
        }
    }

    Matrix sum = add_matrix(matrix_one, matrix_two);
    std::string sum_string = sum.to_string();



    /*std::string my_string_one = matrix_one.to_string();
    std::string my_string_two = matrix_two.to_string();

    std::cout << "matrix one: " << my_string_one << std::endl;
    std::cout << "matrix two: " << my_string_two << std::endl;

    int size_one = matrix_one.get_size();
    int size_two = matrix_two.get_size();

    std::cout << "This is the amount of non-zero elements in sparse matrix one: " << size_one << std::endl;
    std::cout << "This is the amount of non-zero elements in sparse matrix two: " << size_two << std::endl;*/






    //12/2/2020 3:33 am
    //added a add fucntion in matrix.cpp, we can try to fit it in a math.h file for the matrices, seems to work for all values that are not in the first column or last row
    //of the two matrices. For everything else it adds correctly, but for values in the first column/first row it simply
    //lists both values seperately. Probabaly something in the first if statement.


}




Matrix add_matrix(Matrix mat1, Matrix mat2){

    Matrix sum = Matrix();

    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
        std::cout << "Must be same size to add" << std::endl;
        return sum;
    }


    Node* temp1 = mat1.get_head();
    Node* temp2 = mat2.get_head();

    while(temp1 != nullptr && temp2 != nullptr){
        if((temp1->get_row() == temp2->get_row()) && (temp1->get_col() == temp2->get_col())){
            sum.push_back((temp1->get_data() + temp2->get_data()), temp1->get_row(), temp1->get_col());
            temp1 = temp1->get_next();
            temp2 = temp2->get_next();

        } else if(temp1->get_row() == temp2->get_row()){
            if(temp1->get_col() < temp2->get_col()){
                sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        } else if(temp1->get_row() != temp2->get_row()){
            if(temp1->get_row() < temp2->get_row()){
                sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        }

    }

    while(temp2 != nullptr){
        sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
        temp2 = temp2->get_next();


    }
    while(temp1 != nullptr){
        sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
        temp1 = temp1->get_next();
    }
    return sum;

}