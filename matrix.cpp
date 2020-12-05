#include "node.h"
#include "matrix.h"
#include <iostream>

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

/*void Matrix::add_matrix(Matrix matrix_one, Matrix matrix_two){
    Matrix matrix_three = Matrix();
    Node* temp1 = matrix_one.head;
    Node* temp2 = matrix_two.head;

    while(temp1 != nullptr && temp2 !=nullptr){
        if((temp1->row == temp2->row) && (temp1->col && temp2->col)){
            matrix_three.push_back((temp1->data + temp2->data), temp1->row, temp1->col);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if(temp1->row == temp2->row){
            if(temp1->col < temp2->col){
                matrix_three.push_back(temp1->data, temp1->row, temp1->col);
                temp1 = temp1->next;
            }else{
                matrix_three.push_back(temp2->data, temp2->row, temp2->col);
                temp2 = temp2->next;
            }
        }else if(temp1->row != temp2->row){
            if(temp1->row < temp2->row){
                matrix_three.push_back(temp1->data, temp1->row, temp1->col);
                temp1 = temp1->next;
            }else{
                matrix_three.push_back(temp2->data, temp2->row, temp2->col);
                temp2 = temp2->next;
            }
        }
    }
    matrix_three.to_string();

}*/

/*
void Matrix::insert(int data, int row, int col){
    if(!this->head){    // this->head == nullptr
        this->head = new Node(data, idx, col);
    }else if(idx == 0){
        this->push_front(data);
        return;
    }else if(this->size < idx){
        this->push_back(data);
        return;
    }else{
        Node* tmp = this->head;
        while(idx > 1){
            tmp = tmp->next;
            idx--;
        }
        Node* tmp2 = new Node(data);
        tmp2->next = tmp->next;
        tmp->next = tmp2;
    }
    this->size++;
}

 void Matrix::remove(int data){
    Node* tmp = this->head;
    Node* prev = nullptr;

    while(tmp != nullptr && tmp->data != data){
        prev = tmp;
        tmp = tmp->next;
    }

    if(tmp != nullptr){
        prev->next = tmp->next;
        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->next = nullptr;
        delete tmp;

        this->size--;
    }else{
        std::cout << data << " does not exist!" << std::endl;
    }
}
 bool Matrix::contains(int data){
    Node* tmp = this->head;

    while(tmp != nullptr){
        if(tmp->data == data){
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}
*/
int Matrix::get_size(){
    return this->size;
}

int Matrix::get_rows() {
    return this->rows;
}

int Matrix::get_cols() {
    return this->cols;
}



void Matrix::to_string(int rows, int cols){
    //std::string stringified;
    int print_array[rows][cols];
    Node* temp = this->head;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(temp->row == i && temp->col == j){
                print_array[i][j] = temp->data;
                //issue might be here with printing matrix
                temp = temp->next;
            }else{
                print_array[i][j] = 0;
            }
        }
    }



    //while(temp != nullptr){


        //stringified += std::to_string(tmp->data) + " "; // + std::to_string(tmp->row) + " " + std::to_string(tmp->col) << " ";
        //temp = temp->next;
    //}

    std::cout << std::endl;
    std::cout << "Your Matrix: " <<  std::endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            std::cout << print_array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //std::cout << rows << " and " << cols << std::endl;



    //std::cout << stringified << std::endl;
       
}


