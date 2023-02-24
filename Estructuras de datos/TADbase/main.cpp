#include <iostream>
#include "tad.h"

int main(){
   TAD test;

   test.Alta("A");
   test.Alta("1");
   test.Alta("B");
   test.Alta("M");
   test.Alta("9");

   std::cout<<"Elements in test TAD"<<std::endl;
   test.printElements();

   std::cout<<"\nOrder Elements"<<std::endl;
   test.orderElements();
   test.printElements();

    std::cout<<"\nDelete Last Elements"<<std::endl;
   test.Baja();
   test.printElements();

   std::cout<<"\nDelete Second Elements"<<std::endl;
   test.Baja(1);
   test.printElements();
    return 0;
}