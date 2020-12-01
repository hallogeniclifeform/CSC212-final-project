#include "node.h"
#include <vector>
#include <string>

class Matrix{
    private:
        Node* head;
        int size;
        
    public:
        Matrix(); //this->head = nullptr;
        Matrix(int data);
        Matrix(int data,int vec);
        
        void push_front(int data);
        void push_back(int data);
        void insert(int data, int idx);
        void remove(int data);
        bool contains(int data);
        int get_size();
        std::string to_string();
        //etc
};