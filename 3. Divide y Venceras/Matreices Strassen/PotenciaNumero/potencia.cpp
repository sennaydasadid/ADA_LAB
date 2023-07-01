#include <iostream>
using namespace std;

int potencia(int base, int exponente) {
    if (exponente == 0)
        return 1;

    int temp = potencia(base, exponente / 2);
    int resultado = temp * temp;

    if (exponente % 2 != 0) {
        if (exponente > 0)
            resultado *= base;
        else
            resultado /= base;
    }
    return resultado;
}

int main() {
    int base;
    int exponente;

    cout << "Base: ";
    cin >> base;

    cout << "Exponente: ";
    cin >> exponente;

    int resultado = potencia(base, exponente);

    cout << "El resultado de es: " << resultado << endl;

    return 0;
}