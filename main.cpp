#include <iostream>
#include <string>
#include <vector>
#include "matrix.h"
#include <fstream>
#include <sstream>

Matrix add_matrix(Matrix mat1, Matrix mat2);
Matrix subtract_matrix(Matrix mat1, Matrix mat2);
Matrix mult_matrix(Matrix mat1, Matrix mat2);

int main(int argc, char** argv){

    if (argc != 4) {
        std::cout << "USAGE: [file 1] [file 2] [operation type]" << std::endl;
        exit(1);
    }

    std::fstream matrix_file_one(argv[1]);              // filestream containing matrix 1
    std::fstream matrix_file_two(argv[2]);              // filestream containing matrix 2
    std::string operation_type = argv[3];

    // 2-d vectors to load in the matrices
    std::vector<std::vector<int>> sparse_matrix_one;    
    std::vector<std::vector<int>> sparse_matrix_two;

    int row1 = 0, row2 = 0;
    int col1 = 0, col2 = 0;
    std::string tempString;
    int num;

    // Load filestream into vector 1
    while(std::getline(matrix_file_one, tempString)){
        std::vector<int> row;
        std::stringstream ss(tempString);
        while(ss >> num){
            row.push_back(num);
            col1++;
        }
        sparse_matrix_one.push_back(row);
        row1++;
    }
    col1 /= row1;

    // Load filestream into vector 2
    while(std::getline(matrix_file_two, tempString)){
        std::vector<int> row;
        std::stringstream ss(tempString);
        while(ss >> num){
            row.push_back(num);
            col2++;
        }
        sparse_matrix_two.push_back(row);
        row2++;
    }
    col2 /= row2;

    // Initialize Matrix objects with the row/col counts (to check for operability)
    Matrix matrix_one = Matrix(row1, col1);
    Matrix matrix_two = Matrix(row2, col2);

    /* 12/6/2020:
     * had to split up nested for loop for each matrix because differing sizes of matrices (5x4 matrix and 4x5 matrix) breaks the program
     * and doesnt even run;
     * added row1,col1, etc above in main to lessen the amount of hardcoding necessary.
     * also added file reading, with command line arguments. first two are the two text files while the third one is operation type. ("add or multiply")
     */

    // Load vectors into Matrix objects
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            if(sparse_matrix_one[i][j] != 0){
                matrix_one.push_back(sparse_matrix_one[i][j], i, j);
            }
        }
    }

    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            if(sparse_matrix_two[i][j] != 0){
                matrix_two.push_back(sparse_matrix_two[i][j], i, j);
            }
        }
    }

    // Operate on matrices based on the op specified
    // EDIT: I edited to foolproof for typos (as long as the first letter is right)
    if (operation_type[0] == 'm'){
        Matrix product = mult_matrix(matrix_one, matrix_two);
        product.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
    } else if (operation_type[0] == 'a'){
        Matrix sum = add_matrix(matrix_one, matrix_two);
        sum.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
    } else if(operation_type[0] == 's'){
        Matrix difference = subtract_matrix(matrix_one, matrix_two);
        difference.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
    } else {
        // If the operation
        std::cout << "Operation types: (m)ultiply, \n"
                  << "                 (a)dd, \n"
                  << "                 (s)ubtract" << std::endl;
        exit(1);
    }
}


Matrix add_matrix(Matrix mat1, Matrix mat2){

    Matrix sum = Matrix();

    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
        std::cout << "Matrices must be same size to add" << std::endl;
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

Matrix subtract_matrix(Matrix mat1, Matrix mat2){
    Matrix difference = Matrix();

    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
        std::cout << "Matrices must be same size to subtract" << std::endl;
        return difference;
    }

    Node* temp1 = mat1.get_head();
    Node* temp2 = mat2.get_head();

    while(temp1 != nullptr && temp2 != nullptr){
        if((temp1->get_row() == temp2->get_row()) && (temp1->get_col() == temp2->get_col())){
            difference.push_back((temp1->get_data() - temp2->get_data()), temp1->get_row(), temp1->get_col());
            temp1 = temp1->get_next();
            temp2 = temp2->get_next();

        } else if(temp1->get_row() == temp2->get_row()){
            if(temp1->get_col() < temp2->get_col()){
                difference.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        } else if(temp1->get_row() != temp2->get_row()){
            if(temp1->get_row() < temp2->get_row()){
                difference.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        }

    }

    while(temp2 != nullptr){
        difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
        temp2 = temp2->get_next();


    }
    while(temp1 != nullptr){
        difference.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
        temp1 = temp1->get_next();
    }
    return difference;
}



Matrix mult_matrix(Matrix mat1, Matrix mat2) {
    // Initialize the Matrix to return
    Matrix product = Matrix(mat1.get_rows(), mat2.get_rows());
    int val = 0;                    // The value to pass to the product Matrix
    int prod_row, prod_col;         // The indices of the row and column to push the value to

    Node* temp1 = mat1.get_head();  // The Node to check from matrix 1
    Node* temp2 = mat2.get_head();  // The Node to check from matrix 2

    std::vector<Node*> mat1_rows;   // A vector to store the values in the specified row from matrix 1
    std::vector<Node*> mat2_cols;   // A vector to store the values in the specified column from matrix 2
    int j = 0, k = 0;               // The indices of the row/column vectors for the nested for-loop


    // In the event the product cannot be calculated, throw an error and exit the program
    if (mat1.get_rows() != mat2.get_cols() || mat1.get_cols() != mat2.get_rows()){
        std::cout << "Improper matrix dimensions for multiplication" << std::endl;
        exit(1);
    }


    for (prod_row=0; prod_row<mat1.get_rows(); prod_row++){

        //Reinitialize the value for temp1, and clear the row vector
        temp1 = mat1.get_head();
        mat1_rows.clear();

        while(temp1 != nullptr) {
            // If the row of the Node matches the row of the index in the product matrix
            // we are calculating, add it to the vector
            if (temp1->get_row() == prod_row)
            {
                mat1_rows.push_back(temp1);
            }
            temp1 = temp1->get_next();


        }
        for (prod_col=0; prod_col<mat2.get_cols(); prod_col++) {
            // Reinitialize the values for temp2 and val, and clear the column vector
            temp2 = mat2.get_head();
            mat2_cols.clear();
            val=0;

            while(temp2 != nullptr) {
                // If the column of the Node matches the column of the index in the product matrix
                // we are calculating, add it to the vector
                if (temp2->get_col() == prod_col) {
                    mat2_cols.push_back(temp2);

                }
                temp2 = temp2->get_next();
            }


            for (j=0; j<mat1_rows.size(); j++) {
                for (k=0; k<mat2_cols.size(); k++) {
                    if (mat1_rows[j]->get_col() == mat2_cols[k]->get_row()) {

                        // If the column index of the Node from the first matrix matches the row index of the second,
                        // multiply and add to the value to be passed to the product matrix
                        val += mat1_rows[j]->get_data() * mat2_cols[k]->get_data();
                        
                    }
                }
            }
            // Push the value to the product matrix
            product.push_back(val, prod_row, prod_col);

        }
    }

    
    return product;
}