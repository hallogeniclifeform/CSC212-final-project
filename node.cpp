#include "node.h"

Node::Node(){
    this->data = 0;
    this->row = 0;
    this->col = 0;
    this->right = nullptr;
    this->down = nullptr;
}

Node::~Node(){
    if(this->right != nullptr){
        delete this->right;
        delete this->down;
    }
}

Node::Node(int data){
    this->data = data;
    this->row = 0;
    this->col = 0;
    this->right = nullptr;
    this->down = nullptr;
}

Node::Node(int data, Node* right, Node* down){
    this->data = data;
    this->row = 0;
    this->col = 0;
    this->right = right;
    this->down = down;
}

Node::Node(int data, int row, int col, Node* right, Node* down) {
    this->data = data;
    this->row = row;
    this->col = col;
    this->right = right;
    this->down = down;
}