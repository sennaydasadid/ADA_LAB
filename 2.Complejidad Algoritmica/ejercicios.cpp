#include <iostream>
using namespace std;
int main(){
    int N;
    cout<<"Valor de N: ";
    cin>>N;

    //Ejercicio 1
    for (int i = 0; i < N; i++)
        if (i%2==0)
            cout<<i;
    //Complejidad: O(N)

    //Ejercicio 2
    for (int  i = 0; i < N; i++)
        if (i%2==0)
            cout<<i;
    for (int i = 0; i < N; i++)
        if (i%2 !=0)
            cout<<i;
    //Complejidad: O(N)
    
    //Ejercicio 3
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout<< i<<","<<j;
    //Complejidad: O(N^2)
        
    //Ejercicio 4 
    int i=1;
    while (i<N){
        cout<<i;
        i=i*2;
    }
    //Complejidad: O(log N)
    
    //Ejercicio 5
    string A{0,1,2,3,4};
    string B{5,6,7,8,9};
    for (int i = 0; i <A.length(); i++)
        for (int j = 0;j< B.length(); j++)
            cout<<A[i]<<","<<B[j];
    //Complejidad: O(A*B)

    //Ejercicio 6
    for (int i = 0; i < N; i++){
        int j=1;
        while (j<N){
            cout<<j;
            j=j*2;
        }  
    }
    //Complejidad: O(N*logN)

    //Ejercicio 7
    N=100;
    if(N%2==0)
        cout<<"par";
    else
        cout<<"impar";
    //Complejidad: O(1)
}

