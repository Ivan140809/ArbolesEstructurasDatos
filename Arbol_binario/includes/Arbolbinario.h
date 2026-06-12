
#ifndef __ARBOLBINARIOORD_H__
#define __ARBOLBINARIOORD_H__

#include "NodoBinario.h"


template < class T >
class ArbolBinario {
protected:
NodoBinario<T>* raiz;
public:
ArbolBinario();
~ArbolBinario();
bool esVacio();
T datoRaiz();
int altura();
int tamano();
bool insertar(T val);
bool eliminar(T val);
bool buscar(T val);
void PreOrden();
void InOrden();
void PosOrden();
void NivelOrden();

};
#include "../src/Arbolbinario.hxx"
#endif
