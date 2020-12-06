#include <iostream>
#include <string>
#include <vector>
#include "matrix.h"
#include "matrixMath.h"
#include <fstream>
#include <sstream>

Matrix add_matrix(Matrix mat1, Matrix mat2);
Matrix mult_matrix(Matrix mat1, Matrix mat2);

int main(int argc, char** argv){
    std::fstream matrix_file_one(argv[1]);
    std::fstream matrix_file_two(argv[2]);
    std::string operation_type = argv[3];        

    std::vector<std::vector<int>> sparse_matrix_one;
    std::vector<std::vector<int>> sparse_matrix_two;
    std::string tempString;   
    int num;
    while(std::getline(matrix_file_one, tempString)){
        std::vector<int> row;
        std::stringstream ss(tempString);
        while(ss >> num){
            row.push_back(num);
        }
        sparse_matrix_one.push_back(row);
    }

    while(std::getline(matrix_file_two, tempString)){
        std::vector<int> row;
        std::stringstream ss(tempString);
        while(ss >> num){
            row.push_back(num);
        }
        sparse_matrix_two.push_back(row);
    }

    Matrix matrix_one = Matrix(4, 4);
    Matrix matrix_two = Matrix(4, 4);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(sparse_matrix_one[i][j] != 0){
                matrix_one.push_back(sparse_matrix_one[i][j], i, j);
            }
            if(sparse_matrix_two[i][j] != 0){
                matrix_two.push_back(sparse_matrix_two[i][j], i, j);
            }
        }
    }

    if (operation_type == "multiply"){
        Matrix product = mult_matrix(matrix_one, matrix_two);
        product.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
    }else if (operation_type == "add"){
        Matrix sum = add_matrix(matrix_one, matrix_two);
        sum.print_matrix(matrix_one.get_rows(), matrix_two.get_cols(), operation_type);
    }
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


Matrix mult_matrix(Matrix mat1, Matrix mat2) {
    Matrix product;

    Node* temp1 = mat1.get_head();
    Node* temp2 = mat2.get_head();

    std::vector< std::vector<int> > mat1_rows;
    std::vector< std::vector<int> > mat2_cols;
    std::vector<int> topush_rows;
    std::vector<int> topush_cols;
    std::vector<int> prod_mat;
    int val;    


    if (mat1.get_rows() != mat2.get_cols() || mat1.get_cols() != mat2.get_rows()){
        std::cout << "Improper matrix dimensions for multiplication" << std::endl;
        return product;
    }

    for (int i=0; i<mat1.get_rows(); i++){
        while(temp1 != nullptr) {
            if(temp1->get_row() == i) {
                topush_rows.push_back(temp1->get_row());
            } else {
                topush_rows.push_back(0);
            }
            if(temp2->get_col() == i) {
                topush_cols.push_back(temp2->get_col());
            } else {
                topush_cols.push_back(0);
            }
            mat1_rows.push_back(topush_rows);
            mat2_cols.push_back(topush_cols);
        }
    }

    //i corresponts to a(row) and b(col)
    //j corresponds to idx of a(row) and b(col)
    //a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0]
    //val += a[i][j]*b[j][i]

    for (unsigned int i=0; i<mat1_rows.size(); i++){
        val = 0;
        for (unsigned int j=0; j<mat1_rows[i].size(); j++){
            val += mat1_rows[i][j]*mat2_cols[j][i];
        }
        prod_mat.push_back(val);
    }

    // TODO: arrange 1d prod_mat into a 2d array
    

    // TODO: push 2d product array to the product matrix linkedlist;


    return product;
}