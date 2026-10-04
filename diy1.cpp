#include <iostream>
#include <stdexcept>

class DynamicMatrix {
private:
    int rows;
    int cols;
    int** data;

    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{0};
        }
    }

  
    void freeMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    
    DynamicMatrix(int m, int n) : rows(m), cols(n), data(nullptr) {
        if (m <= 0 || n <= 0) {
            throw std::invalid_argument("Matrix dimensions must be greater than zero.");
        }
        allocateMemory();
    }

 
    DynamicMatrix(const DynamicMatrix& other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j]; 
            }
        }
    }

   
    DynamicMatrix& operator=(const DynamicMatrix& other) {
        if (this != &other) {
            freeMemory();     
            rows = other.rows;
            cols = other.cols;
            allocateMemory(); 

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

   
    ~DynamicMatrix() {
        freeMemory();
    }

    
    int& at(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[r][c];
    }

    
    int at(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            throw std::out_of_range("Index out of bounds.");
        }
        return data[r][c];
    }

   
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
   
    DynamicMatrix mat1(2, 3);
    mat1.at(0, 0) = 1;
    mat1.at(0, 1) = 2;
    mat1.at(0, 2) = 3;
    
    std::cout << "Matrix 1:\n";
    mat1.print();

   
    DynamicMatrix mat2 = mat1; 
    mat2.at(1, 1) = 99; 

    std::cout << "\nMatrix 1 (After modifying Matrix 2):\n";
    mat1.print();

    std::cout << "\nMatrix 2 (Copied and modified):\n";
    mat2.print();

    return 0;
}
