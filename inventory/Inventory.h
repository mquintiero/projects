#ifndef INVENTORY_INVENTORY_H
#define INVENTORY_INVENTORY_H

#include "Trie.h"
#include "string"

using namespace std;

class Inventory{
public:
    /*
     * Construye un inventario a partir de una lista de stocks
     */
    Inventory(Trie inventory);

    /*
     * Agrega un articulo al inventario
     */
    void addProduct(string name, int cantidad, int precio);

    /*
     * Edita a la cantidad de unidades que hay
     */
    void editStock(string name, int cantidad);

    /*
     * Edita el precio de la unidad
     */
    void editPrice(string name, int precio);

    /*
     * Edita el precio de la unidad
     */
    void editName(string name, string newName);

    /*
     * Elimina un articulo
     */
    void deleteStock(string name);

private:
    Trie _inventory;

};

#endif //INVENTORY_INVENTORY_H
