#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int peso;
    int valor;
};

int mochila(vector<Item>& items, int capacidad, int indice_actual) {
    if (indice_actual < 0 || capacidad <= 0) 
        return 0;
    if (items[indice_actual].peso > capacidad) 
        return mochila(items, capacidad, indice_actual - 1);

    int incluir_actual = items[indice_actual].valor + mochila(items, capacidad - items[indice_actual].peso, indice_actual - 1);
    int excluir_actual = mochila(items, capacidad, indice_actual - 1);

    return max(incluir_actual, excluir_actual);
}

int main() {
    int capacidad = 10;
    vector<Item> items = {{2, 6}, {3, 8}, {4, 10}, {5, 12}};
    int itemCount = items.size();

    int maxvalor = mochila(items, capacidad, itemCount - 1);

    cout << "El valor maximo  es: " << maxvalor << endl;

    return 0;
}



