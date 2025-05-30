# ClassMatrix

Library which models a mathematical matrix in C++


This library is used to simply create a matrix and manipulate it.

Features:

-Clean syntax

-Easy to use

-Mathematical methods

-Uses C-style arrays dynamically allocated so its fast


Overview:

Right now the library has a default constructor which creates a 3x3 null matrix.

A constructor which accepts the dimensions of a matrix and an optional value to fill in the matrix

To create a matrix simply write:

matrix matrixName(); -----> Creates a 3x3 null matrix

matrix matrixName(5,5) -----> Creates a 5x5 null matrix

matrix matrixName(6,6,5) -----> Creates a 6x6 matrix with all 6 elements


Built in print() method for a nice and easy way of printing a matrix

matrixName.print(); -----> Prints out the matrix

Supports .at() method similar to how std::vector does it, can chain .at() and throws range_error if out of index range 

Supports .size() for returning size of current row/colum


Work in progress:

Overloading operators "<" ">" "=" "==" "[]" "+" "-" "*" 

.inverse() method for an instant inverted matrix

.resize() for dynamically resizing the matrix

.identity for transforming a matrix into identity matrix

and much more...


Who am I?:

Im Omar, a software engineering student working on cool micro-libraries and low level C++ experiments.
 This is a part of my learning journey and portofolio and I'm having a blast building it.

