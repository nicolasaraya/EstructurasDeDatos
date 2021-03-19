#include "Funciones.h"
#include <iostream>

using namespace std;

int main(){
    Funciones* f = new Funciones(20);
    f->Creciente();
    f->Print();
    cout<<endl;
    cout<<f->SolucionUno(3)<<endl;

    f->Decreciente();
    f->Print();
    cout<<endl;
    cout<<f->SolucionUno(3)<<endl;
    
    f->NoOrdenado();
    f->Print();
    cout<<endl;
    cout<<f->SolucionUno(3)<<endl;
    



    
    return 0;
}
