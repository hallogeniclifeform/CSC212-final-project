#include "node.h"


//base constructor for node.
Node::Node(){
    this->row = 0;
    this->col = 0;
}


//node constructor with arguments for row, column, and value of non-zero elements in sparse matrix.
Node::Node(int row, int col){
    this->row = row;
    this->col = col;
    
}



//functions for retrieving private data members of the node class.
int Node::get_row() {
    return this->row;
}

int Node::get_col() {
    return this->col;
}



ElementNode::ElementNode(){
    
}

ElementNode::ElementNode(int row, int col, int data) {
    this->data = data;

    this->right = get_right(row, col);
    this->down = get_down(row, col);

    this->row_header = get_row_header(row);
    this->col_header = get_col_header(col);
}

ElementNode* ElementNode::get_right(){
    return this->right;
}

ElementNode* ElementNode::get_right(int row, int col){
    //find the node to the right
    //if no node to the right, return nullptr
}

ElementNode* ElementNode::get_down(){
    return this->down;
}

ElementNode* ElementNode::get_down(int row, int col){
    //find node below
    //if no node below, return nullptr
}

