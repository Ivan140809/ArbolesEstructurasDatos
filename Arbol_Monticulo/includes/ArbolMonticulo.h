#ifndef __ARBOLMONTICULO_H__
#define __ARBOLMONTICULO_H__

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <list>

template <class T>
class ArbolMonticulo {
private:
    std::vector<T> vec;

public:
    ArbolMonticulo();
    ~ArbolMonticulo();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool buscar(T val);
    void insertar(T val);
    bool eliminar(T val);
    bool esMonticulo();
    void ordenarMonticulo();
    void construirMonticulo();
    void InOrden(std::list<T>& lista);
    void NivelOrden();
};

#include "../src/ArbolMonticulo.hxx"
#endif
