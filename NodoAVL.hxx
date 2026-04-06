#include "NodoAVL.h"

template <class T>
NodoAVL<T>::NodoAVL() {
    this->dato = 0;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->alturaAVL = 0;
    this->distancia = 0;
}

template <class T>
NodoAVL<T>::NodoAVL(T val) {
    this->dato = val;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
    this->alturaAVL = 0;
    this->distancia = 0;
}

template <class T>
NodoAVL<T>::~NodoAVL() {
    if (this->hijoIzq != NULL) {
        delete this->hijoIzq;
        this->hijoIzq = NULL;
    }
    if (this->hijoDer != NULL) {
        delete this->hijoDer;
        this->hijoDer = NULL;
    }
}

template <class T>
T NodoAVL<T>::obtenerDato() {
    return this->dato;
}

template <class T>
void NodoAVL<T>::fijarDato(T val) {
    this->dato = val;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>* nodo) {
    this->hijoIzq = nodo;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer() {
    return this->hijoDer;
}

template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>* nodo) {
    this->hijoDer = nodo;
}

template <class T>
bool NodoAVL<T>::esHoja() {
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template <class T>
int NodoAVL<T>::altura() {
    if (this->esHoja()) {
        return 0;
    }
    
    int altIzq = 0;
    if (this->hijoIzq != NULL) {
        altIzq = this->hijoIzq->altura() + 1;
    }
    
    int altDer = 0;
    if (this->hijoDer != NULL) {
        altDer = this->hijoDer->altura() + 1;
    }
    
    if (altIzq > altDer) {
        return altIzq;
    } else {
        return altDer;
    }
}

template <class T>
void NodoAVL<T>::actualizarAltura() {
    int altIzq = -1;
    if (this->hijoIzq != NULL) {
        altIzq = this->hijoIzq->altura();
    }
    
    int altDer = -1;
    if (this->hijoDer != NULL) {
        altDer = this->hijoDer->altura();
    }
    
    int maxAltura = altIzq;
    if (altDer > altIzq) {
        maxAltura = altDer;
    }
    
    this->alturaAVL = 1 + maxAltura;
}

template <class T>
int NodoAVL<T>::tamano() {
    if (this->esHoja()) {
        return 1;
    }
    
    int tamIzq = 0;
    if (this->hijoIzq != NULL) {
        tamIzq = this->hijoIzq->tamano();
    }
    
    int tamDer = 0;
    if (this->hijoDer != NULL) {
        tamDer = this->hijoDer->tamano();
    }
    
    return 1 + tamIzq + tamDer;
}

template <class T>
int NodoAVL<T>::obtenerDistancia() {
    return this->distancia;
}

template <class T>
void NodoAVL<T>::actualizarDistancia() {
    int altIzq = -1;
    if (this->hijoIzq != NULL) {
        altIzq = this->hijoIzq->altura();
    }
    
    int altDer = -1;
    if (this->hijoDer != NULL) {
        altDer = this->hijoDer->altura();
    }
    
    this->distancia = altIzq - altDer;
}

template <class T>
void NodoAVL<T>::PreOrden() {
    std::cout << this->obtenerDato();
    
    if (this->hijoIzq != NULL) {
        this->hijoIzq->PreOrden();
    }
    
    if (this->hijoDer != NULL) {
        this->hijoDer->PreOrden();
    }
}

template <class T>
void NodoAVL<T>::InOrden() {
    if (this->hijoIzq != NULL) {
        this->hijoIzq->InOrden();
    }
    
    std::cout << this->obtenerDato()<< " "; 
    
    if (this->hijoDer != NULL) {
        this->hijoDer->InOrden();
    }
}

template <class T>
void NodoAVL<T>::PosOrden() {
    if (this->hijoIzq != NULL) {
        this->hijoIzq->PosOrden();
    }
    
    if (this->hijoDer != NULL) {
        this->hijoDer->PosOrden();
    }
    
    std::cout << this->obtenerDato() << "\n";
}
