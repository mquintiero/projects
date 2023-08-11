
#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cardinal(0) {
}

template <class T>
Conjunto<T>::~Conjunto() {
    destruirConjunto(_raiz);
}

template <class T>
void Conjunto<T>::destruirConjunto(Nodo* raiz) {
    if (raiz == nullptr){
        return;
    }
    destruirConjunto(raiz->der);
    destruirConjunto(raiz->izq);
    delete raiz;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    while (actual != nullptr && clave != actual->valor) {
        if (clave < actual->valor) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }
    return actual != nullptr;
}


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (_raiz == nullptr){
        _raiz = new Nodo(clave);
        _raiz->der == nullptr;
        _raiz->izq == nullptr;
        _cardinal++;
    } else {
        Nodo* anterior;
        Nodo* actual = _raiz;
        while (actual != nullptr && clave != actual->valor){
            if (clave < actual->valor){
                anterior = actual;
                actual = actual->izq;
            } else {
                anterior = actual;
                actual = actual->der;
            }
        }
        if (actual == nullptr){
            if (clave < anterior->valor){
                anterior->izq = new Nodo(clave);
                anterior->izq->padre = anterior;
                anterior->izq->der == nullptr;
                anterior->izq->izq == nullptr;
                _cardinal++;
            } else {
                anterior->der = new Nodo(clave);
                anterior->der->padre = anterior;
                anterior->der->der == nullptr;
                anterior->der->izq == nullptr;
                _cardinal++;
            }
        }
    }
}

template<class T>
typename Conjunto<T>::Nodo* Conjunto<T>::siguienteEnNodo(const T &clave) {
    Nodo* actual = _raiz;
    while (clave != actual->valor) {
        if (clave < actual->valor) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }
    if (actual->der != nullptr){
        Nodo* minimo = actual->der;
        while (minimo->izq != nullptr) {
            minimo = minimo->izq;
        }
        return minimo;
    }
    while (actual->padre != nullptr && actual == actual->padre->der){
        actual = actual->padre;
    }
    return actual->padre;
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if (clave == _raiz->valor && _cardinal == 1) {
        Nodo *actual = _raiz;
        delete (actual);
        _raiz = nullptr;
        _cardinal--;
    } else {
        Nodo *actual = _raiz;
        while (actual != nullptr && clave != actual->valor) {
            if (clave < actual->valor) {
                actual = actual->izq;
            } else {
                actual = actual->der;
            }
        }
        if (actual != nullptr) {
            if (actual->der == nullptr && actual->izq == nullptr) { // es hoja
                if (actual == actual->padre->izq) {
                    actual->padre->izq = nullptr;
                } else {
                    actual->padre->der = nullptr;
                }
                delete (actual);
                _cardinal--;
            } else if (actual->der == nullptr) { // si tiene solo hijo izquierdo4
                    reemplazar(actual, actual->izq);
                    delete (actual);
                    _cardinal--;
                } else if (actual->izq == nullptr){ // si tiene solo hijo derecho
                    reemplazar(actual, actual->der);
                    delete (actual);
                    _cardinal--;
                } else { // si tiene dos hijos
                Nodo *sucesor = siguienteEnNodo(actual->valor);
                if (sucesor->padre != actual) { // si el sucesor no es el padre del arbol derecho del que remuevo
                    reemplazar(sucesor, sucesor->der);
                    sucesor->der = actual->der;
                    sucesor->der->padre = sucesor;
                }
                reemplazar(actual, sucesor);
                sucesor->izq = actual->izq;
                sucesor->izq->padre = sucesor;
                delete actual;
                _cardinal--;
            }
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    while (clave != actual->valor) {
        if (clave < actual->valor) {
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }
    if (actual->der != nullptr){
        Nodo* minimo = actual->der;
        while (minimo->izq != nullptr) {
            minimo = minimo->izq;
        }
        return minimo->valor;
    }
    while (actual->padre != nullptr && actual == actual->padre->der){
        actual = actual->padre;
    }
    return actual->padre->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while (actual->izq != nullptr) {
            actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while (actual->der != nullptr) {
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template<class T>
void Conjunto<T>::reemplazar(Conjunto::Nodo *a, Conjunto::Nodo *b) {
    if (a->padre == nullptr){
        _raiz = b;
    } else if (a == a->padre->izq){
        a->padre->izq = b;
    } else {
        a->padre->der = b;
    }
    if (b != nullptr){
        b->padre = a->padre;
    }
}


