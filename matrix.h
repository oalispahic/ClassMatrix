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
    int *element_number_row;

    void redirect(matrix &&temp) {
        data = temp.data;
        row = temp.col;
        col = temp.row;
    }

public:
    matrix() : row(3), col(3) {

        data = new(std::nothrow) double *[row];
        element_number_row = new int[col];
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
            *element_number_row = row;
            ++element_number_row;
        }
        element_number_row-=row;


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

    matrix(std::initializer_list<std::initializer_list<double>> const &list_data) {
        int size = list_data.size();
        row = list_data.size();
        col = list_data.begin()->size();
        data = new(std::nothrow) double *[size];
        if (!data) {
            std::cerr << "Memory allocation failed";
            std::terminate();
        }

        element_number_row = new int [row];

        for (int i = 0; i < size; i++) {
            auto inner_data = list_data.begin() + i;
            auto num = inner_data->begin();
            int inner_size = inner_data->size();
            *element_number_row = inner_size;
            data[i] = new double[inner_size];
            for (int j = 0; j < inner_size; j++) {
                data[i][j] = *num;
                num++;
            }
            if (col < inner_size) col = inner_size;
            ++element_number_row;
        }
        element_number_row-=row;

        std::cout<<"THIS IS YOUR ROW SIZE"<<row<<std::endl;
        std::cout<<"THIS IS YOUR COL SIZE"<<col<<std::endl;
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
            for (int j = 0; j < element_number_row[i] ;j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

#endif //CLASSMATRIX_MATRIX_H
