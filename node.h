#pragma once

class Node{
    private:
        int data;
        int row;
        int col;
        Node* right;
        Node* down;


        friend class Matrix;
    public:
        Node();
        ~Node();
        Node(int data);
        Node(int data, Node* right, Node* down);
        Node(int data, int row, int col, Node* right, Node* down);
};