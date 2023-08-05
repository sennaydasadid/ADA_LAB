#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int peso;
    int valor;
};

struct Nodo {
    int nivel;
    int valor;
    int peso;
};

int mochila(const vector<Item>& items, int capacidad) {
    int itemCount = items.size();
    vector<Nodo> nodos(itemCount + 1);

    int maxvalor = 0;
    Nodo actual_Nodo = {0, 0, 0};
    int actual_nivel = 0;

    while (actual_nivel != -1) {
        if (actual_Nodo.nivel == itemCount) {
            if (actual_Nodo.valor > maxvalor) {
                maxvalor = actual_Nodo.valor;
            }
            actual_Nodo = nodos[actual_Nodo.nivel--];
        } else if (actual_Nodo.peso + items[actual_Nodo.nivel].peso <= capacidad) {
            nodos[actual_Nodo.nivel + 1] = {actual_Nodo.nivel + 1, actual_Nodo.valor + items[actual_Nodo.nivel].valor, actual_Nodo.peso + items[actual_Nodo.nivel].peso};
            actual_Nodo = nodos[actual_Nodo.nivel + 1];
        } else {
            actual_Nodo = nodos[actual_Nodo.nivel--];
        }

        if (actual_Nodo.nivel != -1) {
            actual_Nodo.valor += (capacidad - actual_Nodo.peso) * static_cast<double>(items[actual_Nodo.nivel].valor) / items[actual_Nodo.nivel].peso;
        }

        actual_nivel = actual_Nodo.nivel;
        if (actual_nivel < itemCount - 1) {
            nodos[actual_nivel + 1].valor = actual_Nodo.valor;
            nodos[actual_nivel + 1].peso = actual_Nodo.peso;
        }
    }

    return maxvalor;
}

int main() {
    vector<Item> items = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}};
    int capacidad = 10;

    int maxvalor = mochila(items, capacidad);
    cout << "El maximo valor es: " << maxvalor << endl;

    return 0;
}
