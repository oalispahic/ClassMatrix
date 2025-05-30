//*******************************************
// Created by Omar Alispahic on 30. 5. 2025.
//              ~ClassMatrix~
//*******************************************

#ifndef CLASSMATRIX_MATRIX_H
#define CLASSMATRIX_MATRIX_H

#include <iostream>
#include <stdexcept>

class rowCheck{
private:
    double *row_data;
    int cols;
public:
    rowCheck(double *row_data, int cols): row_data(row_data), cols(cols){}
    int size() const {return cols;}
    double& at(int j) {
        return row_data[j];
    }
    operator double*(){
        return row_data;
    }
};



class matrix {
private:
    int row, col;
    double **data;
public:
    matrix() : row(3), col(3) {
        data = new double *[row];
        for (int i = 0; i < row; i++) {
            data[i] = new double[col];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }

    }

    matrix(int row, int col, double value = 0) : row(row), col(col) {
        data = new double *[row];
        for (int i = 0; i < row; i++) {
            data[i] = new double[col];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = value;
            }
        }

    }

    ~matrix() {
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    int size() const {
        return row;
    }

    rowCheck at(int i){
        if(i>col) throw std::range_error("Index out of range");
        return rowCheck(data[i],col);
    }

    void print() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //CLASSMATRIX_MATRIX_H
