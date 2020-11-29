#include "matrix.h"
#include <iostream>

Matrix::Matrix(){
    this->head = nullptr;
    this->size = 0;
}

Matrix::~Matrix(){
    if (this->head){
        delete this->head;
    }
}




void Matrix::insert(int data, int row, int col){
    /*if(!this->head){    // this->head == nullptr
        this->head = new Node(data);
    }else if(idx == 0){
        this->push_front(data);
        return;
    }else if(this->size < idx){
        this->push_back(data);
        return;
    }else{
        Node* tmp = this->head;
        while(idx > 1){
            tmp = tmp->right;
            idx--;
        }
        Node* tmp2 = new Node(data);
        tmp2->right = tmp->right;
        tmp->right = tmp2;
    }*/
    this->size++;
}

void Matrix::remove(int data){
    Node* tmp = this->head;
    Node* prev = nullptr;

    while(tmp != nullptr && tmp->data != data){
        prev = tmp;
        tmp = tmp->right;
    }

    //Hunter's code
    
    if(tmp != nullptr){
        prev->right = tmp->right;
        // Without this, the Node destructor will delete
        // every element in the list after 'temp'
        tmp->right = nullptr;
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
        tmp = tmp->right;
    }

    return false;
}

int Matrix::get_size(){
    return this->size;
}

std::string Matrix::to_string(){
    std::string stringified;
    Node* tmp = this->head;

    while(tmp != nullptr){
        stringified += std::to_string(tmp->data) + " ";
        tmp = tmp->right;
    }

    return stringified;
}
