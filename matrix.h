#include "node.h"
#include <vector>
#include <string>

class Matrix{
    private:
        Node* head;
        unsigned int size;

    public:
        Matrix();
        ~Matrix();

        void insert(int data, int row, int col);
        void remove(int data);
        bool contains(int data);
        int get_size();
        std::string to_string();
};
