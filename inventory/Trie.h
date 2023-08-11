#ifndef INVENTORY_TRIE_H
#define INVENTORY_TRIE_H
#include "string"
#include "vector"
using namespace std;
struct stock{
    int cantidad;
    int price;
    stock(int cant, int precio) : cantidad(cant), price(precio){};
    stock() : cantidad(0), price(0){};
};


class Trie {
public:
    Trie();
    ~Trie();
    Trie(const Trie& aCopiar);
    void agregar(const string name, stock stock);
    bool pertenece(string name) const;
    stock darStock(string name);
    void erase(const string& name);
    void editarCantidad(string name, int cantidad);
    void editarPrecio(string name, int precio);
    Trie& operator=(const Trie& d);
private:
    struct Nodo {
        vector<Nodo*> hijos;
        bool finPalabra;
        stock _stock;
        Nodo(): hijos(27, nullptr), finPalabra(false), _stock() {}
    };
    void copiarNodos(Trie::Nodo *& raiz, const Trie::Nodo* raiz_a_copiar);
    void destruirNodos(Nodo* &);
    int cantDeHijos(Nodo n);
    Nodo* _raiz;
};

#endif //INVENTORY_TRIE_H
