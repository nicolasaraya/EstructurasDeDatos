    #include "Funciones.h"
#include <bits/stdc++.h>

using namespace std;


Funciones::Funciones(int n){
    mysize=n;
    srand(time(NULL));
    myarray=new int[mysize];
}
int Funciones::SolucionUno(int i){
    for(int j=i+1; j<mysize; j++){
        if(myarray[i]<myarray[j]){
            return myarray[j];
        }
    }
    return (-1);
}
int Funciones::SolucionDos(int i){
    return (1);
}
void Funciones::Creciente(){
    for(int i=0; i<mysize; i++){
        myarray[i]=i+1;
    }
}
void Funciones::Decreciente(){
    for(int i=0; i<mysize; i++){
        myarray[i]=mysize-i;
    }
}
void Funciones::NoOrdenado(){
    for(int i=0; i<mysize; i++){
        myarray[i]=rand()%(mysize+1);
    }   
}
void Funciones::Print(){
    for(int i=0; i<mysize; i++){
        cout<<myarray[i]<<" ";
    }
}