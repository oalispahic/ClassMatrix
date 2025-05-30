#include "matrix.h"

#include <iostream>
#include <vector>
int main(){
    matrix matrica = matrix(5,6,1000);
    matrica.print();
    std::cout<<std::endl;
    auto number = matrica.at(1);
    std::vector<std::vector<int>> matrixV (10, std::vector<int>(10,5));
    auto mat = matrixV.at(0).at(0);


    return 0;
}
