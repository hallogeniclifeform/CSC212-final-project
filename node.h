#pragma once

#include <iostream>

class Node{
    private:
        //private data members for each node.
        int row;
        int col;
        
    public:
        //constructor for each node.
        Node();
        ~Node();
        Node(int row, int col);
        //functions to set node members
        void set_row(int row);
        void set_col(int col);
        //functions to get different node members.
        int get_row();
        int get_col();
};


class ElementNode: public Node {
    private:
        int data;
        ElementNode* right;
        ElementNode* down;
        HeaderNode* row_header;
        HeaderNode* col_header;
    
    public:
        ElementNode();
        ~ElementNode();
        ElementNode(int row, int col, int data);      

        // accessors
        ElementNode* get_right();
        ElementNode* get_right(int row, int col);
        ElementNode* get_down();
        ElementNode* get_down(int row, int col);

        HeaderNode* get_row_header();
        HeaderNode* get_row_header(int row);
        HeaderNode* get_col_header();
        HeaderNode* get_col_header(int col);


};


class HeaderNode: public Node {
    private:
        ElementNode* next;
        bool isRowHeader;
        bool isColHeader = !isRowHeader;

    public:
        HeaderNode();
        ~HeaderNode();
        HeaderNode(int index, std::string type);
};