#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__
#include "NodoGeneral.h"

template <class T>
class ArbolGeneral {
protected:
    NodoGeneral<T>* raiz;
public:
    ArbolGeneral();
    ArbolGeneral(T val);
    ~ArbolGeneral();
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T padre, T n);
    bool eliminarNodo(T n);
    bool buscar(T n);
    int altura();
    unsigned int tamano();
    void preOrden();
    void posOrden();
    void nivelOrden();
private:
    bool insertarRec(NodoGeneral<T>* nodo, T padre, T n);
    bool eliminarRec(NodoGeneral<T>* nodo, T n);
    bool buscarRec(NodoGeneral<T>* nodo, T n);
    unsigned int tamanoRec(NodoGeneral<T>* nodo);
};
#include "ArbolGeneral.hxx"
#endif
