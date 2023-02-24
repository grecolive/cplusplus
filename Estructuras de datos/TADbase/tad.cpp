#include "tad.h"

TAD::TAD(){
    this->numberElement = 0;
    this->elements = nullptr;
}

TAD::~TAD(){
     delete[] elements;
}

void TAD::Alta(std::string element){
    std::string *acopy = this->elements;
    this->numberElement++;
    this->elements = new std::string[this->numberElement];
    if (acopy != nullptr)
        copyData(acopy, 0,this->numberElement-1, 0);
    this->elements[this->numberElement-1] = element;
}

void TAD::copyData(std::string *acpy, int start, int end, short int paralel){
    for (int k = start; k < end; k++)
        this->elements[k] = acpy[k+paralel];
    delete[] acpy;
}

void TAD::orderElements(){
    std::string auxiliar;
    for(int i=0;i<this->numberElement-1;i++)
    {           
        for(int j=i+1;j<this->numberElement;j++)
        {             
            if (this->elements[i] > this->elements[j]){   
                auxiliar = this->elements[i];                  
                this->elements[i] = this->elements[j];                  
                this->elements[j] = auxiliar;              
            }
        }
    }
    
}

void TAD::printElements(){
    for (int i = 0; i < this->numberElement; i++)
    {
       std::cout<<this->elements[i]<<std::endl;
    }
}

std::string TAD::Baja(){
    std::string *acopy = this->elements;
    std::string bajado = acopy[this->numberElement - 1];
    this->numberElement--;
    this->elements = new std::string[this->numberElement];
    if (acopy != nullptr)
        copyData(acopy, 0, this->numberElement,0);
    return bajado;
}

std::string TAD::Baja(int posicion){
    if (posicion < 0 || posicion > this->numberElement - 1)
        return NULL;
    std::string bajado = this->elements[posicion];
    this->numberElement--;
    std::string *auxElements = new std::string[this->numberElement];
    for(int i = 0; i < posicion; i++){
        auxElements[i] = this->elements[i];
    }
    for(int i = posicion; i < this->numberElement; i++){
        auxElements[i] = this->elements[i+1];
    }
    delete[] this->elements;
    this->elements = auxElements;
    return bajado;
}


std::string TAD::Busqueda(std::string element){
    std::string resutaldo = "";
    for (int i = 0; i < this->numberElement; i++){
        if (this->elements[i] == element){
            resutaldo = this->elements[i];
        }
    }
    return resutaldo;
}

bool TAD::isMemberOf(std::string element){
    for (int i = 0; i < this->numberElement; i++){
        if (this->elements[i] == element){
            return true;
        }
    }
    return false;
}

