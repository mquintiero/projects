template <typename T>
string_map<T>::string_map() : raiz(new Nodo()), _size(0) {
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    destruirNodos(raiz);
    _size = d.size();
    raiz = new Nodo();
    copiarNodos(raiz, d.raiz);
    return *this;
}

template <typename T>
string_map<T>::~string_map(){
    destruirNodos(raiz);
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& par){
    string palabra = get<0>(par);
    T def = get<1>(par);
    Nodo* actual = raiz;
    for (int i = 0; i < palabra.size(); ++i) {
        if (actual->siguientes[int(palabra[i])] == nullptr){
            actual->siguientes[int(palabra[i])] = new Nodo();
        }
        actual = actual->siguientes[int(palabra[i])];
        if (i == palabra.size() - 1){
            if (actual->definicion == nullptr){
                _size++;
                actual->definicion = new T(def);
            } else {
                delete actual->definicion;
                actual->definicion = new T(def);
            }
        }
    }
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        if (actual->siguientes[int(clave[i])] == nullptr){
            return 0;
        }
        actual = actual->siguientes[int(clave[i])];
        if (i == clave.size() - 1){
            if (actual->definicion == nullptr){
                return 0;
            }
        }
    }
    return 1;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo *actual = raiz;
    for (int i = 0; i < clave.size(); ++i) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo *actual = raiz;
    for ( int i = 0; i < clave.size(); ++i) {
        actual = actual->siguientes[int(clave[i])];
    }
    return *(actual->definicion);
}

template <typename  T>
int string_map<T>::cantDeHijos(Nodo n){
    int counter = 0;
    vector<Nodo*> v = n.siguientes;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != nullptr){
            counter++;
        }
    }
    return counter;
}


template <typename T>
void string_map<T>::erase(const string& clave) {
    _size--;
    Nodo* actual = raiz;
    Nodo* ultimo_nodo = raiz;
    int ultimo_indice = 0;
    for (int i = 0; i < clave.size(); ++i) {
        if (cantDeHijos(*actual) > 1 || actual->definicion != nullptr){
            ultimo_nodo = actual;
            ultimo_indice = i;
        }
        actual = actual->siguientes[int(clave[i])];
    } // cuando salgo del loop, actual es el nodo donde esta la definicion y ultimo nodo es a partir de que nodo borrar, con indice ultimo indice
    delete actual->definicion;
    actual->definicion = nullptr;
    if (cantDeHijos(*actual) == 0) {
        Nodo* siguiente = ultimo_nodo->siguientes[int(clave[ultimo_indice])];
        ultimo_nodo->siguientes[int(clave[ultimo_indice])] = nullptr;
        ultimo_indice++;
        ultimo_nodo = siguiente;
        while (ultimo_indice != clave.size()){
            siguiente = ultimo_nodo->siguientes[int(clave[ultimo_indice])];
            ultimo_indice++;
            delete ultimo_nodo;
            ultimo_nodo = siguiente;
        }
        delete ultimo_nodo;
    }
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template <typename T>
void string_map<T>::destruirNodos(Nodo*& root) {
    if (root->definicion != nullptr){
        delete (root->definicion);
        root->definicion = nullptr;
    }
    for (int i = 0; i < 256; ++i) {
        if (root->siguientes[i] != nullptr){
            destruirNodos(root->siguientes[i]);
        }
    }
    delete (root);
    root = nullptr;
}

template <typename T>
void string_map<T>::copiarNodos(Nodo*& root, const Nodo* copyRoot){
    if (copyRoot->definicion != nullptr){
        root->definicion = new T(*(copyRoot->definicion));
    }
    for (int i = 0; i < 256; ++i) {
        if (copyRoot->siguientes[i] != nullptr){
            root->siguientes[i] = new Nodo();
            copiarNodos(root->siguientes[i], copyRoot->siguientes[i]);
        }
    }
}

template<typename T>
int string_map<T>::size() const {
    return _size;
}