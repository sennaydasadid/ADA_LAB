#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int izq, int medio, int decha) {
    int n1 = medio - izq + 1;
    int n2 = decha - medio;

    vector<int> IZ(n1), DE(n2);

    for (int i = 0; i < n1; i++)
        IZ[i] = arr[izq + i];
    for (int j = 0; j < n2; j++)
        DE[j] = arr[medio + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = izq; 

    while (i < n1 && j < n2) {
        if (IZ[i] <= DE[j]) {
            arr[k] = IZ[i];
            i++;
        } else {
            arr[k] = DE[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = IZ[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = DE[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int izq, int decha) {
    if (izq < decha) {
        int medio = izq + (decha - izq) / 2;

        mergeSort(arr, izq, medio);//izquierda
        mergeSort(arr, medio + 1, decha);//derecha

        merge(arr, izq, medio, decha);
    }
}

void printArray(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    
    int tam;
    cout<<"Numero de elemento del arreglo: ";
    cin>>tam;
    vector<int> arr(tam);
    cout<<"Elementos del arreglo: "<<endl;
    for(int i=0;i<tam;i++){
        cin>>arr[i];
    }

    cout << "Arreglo: "<<endl;
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Arreglo ordenado: "<<endl;
    printArray(arr);

    return 0;
}
