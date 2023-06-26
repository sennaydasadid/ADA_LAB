#include <iostream>
#include <ctime>
#include"Strassen.h"
using namespace std;

void Init_Matrix(int N, int** MatrixA){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            MatrixA[i][j]=rand()%10+1;
}
void print(int** MatrixA , int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<MatrixA[i][j]<<" ";
        cout<<endl;        
    }cout<<endl;
}
int main(){

    clock_t startTime_For_Normal_Multiplication;
    clock_t endTime_For_Normal_Multiplication;
    clock_t startTime_For_Strassen;
    clock_t endTime_For_Strassen;
    time_t start, end;
    int MatrixSize;
    cout<<"Dimension de la matriz: ";
    cin>>MatrixSize;
    int N=MatrixSize;
    int**MatrixA=new int*[N];
    int**MatrixB=new int*[N];
    int**MatrixC=new int*[N];
    int**MatrixT=new int*[N];
    for(int i=0;i<N;i++){
        MatrixA[i]=new int[N];
        MatrixB[i]=new int[N];
        MatrixC[i]=new int[N];
        MatrixT[i]=new int[N];
    }
    Init_Matrix(N,MatrixA);
    Init_Matrix(N,MatrixB);

    print(MatrixA,N);
    print(MatrixB,N);

    cout<<"Multiplicacion clasica"<<endl;
    cout<<"Hora de incio: "<<(startTime_For_Normal_Multiplication=clock())<<endl; 
    Matrix_Mul(N,MatrixA,MatrixB,MatrixT);
    cout<<"Hora de finalizacion: "<<(endTime_For_Normal_Multiplication=clock())<<endl;
    print(MatrixT,N);

    cout<<"Multiplicacion Strassen"<<endl;
    cout<<"Hora de incio: "<<(startTime_For_Strassen=clock())<<endl; 
    Strassen(N,MatrixA,MatrixB,MatrixC);
    cout<<"Hora de finalizacion: "<<(endTime_For_Strassen=clock())<<endl;
    print(MatrixC,N);

    return 0;
}