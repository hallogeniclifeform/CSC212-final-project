#pragma once

class Node{
    private:
        //private data members for each node.
        int data;
        int row;
        int col;
        Node* next;

        friend class Matrix;
    public:
        //constructor for each node.
        Node();
        ~Node();
        Node(int data, int row, int col);
        //functions to retrieve different node members.
        int get_data();
        int get_row();
        int get_col();

        Node* get_next();
};