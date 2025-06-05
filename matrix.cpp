#include "matrix.h"

#include <iostream>
#include <vector>
int main(){
   /* matrix matrica = matrix(5,6,1);
    matrica.print();
    std::cout<<std::endl;
    auto number = matrica.nth(31);
    std::cout<<(number);*/

   matrix test = {{1,2,3},
                  {3,6,3},
                  {1,9,5,4}};
   test.print();
   std::cout<<std::endl;
   matrix test2;
   test2.print();



    return 0;
}
