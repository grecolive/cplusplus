#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <iostream>

class Conjunto{
    private:
        std::string *elements;
        /*Cantidad de Elementos que tendrá nuestro pointer*/
        int numberElement;
        /*Hace una copia en el pointer*/
        void copyData(std::string *acpy, int start, int end, short int paralel);
        /*Nos permite saber cuando un elemento esta en nuestro conjunto*/
        bool isMemberOf(std::string element);
    public:
        /*Constructor de nuestro TAD conjunto, aqui se inicializan nuestras variables*/
        Conjunto();
        /*Destructor de nuestro TAD conjunto*/
        ~Conjunto();
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
        /*Realiza la union de 2 conjunto dados y devuele un nuevo conjunto con los elementos*/
        Conjunto Union(const Conjunto& p_conjunto);
        Conjunto unionDitinct(const Conjunto& p_conjunto);
        /*Encuentra la intersección de 2 conjuntos dados y devuelve un nuevo conjunto*/
        Conjunto Intersection(const Conjunto& p_conjunto);
        /*Encuentra la diferencia de 2 conjuntos dados y devuelve un nuevo conjunto*/
        Conjunto Difference(Conjunto p_conjunto);
        /*Realiza el producto cartesiadno de 2 conjunto dados  y devuele un nuevo conjunto*/
        Conjunto cartesianProduct(const Conjunto& p_conjunto);
        /*Realiza el producto natural de 2 conjunto dados  y devuele un nuevo conjunto*/
        Conjunto naturalProduct(const Conjunto& p_conjunto);
};
#endif
