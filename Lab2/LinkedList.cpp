#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    mysize = 0;
    head = new nodo();
}
LinkedList::~LinkedList(){
    struct nodo *aux;
    for(int i=0; i<mysize; i++){
        aux=head->siguiente;
        delete head->siguiente;
        head->siguiente=aux->siguiente;
    }
    mysize=0;
    delete head;  
}
void LinkedList::insert(int x){      //O(1)
    struct nodo *aux;
    aux = new nodo();
    if(mysize>0){
        aux->n = x;
        aux->siguiente = head->siguiente;
        head->siguiente = aux;
        mysize+=1;
    }
    if(mysize==0){
        aux->n = x;
        head->siguiente = aux;
        mysize+=1;
    }
}
void LinkedList::pop(){            //O(n)
    struct nodo *aux;
    aux = head;
    if(mysize==1){
        delete head->siguiente;
    }
    for(int i = 1; i<=mysize-1; i++){
        aux=aux->siguiente;
        if(i==mysize-1){
            delete aux->siguiente;
            break;
        }
    }
    mysize-=1;
    
}
int LinkedList::at(int pos){         //O(n)
    if(pos>mysize){
        return -1;
    }
    struct nodo * aux; 
    aux = head->siguiente;
    int i=1;
    while(i<pos){
        aux=aux->siguiente;
        i++;
    }
    return aux->n;
}
int LinkedList::size(){
    return mysize;
}

void LinkedList::print(){
    struct nodo *aux;
    aux = head->siguiente;
    for(int i = 0; i<mysize; i++){
        int x = aux->n;
        cout<<x<<" ";
        aux=aux->siguiente;

    }
}