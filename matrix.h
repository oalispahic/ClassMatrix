//*******************************************
// Created by Omar Alispahic on 30. 5. 2025.
//              ~ClassMatrix~
//*******************************************

#ifndef CLASSMATRIX_MATRIX_H
#define CLASSMATRIX_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <new>
#include <cstdlib>
#include <exception>

class rowCheck {
private:
    double *row_data;
    int cols;
public:
    rowCheck(double *row_data, int cols) : row_data(row_data), cols(cols) {}

    int size() const { return cols; }

    double &at(int j) {
        return row_data[j];
    }

    operator double *() {
        return row_data;
    }
};


class matrix {
private:
    int row, col;
    double **data;
public:
    matrix() : row(3), col(3) {

        data = new(std::nothrow) double *[row];
        if (data == nullptr) {
            std::cerr << "Memory allocation failed";
            std::terminate();
        }
        for (int i = 0; i < row; i++) {
            data[i] = new(std::nothrow) double[col];
            if (data[i] == nullptr) {
                std::cerr << "Memory allocation failed";
                for (int j = 0; j < i; j++) {
                    delete[] data[j];
                }
                delete[]data;
                std::terminate();
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                data[i][j] = 0;
            }
        }


    }

    matrix(int row, int col, double value = 0) : row(row), col(col) {
        data = new(std::nothrow) double *[row];
        if (data == nullptr) {
            std::cerr << "Memory allocation failed";
            std::terminate();
        }
        for (int i = 0; i < row; i++) {
            data[i] = new(std::nothrow) double[col];
            if (data[i] == nullptr) {
                std::cerr << "Memory allocation failed";
                for (int j = 0; j < i; j++) {
                    delete[] data[j];
                }
                delete[]data;
                std::terminate();
            }
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

    auto nth(int i) {
        if (i > row * col) throw std::range_error("Index out of range");
        return *(rowCheck(data[i], col));
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
