#ifndef TAD_H
#define TAD_H
#include <iostream>

class TAD{
    private:
        std::string *elements;
        /*Cantidad de Elementos que tendrá nuestro pointer*/
        int numberElement;
        /*Hace una copia en el pointer*/
        void copyData(std::string *acpy, int start, int end, short int paralel);
        bool isMemberOf(std::string element);
    public:
        /*Constructor de nuestro TAD conjunto, aqui se inicializan nuestras variables*/
        TAD();
        /*Destructor de nuestro TAD conjunto*/
        ~TAD();
        /*El metodo Alta nos ayuda a insertar data en nuestro conjunto*/
        void Alta(std::string element);
        /*El metodo orderElements nos ayuda a oredenar de menor a mayor la data de nuestro conjunto con el algoritmo de la burbuja*/
        void orderElements();
        /*El metodo orderElements nos ayuda a imprimir en pantalla la data de nuestro conjunto*/
        void printElements();
        /*El metodo Cardinality devuelve la cantidad de elementos que tiene el conjunto*/
        int Cardinality();
        /*Elimina el ultimo elemento del pointer*/
        std::string Baja();
        //overload 1 de baja
        /*Elimina el elemento en la posicion pasada como parametro del pointer*/
        std::string Baja(int posicion);
        /*Busca un elemento dentro del pointer*/
        std::string Busqueda(std::string element);
};
#endif
