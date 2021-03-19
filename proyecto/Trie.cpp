#include <iostream>
#include <vector>
#include "Trie.h"

using namespace std; 

Trie::Trie(){
    root = new Nodo();
    root->fin = false;
    for(int i=0; i<27; i++){
        root->siguiente[i]=NULL;
    }
}

Trie::~Trie(){
   /* if(root==NULL){
        delete root;
    }
    else{
        Nodo *aux;
        Nodo *aux2; //puntero para no cambiar la ref de head
        aux = root;
        aux2 = aux->siguiente;
        
        for (int i = 0; i <; i++){     
            delete aux;
            aux = aux2;
            aux2 = aux->siguiente[];  
        }       
        delete aux;     
    }*/

}

void Trie::insert(string s){
    Nodo* aux=root;
    for(int i=0; i<s.size(); i++){
        if(aux->siguiente[s[i]-97]==NULL){
            aux->siguiente[s[i]-97]=new Nodo();
        }
        aux = aux->siguiente[s[i]-97];
    }
    aux->fin = true;

}

bool Trie::search(string s){
    if (root == NULL) return false;
    Nodo* aux=root;
    for(int i=0; i<s.length(); i++){
        aux=aux->siguiente[s[i]-97];
        if(aux==NULL) return false;
    }
    return aux->fin;
}


vector<string> Trie::pred(string s){
    vector<string> respuestas;
    respuestas.push_back("chao");
    if (root == NULL) return respuestas;
    Nodo* aux=root;
    for(int i=0; i<s.length(); i++){
        aux=aux->siguiente[s[i]-97];
        if(aux==NULL) return respuestas;
    }
    respuestas = Relleno(root, respuestas, "");
    for(int i=0; i<respuestas.size(); i++){
        cout<<respuestas[i]<<endl;
    }
    return respuestas;
}



vector<string> Trie::Relleno(Nodo* n, vector<string> respuestas, string st){
    if(n->fin==true){
        respuestas.push_back(st);
        return respuestas;
    }
    for(int i=0; i<27; i++){
        if(n->siguiente[i]!=NULL){
            
            respuestas = Relleno(n->siguiente[i], respuestas, st+=(i+97));
        }
    }
    return respuestas;
}






