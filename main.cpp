#include <iostream>
#include <list>
#include "Arbol_binario/includes/Arbolbinario.h"
#include "Arbol_General/includes/ArbolGeneral.h"
#include "Arbol_AVL/includes/ArbolAVL.h"
#include "Arbol_RN/includes/ArbolRN.h"
#include "Arbol_Monticulo/includes/ArbolMonticulo.h"
using namespace std;

int main(){

    cout << "Arbol Binario" << endl;
    
    ArbolBinario<int> ab;
    ab.insertar(5);
    ab.insertar(3);
    ab.insertar(7);
    ab.insertar(1);
    ab.insertar(4);
    ab.insertar(6);
    ab.insertar(8);
    
    ab.InOrden();
    cout << endl;
    
    ab.eliminar(3);
    ab.InOrden();
    cout << endl << endl;

    cout << "Arbol General" << endl;
    
    ArbolGeneral<int> ag(1);
    ag.insertarNodo(1, 2);
    ag.insertarNodo(1, 3);
    ag.insertarNodo(1, 4);
    ag.insertarNodo(2, 5);
    ag.insertarNodo(2, 6);
    ag.insertarNodo(3, 7);
    
    ag.preOrden();
    cout << endl;
    
    ag.eliminarNodo(2);
    ag.nivelOrden();
    cout << endl << endl;

    cout << "Arbol AVL" << endl;
    
    ArbolAVL<int> avl;
    avl.insertar(50);
    avl.insertar(30);
    avl.insertar(70);
    avl.insertar(20);
    avl.insertar(40);
    avl.insertar(60);
    avl.insertar(80);
    
    avl.InOrden();
    cout << endl;
    
    avl.eliminar(30);
    avl.InOrden();
    cout<<endl;
    cout << "Altura AVL: " << avl.altura() << endl;
    cout << endl << endl;

    cout << "Arbol Rojinegro" << endl;
    
    ArbolRN<int> rn;
    rn.insertar(50);
    rn.insertar(30);
    rn.insertar(70);
    rn.insertar(20);
    rn.insertar(40);
    rn.insertar(60);
    rn.insertar(80);
    
    rn.InOrden();
    cout << endl;
    
    rn.eliminar(30);
    rn.InOrden();
    cout << endl << endl;

    cout << "Arbol Monticulo" << endl;
    
    ArbolMonticulo<int> heap;
    heap.insertar(50);
    heap.insertar(30);
    heap.insertar(70);
    heap.insertar(20);
    heap.insertar(40);
    heap.insertar(60);
    heap.insertar(80);
    
       list<int> listaHeap1;
    heap.InOrden(listaHeap1);
    for(list<int>::iterator it = listaHeap1.begin(); it != listaHeap1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    heap.eliminar(30);
    list<int> listaHeap2;
    heap.InOrden(listaHeap2);
    for(list<int>::iterator it = listaHeap2.begin(); it != listaHeap2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
