#include "node.h"
#include <vector>
#include <string>

class Matrix{
    private:
        Node* head;
        int size;
        
    public:
        Matrix(); //this->head = nullptr;
        ~Matrix(); 
        Matrix(int data);
        Matrix(int data,int vec);
        
        //void push_front(int data);
        void push_back(int data, int row, int col);

        void add_matrix(Matrix matrix_one, Matrix matrix_two);

        //void insert(int data, int idx);
        void remove(int data);
        bool contains(int data);
        int get_size();
        Node* get_head();
        std::string to_string();
        //etc
};