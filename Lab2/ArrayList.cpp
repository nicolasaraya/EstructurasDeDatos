#include "ArrayList.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList(){   
    capacity=5000;
    mysize=0;
    myarray = new int(capacity);
}
ArrayList::~ArrayList(){
    delete[] myarray;
    mysize=0;
}
void ArrayList::insert(int n){   //O(n)
	mysize++;
    if(capacity<mysize){
        cout<<"Capacidad Excedida"<<endl;
        agrandar();
        cout<<"extendido"<<endl;
    }
    int aux = myarray[0];
    for(int i = 1; i<mysize; i++){   //O(n)
        int aux2 = myarray[i];
        myarray[i]=aux;
        aux=aux2;
    }
    myarray[0]=n;
}
void ArrayList::pop(){          //O(1)
    myarray[mysize-1]=0;
    mysize--;

}
int ArrayList::at(int pos){    //O(1)
    return myarray[pos-1];
}
int ArrayList::size(){
    return mysize;
}
void ArrayList::agrandar(){          //O(n)
    int * aux = myarray;
    myarray = new int(capacity*2);
    for(int i=0; i<mysize; i++){          //O(n)
        myarray[i]=aux[i];
    }
    capacity=capacity*2;
    free(aux);
}

void ArrayList::print(){
    for(int i=0; i<mysize; i++){
        cout<<myarray[i]<<" ";
    }
}


