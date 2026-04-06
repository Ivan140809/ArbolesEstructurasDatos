#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__
 
#include "NodoAVL.h"
 
template <class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;
    NodoAVL<T>* eliminar(NodoAVL<T>* nodo, T val, bool& eliminado);
public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T datoRaiz();
    int altura();
    int tamano();
    bool buscar(T val);
    bool insertar(T val);
    bool eliminar(T val);
    NodoAVL<T>* rotarDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarIzquierda(NodoAVL<T>* nodo);
    NodoAVL <T>* rotarIzqDer(NodoAVL<T>* nodo);
    NodoAVL <T>* rotarDerIzq(NodoAVL<T>* nodo);
    NodoAVL<T>* balancear(NodoAVL<T>* nodo);
    NodoAVL<T>* obtenerMinimo(NodoAVL<T>* nodo);
    NodoAVL<T>* balancearArbol(NodoAVL<T>* nodo, T val, bool& insertado);
    void PreOrden();
    void InOrden();
    void PosOrden();
    void NivelOrden();
};
 
#include "ArbolAVL.hxx"
#endif
