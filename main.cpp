#include <iostream>
#include <string>
#include <vector>
#include "matrix.h"
#include <fstream>
#include <sstream>
#include <ctime>

Matrix add_matrix(Matrix mat1, Matrix mat2);
Matrix subtract_matrix(Matrix mat1, Matrix mat2);
Matrix mult_matrix(Matrix mat1, Matrix mat2);

void time_func(Matrix mat1, Matrix mat2, std::vector< std::vector<int> > vec1, std::vector< std::vector<int> > vec2 ) {
    Matrix new_mat;
    unsigned long c_start, c_end;
    float output;
    
    c_start = std::clock();
    new_mat = add_matrix(mat1, mat2);
    c_end = std::clock();

    output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << "Time of Linked List addition:" << std::endl;
    std::cout << output << std::endl;
    
    c_start = std::clock();
    new_mat = mult_matrix(vec1, vec2);
    c_end = std::clock();

    output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    std::cout << "Time of Full Matrix addition:" << std::endl;
    std::cout << output << std::endl;
}



int main(int argc, char** argv){

    if (argc < 4) {
        std::cout << "USAGE: [file 1] [file 2] [operation type]" << std::endl;
        exit(1);
    }

    // Files saved in the Sparse Matrix form are named in the format mat-*.txt
    // Files saved in the Linked List form are named in the format ll-*.txt

    std::string file_one(argv[1]);                  // filename of file containing matrix 1
    std::string file_two(argv[2]);                  // filename of file containing matrix 2
    std::string operation_type = argv[3];
    std::string save_file;
    bool save = false;
    if (argc == 5) {
        save_file = argv[4];
        save = true;
        if (save_file[0] != 'l') {
            std::cout << "Files saved in the Linked List form are named in the format ll-*.txt" << std::endl;
            exit(1);
        }
    }

    Matrix matrix_one;
    Matrix matrix_two;

    // 2-d vectors to load in the matrices
    std::vector<std::vector<int>> sparse_matrix_one;    // 2d vector to load in matrix 1
    std::vector<std::vector<int>> sparse_matrix_two;    // 2d vector to load in matrix 2

    int row1 = 0, row2 = 0;
    int col1 = 0, col2 = 0;
    std::string tempString;
    int num;

    if(operation_type[0] == 'c') {
        if (file_one[0] == 'm') {
            std::fstream matrix_file_one(file_one);             // filestream containing matrix 1

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

            matrix_one = Matrix(row1, col1);

            // Load vectors into Matrix objects
            for(int i = 0; i < row1; i++){
                for(int j = 0; j < col1; j++){
                    if(sparse_matrix_one[i][j] != 0){
                        matrix_one.push_back(sparse_matrix_one[i][j], i, j);
                    }
                }
            }
        } else {
            std::cout << "Files saved in the Sparse Matrix form are named in the format mat-*.txt" << std::endl;
            exit(1);
        }

        if(file_two[0] == 'l'){
            matrix_one.save_matrix(file_two);
        } else {
            std::cout << "Files saved in the Linked List form are named in the format ll-*.txt" << std::endl;
            exit(1);
        }

    } else {

        if(file_one[0] == 'm') {
            std::fstream matrix_file_one(file_one);             // filestream containing matrix 1

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

            matrix_one = Matrix(row1, col1);

            // Load vectors into Matrix objects
            for(int i = 0; i < row1; i++){
                for(int j = 0; j < col1; j++){
                    if(sparse_matrix_one[i][j] != 0){
                        matrix_one.push_back(sparse_matrix_one[i][j], i, j);
                    }
                }
            }

        } else if (file_one[0] == 'l') {
            matrix_one = Matrix(file_one);
        }

        if(file_two[0] == 'm') {
            std::fstream matrix_file_two(file_two);              // filestream containing matrix 2

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
            
            matrix_two = Matrix(row2, col2);

            // Load vectors into Matrix objects
            for(int i = 0; i < row2; i++){
                for(int j = 0; j < col2; j++){
                    if(sparse_matrix_two[i][j] != 0){
                        matrix_two.push_back(sparse_matrix_two[i][j], i, j);
                    }
                }
            }


        } else if (file_two[0] == 'l') {
            matrix_two = Matrix(file_two);
        }

        // Operate on matrices based on the op specified
        // EDIT: I edited to foolproof for typos in the command line (as long as the first letter is right)
        if (operation_type[0] == 'm'){
            Matrix product = mult_matrix(matrix_one, matrix_two);
            product.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
            if(save) {
                product.save_matrix(save_file);
            }
        } else if (operation_type[0] == 'a'){
            Matrix sum = add_matrix(matrix_one, matrix_two);
            sum.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
            if(save) {
                sum.save_matrix(save_file);
            }
        } else if(operation_type[0] == 's'){
            Matrix difference = subtract_matrix(matrix_one, matrix_two);
            difference.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
            if(save) {
                difference.save_matrix(save_file);
            }
            
        } else {
            // If the operation
            std::cout << "Operation types: (m)ultiply,\n"
                      << "                 (a)dd,\n"
                      << "                 (s)ubtract\n" 
                      << "                 (c)onvert"<< std::endl;
            exit(1);
        }
    }
}


Matrix add_matrix(Matrix mat1, Matrix mat2){

    // Initialize the matrix to return
    Matrix sum = Matrix();

    Node* temp1 = mat1.get_head();      // The node to check from matrix 1
    Node* temp2 = mat2.get_head();      // The node to check from matrix 2

    // In the event the sum cannot be calculated, throw an error and exit the program
    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
        std::cout << "Matrices must be same size to add" << std::endl;
        exit(1);
    }


    while(temp1 != nullptr && temp2 != nullptr){
        if((temp1->get_row() == temp2->get_row()) && (temp1->get_col() == temp2->get_col())){
            // If both the row and column indices of each Node match, add the values and push them to the new matrix
            sum.push_back((temp1->get_data() + temp2->get_data()), temp1->get_row(), temp1->get_col());
            temp1 = temp1->get_next();
            temp2 = temp2->get_next();

        } else if(temp1->get_row() == temp2->get_row()){
            if(temp1->get_col() < temp2->get_col()){
                // If the row indices match and the column of the first is smaller, push the Node from matrix 1
                sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                // If the row indices match and the column of the second is smaller, push the Node from matrix 2
                sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        } else if(temp1->get_row() != temp2->get_row()){
            if(temp1->get_row() < temp2->get_row()){
                // If the row indices do not match and the column of the first is smaller, push the Node from matrix 1
                sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                // If the row indices do not match and the column of the second is smaller, push the Node from matrix 2
                sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        }

    }

    while(temp2 != nullptr){
        // If the Matrix 1 runs out of Nodes to check, push the remaining Nodes to the new Matrix
        sum.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
        temp2 = temp2->get_next();
    }
    while(temp1 != nullptr){
        // If the Matrix 2 runs out of Nodes to check, push the remaining Nodes to the new Matrix
        sum.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
        temp1 = temp1->get_next();
    }
    return sum;

}

Matrix subtract_matrix(Matrix mat1, Matrix mat2){
    // Initialize the matrix to return
    Matrix difference = Matrix();

    Node* temp1 = mat1.get_head();      // The node to check from matrix 1
    Node* temp2 = mat2.get_head();      // The node to check from matrix 2

    // In the event the sum cannot be calculated, throw an error and exit the program
    if (mat1.get_rows() != mat2.get_rows() || mat1.get_cols() != mat2.get_cols()){
        std::cout << "Matrices must be same size to subtract" << std::endl;
        exit(1);
    }

    while(temp1 != nullptr && temp2 != nullptr){
        if((temp1->get_row() == temp2->get_row()) && (temp1->get_col() == temp2->get_col())){
            // If both the row and column indices of each Node match, subtract the values and push them to the new matrix
            difference.push_back((temp1->get_data() - temp2->get_data()), temp1->get_row(), temp1->get_col());
            temp1 = temp1->get_next();
            temp2 = temp2->get_next();

        } else if(temp1->get_row() == temp2->get_row()){
            if(temp1->get_col() < temp2->get_col()){
                // If the row indices match and the column of the first is smaller, push the Node from matrix 1
                difference.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                // If the row indices match and the column of the second is smaller, push the Node from matrix 2
                difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        } else if(temp1->get_row() != temp2->get_row()){
            if(temp1->get_row() < temp2->get_row()){
                // If the row indices do not match and the column of the first is smaller, push the Node from matrix 1
                difference.push_back(temp1->get_data(), temp1->get_row(), temp1->get_col());
                temp1 = temp1->get_next();
            }else{
                // If the row indices do not match and the column of the second is smaller, push the Node from matrix 2
                difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
                temp2 = temp2->get_next();
            }
        }

    }

    while(temp2 != nullptr){
        // If the Matrix 1 runs out of Nodes to check, push the remaining Nodes to the new Matrix
        difference.push_back(temp2->get_data(), temp2->get_row(), temp2->get_col());
        temp2 = temp2->get_next();


    }
    while(temp1 != nullptr){
        // If the Matrix 2 runs out of Nodes to check, push the remaining Nodes to the new Matrix
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
            if (val!=0){
                product.push_back(val, prod_row, prod_col);
            }
        }
    }

    
    return product;
}