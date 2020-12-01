#pragma once

class Node{
    private:
        int data;
        int row;
        int col;
        Node* next;

        friend class Matrix;
    public:
        Node();
        ~Node();
        Node(int data, int row, int col);
        Node(int data, int row, int col, Node* next);
};