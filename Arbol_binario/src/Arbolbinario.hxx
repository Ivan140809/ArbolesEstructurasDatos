#include "../includes/Arbolbinario.h"
#include <queue>

template <class T>
ArbolBinario<T>::ArbolBinario(){
  this -> raiz=NULL;
}

template <class T>
ArbolBinario<T>::~ArbolBinario(){
  if(this -> raiz != NULL) {
  delete this -> raiz;
  this-> raiz = NULL;
   }
}

template <class T>
bool ArbolBinario<T>::esVacio(){
  return this-> raiz == NULL;
}


template <class T>
T ArbolBinario<T>::datoRaiz() {
return (this->raiz) -> obtenerDato();
}

//recursion
template <class T>
int ArbolBinario<T>::altura(){
  if(this-> esVacio())
  return -1;
  else {
  return (this->raiz) -> altura();
 }
}

//recursiva
template <class T>
int ArbolBinario<T>::tamano(){
if(this->esVacio()) 
  return -1;
  else {
 return (this->raiz)->tamano();
 }
}

//iterativa
template <class T>
bool ArbolBinario<T>::insertar(T val){
NodoBinario<T>* nodo= this-> raiz;
NodoBinario<T>* padre= NULL;
bool insertado= false;
bool duplicado= false;

while(nodo!= NULL){
 padre=nodo;
if(val < nodo ->obtenerDato()) {
  nodo = nodo->obtenerHijoIzq();
   } else if (val > nodo-> obtenerDato()) {
    nodo = nodo-> obtenerHijoDer();
   } else {
   duplicado=true;
   break;
   }
  }

if(!duplicado){
    NodoBinario<T>* nuevo = new NodoBinario<T>(val);
    if(padre == NULL){
        this->raiz = nuevo;  
    } else if(val < padre->obtenerDato()){
        padre->fijarHijoIzq(nuevo);
    } else {
        padre->fijarHijoDer(nuevo);
    }
    insertado = true;
}
return insertado; 
}
//iterativa
template <class T>
bool ArbolBinario<T>::eliminar(T val){

 NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre = NULL;
    bool esIzq = false;
    while(nodo != NULL && nodo->obtenerDato() != val){
        padre = nodo;
        if(val < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
            esIzq = true;
        } else {
            nodo = nodo->obtenerHijoDer();
            esIzq = false;
        }
    }
    if(nodo == NULL) 
    return false;
    // sin hijos
    if(nodo->esHoja()){
        if(padre == NULL) 
        this->raiz = NULL;
        else if(esIzq) 
        padre->fijarHijoIzq(NULL);
        else padre->fijarHijoDer(NULL);
        nodo->fijarHijoIzq(NULL);
        nodo->fijarHijoDer(NULL);
        delete nodo;
    // hijo derecho
    } else if(nodo->obtenerHijoIzq() == NULL){
        if(padre == NULL) 
        this->raiz = nodo->obtenerHijoDer();
        else if(esIzq) 
        padre->fijarHijoIzq(nodo->obtenerHijoDer());
        else 
        padre->fijarHijoDer(nodo->obtenerHijoDer());
        nodo->fijarHijoIzq(NULL);
        nodo->fijarHijoDer(NULL);
        delete nodo;
    // hijo izquierdo
    } else if(nodo->obtenerHijoDer() == NULL){
        if(padre == NULL) 
        this->raiz = nodo->obtenerHijoIzq();
        else if(esIzq) 
        padre->fijarHijoIzq(nodo->obtenerHijoIzq());
        else 
        padre->fijarHijoDer(nodo->obtenerHijoIzq());
        nodo->fijarHijoIzq(NULL);
        nodo->fijarHijoDer(NULL);
        delete nodo;
    // dos hijos
    } else {
        NodoBinario<T>* padreSuc = nodo;
        NodoBinario<T>* sucesor = nodo->obtenerHijoDer();
        while(sucesor->obtenerHijoIzq() != NULL){
            padreSuc = sucesor;
            sucesor = sucesor->obtenerHijoIzq();
        }
        nodo->fijarDato(sucesor->obtenerDato());
        if(padreSuc == nodo) 
        padreSuc->fijarHijoDer(sucesor->obtenerHijoDer());
        else  
        padreSuc->fijarHijoIzq(sucesor->obtenerHijoDer());
        sucesor->fijarHijoIzq(NULL);
        sucesor->fijarHijoDer(NULL);
        delete sucesor;
    }
    return true;
 
}

//iterativa
template <class T>
bool ArbolBinario<T>::buscar(T val){
 NodoBinario<T>* nodo = this->raiz;
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
void ArbolBinario<T>::PreOrden(){
 if(!this->esVacio())
        (this->raiz)->PreOrden();
}

//recursiva
template <class T>
void ArbolBinario<T>::InOrden(){
if(!this->esVacio()){
 (this->raiz) -> InOrden();
 }
}

//recursiva
template <class T>
void ArbolBinario<T>::PosOrden(){
if(!this->esVacio())
   (this->raiz)->PosOrden();
}

//recursiva
template <class T>
void ArbolBinario<T>::NivelOrden(){

if(!this-> esVacio()) {
std::queue<NodoBinario<T>*> cola;
cola.push(this->raiz);
NodoBinario<T>* nodo;

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
