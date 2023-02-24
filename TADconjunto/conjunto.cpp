#include "conjunto.h"

Conjunto::Conjunto(){
    this->numberElement = 0;
    this->elements = nullptr;
}

Conjunto::~Conjunto(){
     delete[] elements;
}

void Conjunto::Alta(std::string element){
    std::string *acopy = this->elements;
    this->numberElement++;
    this->elements = new std::string[this->numberElement];
    if (acopy != nullptr)
        copyData(acopy, 0,this->numberElement-1, 0);
    this->elements[this->numberElement-1] = element;
}

void Conjunto::copyData(std::string *acpy, int start, int end, short int paralel){
    for (int k = start; k < end; k++)
        this->elements[k] = acpy[k+paralel];
    delete[] acpy;
}

void Conjunto::orderElements(){
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

void Conjunto::printElements(){
    for (int i = 0; i < this->numberElement; i++)
    {
       std::cout<<this->elements[i]<<std::endl;
    }
}

int Conjunto::Cardinality(){
    return this->numberElement;
}

std::string Conjunto::Baja(){
    std::string *acopy = this->elements;
    std::string bajado = acopy[this->numberElement - 1];
    this->numberElement--;
    this->elements = new std::string[this->numberElement];
    if (acopy != nullptr)
        copyData(acopy, 0, this->numberElement,0);
    return bajado;
}

std::string Conjunto::Baja(int posicion){
    if (posicion < 0 || posicion > this->numberElement - 1)
        return NULL;
    std::string *acopy = this->elements;
    std::string bajado = acopy[posicion];
    this->numberElement--;
    this->elements = new std::string[this->numberElement];
    copyData(acopy, 0, posicion, 0);
    copyData(acopy, (posicion+1), (this->numberElement+1), 1);
    return bajado;
}


std::string Conjunto::Busqueda(std::string element){
    std::string resutaldo = "";
    for (int i = 0; i < this->numberElement; i++){
        if (this->elements[i] == element){
            resutaldo = this->elements[i];
        }
    }
    return resutaldo;
}

bool Conjunto::isMemberOf(std::string element){
    for (int i = 0; i < this->numberElement; i++){
        if (this->elements[i] == element){
            return true;
        }
    }
    return false;
}

Conjunto Conjunto::Union(const Conjunto& p_conjunto)
{
    Conjunto unionConjunto;
    // Aumentamos el tamaño del arreglo
    std::string *pointer = this->elements;
    unionConjunto.numberElement = (this->numberElement + p_conjunto.numberElement);
    unionConjunto.elements = new std::string[unionConjunto.numberElement];

    if (pointer != nullptr)
        for (int i = 0; i < (unionConjunto.numberElement-p_conjunto.numberElement); i++)
            unionConjunto.elements[i] = pointer[i];
        delete[] pointer;
    // Agregamos los elementos del conjunto pasado por parámetro
    for (int j = 0; j < p_conjunto.numberElement; j++)
    {
        // Agregamos el elemento si no existe en el conjunto actual
        if (!unionConjunto.isMemberOf(p_conjunto.elements[j])){ 
            unionConjunto.elements[(unionConjunto.numberElement-p_conjunto.numberElement)+j] = p_conjunto.elements[j];
        }else
        unionConjunto.numberElement--;
    }
   return unionConjunto;
}

/* Conjunto Conjunto::unionDitinct(const Conjunto& p_conjunto){

} */

Conjunto Conjunto::Intersection(const Conjunto& p_conjunto)
{
    Conjunto intersectionConjunto;
    int numElements = std::min(this->numberElement, p_conjunto.numberElement);

    intersectionConjunto.elements = new std::string[numElements];

    int counter = 0;
    for (int i = 0; i < numElements; i++) 
    {
        if (this->isMemberOf(p_conjunto.elements[i])) 
        {
            intersectionConjunto.elements[counter] = p_conjunto.elements[i];
            counter++;
        }
    }

    intersectionConjunto.numberElement = counter;
    return intersectionConjunto;
}

Conjunto Conjunto::Difference(Conjunto p_conjunto)
{
    Conjunto differenceConjunto;

    std::string *pointer = new std::string[this->numberElement];

    int counter = 0;
    for (int i = 0; i < this->numberElement; i++){
        if (!p_conjunto.isMemberOf(this->elements[i])){
            pointer[counter] = this->elements[i];
            counter++;
        }
    }
   
    differenceConjunto.numberElement = counter;
    differenceConjunto.elements = new std::string[differenceConjunto.numberElement];
    
    if (pointer != nullptr) {
        for (int i = 0; i < (differenceConjunto.numberElement); i++) {
            differenceConjunto.elements[i] = pointer[i];
        }
        delete[] pointer;
    }
    return differenceConjunto;
}

Conjunto Conjunto::cartesianProduct(const Conjunto& p_conjunto){
    int auxNumberElementOne = this->numberElement;
    std::string *pointerOne = this->elements;

    int auxNumberElementTwo = p_conjunto.numberElement;
    std::string *pointerTwo = p_conjunto.elements;

    Conjunto conjuntoCartesianProduct;

    for (int i = 0; i < auxNumberElementTwo; i++){
        for (int j = 0; j < auxNumberElementOne; j++){
            std::string result = "("+pointerOne[j] + "," + pointerTwo[i]+ ")";
            conjuntoCartesianProduct.Alta(result);
        }
    }

    delete[] pointerOne;
    delete[] pointerTwo;

    return conjuntoCartesianProduct;
}

Conjunto Conjunto::naturalProduct(const Conjunto& p_conjunto){
    int auxNumberElementOne = this->numberElement;
    std::string *pointerOne = this->elements;

    int auxNumberElementTwo = p_conjunto.numberElement;
    std::string *pointerTwo = p_conjunto.elements;

    Conjunto conjuntoNaturalProduct;

    for (int i = 0; i < auxNumberElementTwo; i++){
        for (int j = 0; j < auxNumberElementOne; j++){
            std::string result = "("+ pointerOne[j] +" * "+ pointerTwo[i]+ ")";
            conjuntoNaturalProduct.Alta(result);
        }
    }
    
    delete[] pointerOne;
    delete[] pointerTwo;

    return conjuntoNaturalProduct;
}