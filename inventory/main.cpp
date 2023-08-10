#include <iostream>
#include "Inventory.h"
int main() {
    Trie stocks;
    Inventory inv = Inventory(stocks);
    string s = "crema";
    inv.addProduct(s, 3, 2500);
    inv.editStock(s, 5);
    inv.editStock(s, -4);
    return 0;
}
