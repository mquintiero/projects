#ifndef INVENTORY_TRIE_H
#define INVENTORY_TRIE_H
#include "string"
#include "vector"
using namespace std;
struct stock{
    int cantidad;
    int price;
    stock(int cant, int precio) : cantidad(cant), price(precio){};
};


class Trie {
public:
    Trie();
    ~Trie();
    Trie(const Trie& aCopiar);
    void agregar(const string name, stock* stock);
    bool pertenece(string name) const;
    void editarCantidad(string name, int cantidad);
    void editarPrecio(string name, int precio);
    Trie& operator=(const Trie& d);
private:
    struct Nodo {
        vector<Nodo*> hijos;
        bool finPalabra;
        stock* _stock;
        Nodo(): hijos(27, nullptr), finPalabra(false), _stock(nullptr) {}
    };
    void copiarNodos(Trie::Nodo *& raiz, const Trie::Nodo* raiz_a_copiar);
    void destruirNodos(Nodo* &);
    Nodo* _raiz;
};

#endif //INVENTORY_TRIE_H
