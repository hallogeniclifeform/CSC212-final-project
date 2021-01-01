#include "node.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

//base matrix constructor with all values set to zero.
Matrix::Matrix(){
    this->head = new ElementNode();
}

//matrix constructor where number of rows and columns are known.
Matrix::Matrix(int rows, int cols) {
    HeaderNode* temp;
    this->head = new ElementNode();
    for (int i=0; i<rows; i++) {
        if (this->head->down == nullptr) {
            this->head->down = new HeaderNode(i, "row");
        } else {
            temp = this->head->down;
            temp->down = new HeaderNode(i, "row");
        }
    }
    for (int i=0; i<cols; i++){
        if(this->head->right == nullptr) {
            this->head->right = new HeaderNode(i, "col");
        } else {
            temp = this->head->right;
            temp->right = new HeaderNode(i, "col");
        }
    }
}


Matrix::~Matrix(){

}

/*
//function to push non-zero values of sparse matrix into linked list.
void Matrix::push_back(int data, int row, int col){
    if(this->head == nullptr){
        this->head = new Node(data, row, col);
    }else{
        Node* tmp = this->head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(data, row, col);
    }
    this->size++;
}*/


Matrix Matrix::add_to(Matrix mat){
    Matrix sum;

    return sum;
};

Matrix Matrix::cross_product(Matrix mat){
    Matrix product;

    return product;
}

Matrix Matrix::subtract_from(Matrix mat){
    Matrix diff;

    return diff;
}


//function to output the product/sum/etc. of two sparse matrices to the console.
void Matrix::print_matrix(){
    
    std::vector< std::vector< int > > print_array;
    std::vector< int > row;
    Node* temp = this->head;
    int rows = this->head->row;
    int cols = this->head->col;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            
        }
    }

    

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << print_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//function to save product/sum/etc. of two sparse matrices to a new .txt file.
void Matrix::save_matrix(std::string filename) {
    std::ofstream out_file(filename);
    Node* temp = this->head;

    out_file << this->rows << " " << this->cols << std::endl;

    for (int i=0; i<this->size; i++) {
        out_file << temp->row << " " << temp->col << " " << temp->data << std::endl;
        temp = temp->next;
    }

}


