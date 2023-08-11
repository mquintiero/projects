#include <iostream>
#include "Inventory.h"
int main() {
    Trie stocks;
    Inventory inv = Inventory(stocks);
    string s = "crema";
    string ss = "a";
    string sss = "b";
    string ss2 = "c";
    int c = 3;
    int p = 2500;
    inv.addProduct(s, c, p);
    inv.addProduct(ss, c, p);
    inv.editStock(ss, 8);
    inv.editPrice(ss, 3000);
    inv.editName(ss, ss2);
    inv.deleteStock(ss);
    inv.addProduct(sss, c, p);

    return 0;
}
