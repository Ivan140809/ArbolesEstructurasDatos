#include "../includes/ArbolAVL.h"
#include <queue>

template <class T>
ArbolAVL<T>::ArbolAVL(){
  this -> raiz=NULL;
}

template <class T>
ArbolAVL<T>::~ArbolAVL(){
  if(this -> raiz != NULL) {
  delete this -> raiz;
  this-> raiz = NULL;
   }
}

template <class T>
bool ArbolAVL<T>::esVacio(){
  return this-> raiz == NULL;
}


template <class T>
T ArbolAVL<T>::datoRaiz() {
return (this->raiz) -> obtenerDato();
}

//recursion
template <class T>
int ArbolAVL<T>::altura(){
  if(this-> esVacio())
  return -1;
  else {
  return (this->raiz) -> altura();
 }
}

//recursiva
template <class T>
int ArbolAVL<T>::tamano(){
if(this->esVacio())
  return -1;
  else {
 return (this->raiz)->tamano();
 }
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerecha(NodoAVL<T>* n1) {

NodoAVL<T>* n2=  n1 -> obtenerHijoIzq();
 NodoAVL<T>* n_padre = n2->obtenerHijoDer();
 n2->fijarHijoDer(n1);
    n1->fijarHijoIzq(n_padre);
    n1->actualizarAltura();
    n1->actualizarDistancia();
    n2->actualizarAltura();
    n2->actualizarDistancia();
    return n2;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzquierda(NodoAVL<T>* n1) {
 NodoAVL<T>* n2 = n1->obtenerHijoDer();
    NodoAVL<T>* n_padre = n2->obtenerHijoIzq();
    n2->fijarHijoIzq(n1);
    n1->fijarHijoDer(n_padre);
    n1->actualizarAltura();
    n1->actualizarDistancia();
    n2->actualizarAltura();
    n2->actualizarDistancia();
    return n2;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzqDer(NodoAVL<T>* nodo) {
    NodoAVL<T>* hijoIzq = nodo->obtenerHijoIzq();
    hijoIzq = rotarIzquierda(hijoIzq);
    nodo->fijarHijoIzq(hijoIzq);
    nodo = rotarDerecha(nodo);
    return nodo;
}
 
template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerIzq(NodoAVL<T>* nodo) {
    NodoAVL<T>* hijoDer = nodo->obtenerHijoDer();
    hijoDer = rotarDerecha(hijoDer);
    nodo->fijarHijoDer(hijoDer);
    nodo = rotarIzquierda(nodo);
    return nodo;
}
template <class T>
NodoAVL<T>* ArbolAVL<T>::balancear(NodoAVL<T>* n1) {
    n1->actualizarAltura();
    n1->actualizarDistancia();

    int diferenciaArbol = n1->obtenerDistancia();

    if (diferenciaArbol == 2) {
        int diferenciaIzq = n1->obtenerHijoIzq()->obtenerDistancia();

        if (diferenciaIzq > 0) {
            n1 = rotarDerecha(n1);
} else {
     n1= rotarIzqDer(n1);
   }
}else if (diferenciaArbol == -2) {
        int diferenciaDer = n1->obtenerHijoDer()->obtenerDistancia();
        if (diferenciaDer < 0) {
            n1 = rotarIzquierda(n1);
        } else {
          n1= rotarDerIzq(n1); 
   }
 }
   return n1;
}


template <class T>
NodoAVL<T>* ArbolAVL<T>::balancearArbol(NodoAVL<T>* nodo, T val, bool& insertado) {
if (nodo == NULL) {
        nodo = new NodoAVL<T>(val);
        nodo->actualizarAltura();
        nodo->actualizarDistancia();
        insertado = true;
        return nodo;
    }
if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(balancearArbol(nodo->obtenerHijoIzq(), val, insertado));
    }
else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(balancearArbol (nodo->obtenerHijoDer(), val, insertado));
    }
else {
        insertado = false;
        return nodo;
    }
    nodo->actualizarAltura();
    nodo->actualizarDistancia();
    nodo = balancear(nodo);
    return nodo;
}



//iterativa
template <class T>
bool ArbolAVL<T>::insertar(T val){
bool insertado=false;
this-> raiz= balancearArbol(this-> raiz, val,insertado);
return insertado;
}

template <class T>
bool ArbolAVL<T>::eliminar(T val) {
    bool eliminado = false;
    raiz = eliminar(raiz, val, eliminado);
    return eliminado;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::obtenerMinimo(NodoAVL<T>* nodo) {
    if (nodo == NULL) {
        return NULL;
    }

    while (nodo->obtenerHijoIzq() != NULL) {
        nodo = nodo->obtenerHijoIzq();
    }

    return nodo;
}

//iterativa
template <class T>
NodoAVL<T>* ArbolAVL<T>::eliminar(NodoAVL<T>* nodo, T val, bool& eliminado) {
    if (nodo == NULL) {
        eliminado = false;
        return NULL;
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(eliminar(nodo->obtenerHijoIzq(), val, eliminado));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), val, eliminado));
    } else {
        eliminado = true;

        // Caso 1: hoja
        if (nodo->obtenerHijoIzq() == NULL && nodo->obtenerHijoDer() == NULL) {
            delete nodo;
            return NULL;
        }

        // Caso 2: solo hijo derecho
        if (nodo->obtenerHijoIzq() == NULL) {
            NodoAVL<T>* temp = nodo->obtenerHijoDer();
            nodo->fijarHijoDer(NULL);
            delete nodo;
            return temp;
        }

        // Caso 3: solo hijo izquierdo
        if (nodo->obtenerHijoDer() == NULL) {
            NodoAVL<T>* temp = nodo->obtenerHijoIzq();
            nodo->fijarHijoIzq(NULL);
            delete nodo;
            return temp;
        }

        // Caso 4: dos hijos
        NodoAVL<T>* sucesor = obtenerMinimo(nodo->obtenerHijoDer());
        nodo->fijarDato(sucesor->obtenerDato());

        bool eliminadoSucesor = false;
        nodo->fijarHijoDer(eliminar(nodo->obtenerHijoDer(), sucesor->obtenerDato(), eliminadoSucesor));
    }

    nodo->actualizarAltura();
    nodo->actualizarDistancia();
    nodo = balancear(nodo);

    return nodo;
}

//iterativa
template <class T>
bool ArbolAVL<T>::buscar(T val){
 NodoAVL<T>* nodo = this->raiz;
    while(nodo != NULL){
        if(val == nodo->obtenerDato())
        return true;
        else if(val < nodo->obtenerDato())
        nodo = nodo->obtenerHijoIzq();
        else
        nodo = nodo->obtenerHijoDer();
    }
return false;
 }

//recursiva
template <class T>
void ArbolAVL<T>::PreOrden(){
 if(!this->esVacio())
        (this->raiz)->PreOrden();
}

//recursiva
template <class T>
void ArbolAVL<T>::InOrden(){
if(!this->esVacio()){
 (this->raiz) -> InOrden();
 }
}

//recursiva
template <class T>
void ArbolAVL<T>::PosOrden(){
if(!this->esVacio())
   (this->raiz)->PosOrden();
}

//recursiva
template <class T>
void ArbolAVL<T>::NivelOrden(){

if(!this-> esVacio()) {
std::queue<NodoAVL<T>*> cola;
cola.push(this->raiz);
NodoAVL<T>* nodo;

while(!cola.empty()) {
nodo= cola.front();
cola.pop();
std::cout << nodo->obtenerDato() <<" ";
if(nodo->obtenerHijoIzq() !=NULL)
cola.push(nodo-> obtenerHijoIzq());
if(nodo->obtenerHijoDer() !=NULL)
cola.push(nodo -> obtenerHijoDer());
  }
 }
}
