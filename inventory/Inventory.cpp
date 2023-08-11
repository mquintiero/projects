#include "Inventory.h"
/*
 * Construye un stock a partir de un nombre (del producto), la cantidad que hay (stock) y el precio
 */
Inventory::Inventory(Trie inventory) : _inventory(inventory){}

/*
 * Agrega un articulo al inventario
 */
void Inventory::addProduct(const string name, int& cantidad, int& precio){
    stock s(cantidad, precio);
    _inventory.agregar(name, s);
}
/*
 * Edita a la cantidad de unidades que hay
 */
void Inventory::editStock(string name, int cantidad){
    _inventory.editarCantidad(name, cantidad);
}

/*
 * Edita el precio de la unidad
 */
void Inventory::editPrice(string name, int precio){
    _inventory.editarPrecio(name, precio);
}

/*
 * Edita el nombre de la unidad
 */
void Inventory::editName(string name, string newName){
    stock stockToCopy = _inventory.darStock(name);
    _inventory.agregar(newName, stockToCopy);
    _inventory.erase(name);
}

/*
 * Elimina un articulo del inventario
 */
void Inventory::deleteStock(string name){
    _inventory.erase(name);
}