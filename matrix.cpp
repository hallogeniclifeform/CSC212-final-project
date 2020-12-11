#include "node.h"
#include "matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>

Matrix::Matrix(){
    this->head = nullptr;
    this->size = 0;
    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(int rows, int cols) {
    this->head = nullptr;
    this->size = 0;
    this->rows = rows;
    this->cols = cols;
}

Matrix::Matrix(std::string filename) {
    std::ifstream filein(filename);
    int data, row, col;
	std::string line;

    int val;

    while(std::getline(filein, line)) {
        std::istringstream ss(line);
        ss >> this->rows;
        ss >> this->cols;
        while(std::getline(filein, line)) {
            std::istringstream iss(line);
            while(iss >> row >> col >> data) {
                this->push_back(data, row, col);

            }
        }
    }

    filein.close();
}

Matrix::~Matrix(){

}



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
}

Node* Matrix::get_head() {
    return this->head;
}


int Matrix::get_size(){
    return this->size;
}

int Matrix::get_rows() {
    return this->rows;
}

int Matrix::get_cols() {
    return this->cols;
}

void Matrix::print_matrix(int rows, int cols, std::string type){
    int print_array[rows][cols];
    Node* temp = this->head;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(temp->row == i && temp->col == j){
                print_array[i][j] = temp->data;
                if(temp->next != nullptr){
                    temp = temp->next;
                }
            }else{
                print_array[i][j] = 0;
            }
        }
    }

    if(type == "a"){
        std::cout << std::endl;
        std::cout << "The sum of the two matrices is: " <<  std::endl;
        std::cout << "-------------------------------" << std::endl;
    }else if(type == "m"){
        std::cout << std::endl;
        std::cout << "The product of the two matrices is: " <<  std::endl;
        std::cout << "-------------------------------" << std::endl;
    }else if(type == "s"){
        std::cout << std::endl;
        std::cout << "The difference of the two matrices is: " <<  std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << print_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::save_matrix(std::string filename) {
    std::ofstream out_file(filename);
    Node* temp = this->head;

    out_file << this->rows << " " << this->cols << std::endl;

    for (int i=0; i<this->size; i++) {
        out_file << temp->row << " " << temp->col << " " << temp->data << std::endl;
        temp = temp->next;
    }

}


