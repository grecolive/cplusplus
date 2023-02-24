#include <iostream>
#include "conjunto.h"

int main(){
    Conjunto A;
    Conjunto B;
    Conjunto U;
    Conjunto D;
    Conjunto I;
    Conjunto CP;
    Conjunto NP;
   
    
    std::cout<<"conjunto A"<<std::endl;
    A.Alta("1");
    A.Alta("2");
    A.Alta("5");
    A.Alta("4");
    A.Alta("3");
    A.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto B"<<std::endl;
    B.Alta("6");
    B.Alta("5");
    B.Alta("9");
    B.Alta("8");
    B.Alta("7");
    B.Alta("10");
    B.Alta("14");
    B.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto A Union B"<<std::endl;
    U = A.Union(B);
    U.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto A Intersecion B"<<std::endl;
    I = A.Intersection(B);
    I.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto A Diferencia B"<<std::endl;
    D = B.Difference(A);
    D.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto A Producto Cartesiano B"<<std::endl;
    CP = A.cartesianProduct(B);
    CP.printElements();

    std::cout<<"------------------"<<std::endl;
    std::cout<<"conjunto A Producto Natural B"<<std::endl;
    NP = A.naturalProduct(B);
    NP.printElements();
    return 0;
}