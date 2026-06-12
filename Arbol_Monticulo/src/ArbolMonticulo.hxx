#ifndef __ARBOLMONTICULO_HXX__
#define __ARBOLMONTICULO_HXX__

template <class T>
ArbolMonticulo<T>::ArbolMonticulo() {
}

template <class T>
ArbolMonticulo<T>::~ArbolMonticulo() {
  vec.clear();
}

template <class T>
bool ArbolMonticulo<T>::esVacio() {
  return vec.empty();
}

template <class T>
T ArbolMonticulo<T>::datoRaiz() {
 return vec.front();
}

template <class T>
int ArbolMonticulo<T>::altura() {
 if (vec.empty()) {
     return 0;
 }
return std::floor(std::log2(vec.size())) + 1;
}

template <class T>
int ArbolMonticulo<T>::tamano(){
    return vec.size();
}

template <class T>
bool ArbolMonticulo<T>::buscar(T val){
    typename std::vector<T>::iterator it;
 for(it = vec.begin(); it != vec.end(); ++it) {
    if(*it == val) {
      return true;
   }
 }
    return false;
}

template<class T>
void ArbolMonticulo<T>::insertar(T val) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == val) {
            return;
        }
    }

    vec.push_back(val);
    int i = vec.size() - 1;

    while (i > 0 && vec[(i - 1) / 2] > vec[i]) {
        T aux = vec[i];
        vec[i] = vec[(i - 1) / 2];
        vec[(i - 1) / 2] = aux;
        i = (i - 1) / 2;
    }
}


template <class T>
bool ArbolMonticulo<T>::eliminar(T val) {
        typename std::vector<T>::iterator it = std::find(vec.begin(), vec.end(), val);
    
    if(it == vec.end()) {
        return false;
    }
    
    *it = vec.back();
    vec.pop_back();
    
construirMonticulo();
    return true;
}


template <class T>
bool ArbolMonticulo<T>::esMonticulo() {
    return std::is_heap(vec.begin(), vec.end());
}

template <class T>
void ArbolMonticulo<T>::ordenarMonticulo(){
 std::sort_heap(vec.begin(), vec.end());
}

template <class T>
void ArbolMonticulo<T>::construirMonticulo(){
std::make_heap(vec.begin(), vec.end());
}

template <class T>
void ArbolMonticulo<T>::InOrden(std::list<T>& lista) {
    std::vector<T> temp = vec;
     std::sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++) {
        lista.push_back(temp[i]);
    }
}

template <class T>
void ArbolMonticulo<T>::NivelOrden() {
   typename std::vector<T>::iterator it;
for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
  }
}
#endif
