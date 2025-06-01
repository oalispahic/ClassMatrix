#include "matrix.h"

#include <iostream>
#include <vector>
int main(){
    matrix matrica = matrix(5,6,0);
    matrica.print();
    std::cout<<std::endl;
    auto number = matrica.nth(31);
    std::cout<<(number);


    return 0;
}
