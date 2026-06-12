#ifndef __NODOGENERAL_H__
#define __NODOGENERAL_H__
#include <list>

template <class T>
class NodoGeneral {
protected:
    T dato;
    std::list<NodoGeneral<T>*> desc;
public:
    NodoGeneral();
    ~NodoGeneral();
    T& obtenerDato();
    void fijarDato(T& val);
    void limpiarLista();
    void adicionarDesc(T& val);
    bool eliminarDesc(T& val);
    bool esHoja();
    int altura();
    void preOrden();
    void posOrden();
    std::list<NodoGeneral<T>*>& obtenerDesc();
};
#include "../src/NodoGeneral.hxx"
#endif
