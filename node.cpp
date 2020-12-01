#include "node.h"

Node::Node(){
    this->data = 0;
    this->next = nullptr;
}

Node::~Node(){
    if(this->next != nullptr){
        delete this->next;
    }
}

Node::Node(int data, int row, int col){
    this->data = data;
    this->next = nullptr;
}

Node::Node(int data, int row, int col, Node* next){
    this->data = data;
    this->next = next;
}
