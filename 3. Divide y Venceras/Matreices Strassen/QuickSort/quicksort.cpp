#include <iostream>
using namespace std;
void quickSort(int s[], int l, int r){
    if (l<r){
        int i=l, j=r, x=s[l];
        while (i<j){
            while(i<j && s[j]>=x)
                j--;
            if(i<j)
                s[i++]=s[j];
            while(i<j && s[i]<x)
                i++;
            if(i<j)
                s[j--]=s[i];
        }
        s[i]=x;
        quickSort(s,l,i-1);
        quickSort(s,i+1,r);
    }
}
int main(){
    int array[]={23,43,12,42,11,27,32};
    int tam=sizeof(array)/sizeof(int);
    for(int i=0; i <tam;i++){
        cout<<array[i]<<" , ";
    }cout<<endl;
    quickSort(array,0,tam-1);
    for(int i=0; i <tam;i++){
        cout<<array[i]<<" , ";
    }cout<<endl;
    return 0;
}