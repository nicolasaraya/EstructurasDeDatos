#include "Iterador.h"


Iterador::Iterador(vector<int>* stck){
    st=*stck; 
    it = st.begin();
}
Iterador::~Iterador(){
    st.clear();    
}

bool Iterador::hasNext(){
    if( it == st.end()){
        return false;
    }
    else return true;
}

int Iterador::next(){
    int x = *it;
    it++;
    return x;
}