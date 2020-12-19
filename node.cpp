#include "node.h"


//base constructor for node.
Node::Node(){
    this->data = 0;
    this->next = nullptr;
}


//node destructor.
Node::~Node(){
    if(this->next != nullptr){
        delete this->next;
    }
}

//node constructor with arguments for row, column, and value of non-zero elements in sparse matrix.
Node::Node(int data, int row, int col){
    this->data = data;
    this->row = row;
    this->col = col;
    this->next = nullptr;
}

//functions for retrieving private data members of the node class.
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