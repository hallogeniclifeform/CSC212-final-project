#include "node.h"
#include <vector>
#include <string>

class Matrix{
    private:
        Node* head;
        int size;
        int rows;
        int cols;

    public:
        Matrix();
        ~Matrix();
        Matrix(int data);
        Matrix(int rows, int cols);
        
        void push_back(int data, int row, int col);
        int get_size();
        int get_rows();
        int get_cols();
        Node* get_head();
        void print_matrix(int rows, int cols, std::string type);
};