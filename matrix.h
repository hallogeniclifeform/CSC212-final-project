#include "node.h"
#include <vector>
#include <string>

class Matrix{
    private:
        Node* head;

    public:
        Matrix();
        ~Matrix();
        Matrix(int rows, int cols);
        
        void add_header(int row, int col);
        void add_element(HeaderNode row, HeaderNode col, int data);
        void add_element(int row, int col, int data);
        
        Matrix add_to(Matrix mat);
        Matrix cross_product(Matrix mat);
        Matrix subtract_from(Matrix mat);

        void print_matrix();
};