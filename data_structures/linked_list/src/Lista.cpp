#include "Lista.h"
#include <cassert>

Lista::Lista() : _primero(nullptr), _ultimo(nullptr) {}

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista() {
    Nodo* actual = _primero;
    while (actual != nullptr){
        Nodo* siguiente = actual->_sig;
        delete actual;
        actual = siguiente;
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(nullptr, elem, _primero);
    if (longitud() == 0) {
        _primero = nuevo;
        _ultimo = nuevo;
    } else {
        _primero->_prev = nuevo;
        _primero = nuevo;

    }
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(_ultimo, elem, nullptr);
    if (longitud() == 0) {
        _primero = nuevo;
        _ultimo = nuevo;
    } else {
        _ultimo->_sig = nuevo;
        _ultimo = nuevo;

    }
}

void Lista::eliminar(Nat i) {
    if (longitud() == 1) {
        delete _primero;
        _primero = nullptr;
        _ultimo = nullptr;
    } else {
        Nodo *actual = _primero;
        if (i == 0) {
            actual->_sig->_prev = nullptr;
            Nodo* siguiente = actual->_sig;
            delete actual;
            actual = siguiente;
            _primero = actual;
        } else {
            Nodo *ult = _ultimo;
            if (i == longitud() - 1) {
                ult->_prev->_sig = nullptr;
                Nodo* siguiente = ult->_prev;
                delete ult;
                ult = siguiente;
                _ultimo = ult;
            } else {
                for (int j = 0; j < i; ++j) {
                    actual = actual->_sig;
                }
                (actual->_prev)->_sig = actual->_sig;
                (actual->_sig)->_prev = actual->_prev;
                delete actual;
            }
        }
    }
}

int Lista::longitud() const {
    Nodo* actual = _primero;
    int contador = 0;
    while (actual != nullptr){
        contador++;
        actual = actual->_sig;
    }
    return contador;
}

const int& Lista::iesimo(Nat i) const {
    assert(0 <= i && i < longitud());
    Nodo* actual = _primero;
    for (int j = 0; j < i; ++j) {
        actual = actual->_sig;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    assert(0 <= i && i < longitud());
    Nodo* actual = _primero;
    for (int j = 0; j < i; ++j) {
        actual = actual->_sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    Nodo* actual = _primero;
    while (actual != nullptr){
        o << actual->valor << ", " << endl;
        actual = actual->_sig;
    }
}

void Lista::copiarNodos(const Lista &l) {
    Nodo* actual = l._primero;
    while (actual != nullptr){
        agregarAtras(actual->valor);
        actual = actual->_sig;
    }
}

void Lista::destruirNodos() {
    Nodo* actual = _primero;
    while (actual != nullptr){
        Nodo* siguiente = actual->_sig;
        delete actual;
        actual = siguiente;
    }
    _ultimo = nullptr;
    _primero = nullptr;
}