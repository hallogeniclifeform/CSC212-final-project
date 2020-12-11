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
    this->row = row;
    this->col = col;
    this->next = nullptr;
}

int Node::get_data() {
    return this->data;
}

int Node::get_row() {
    return this->row;
}

int Node::get_col() {
    return this->col;
}

Node* Node::get_next() {
    return this->next;
}