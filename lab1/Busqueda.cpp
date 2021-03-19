#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n) {
	this->vec = new int[n];

	srand(time(NULL));

	for(int i=0;i<n;i++) {
		this->vec[i] = rand() % n + 1;
	}
	this->tam = n;
	sort(this->vec,this->vec + this->tam);

	
	for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
	puts("");
}

Busqueda::~Busqueda(){
	delete[] this->vec;
}
int Busqueda::size(){
	return this->tam;
}

int Busqueda::lineal(int num){
	for(int i=0; i<tam; i++){
		if(vec[i]== num){
			return i;
		}
	}
	return -1;
}

int Busqueda::binariaRecursiva(int num,int l,int r){
	int p=(l+r)/2;
	if(r>=l){
		if(num==vec[p]){
			return p;
		}
		if(num>vec[p]){
			return binariaRecursiva(num,p+1,r);
		}
		if(num<vec[p]){
			return binariaRecursiva(num,l,p-1);
		}

	}
	return -1;
}

int Busqueda::binariaIterativa(int num){
	int inicio=0, final=tam-1, p;
	while(inicio <= final){
		p=(inicio+final)/2;
		if(vec[p] == num){
			return p;
		}
		if(num<vec[p]){
			final=p-1;
		}
		if(num>vec[p]){
			inicio=p+1;
		}
	}
	return -1;
}

int Busqueda::binariaRecursiva(int num){
	return binariaRecursiva(num,0,tam-1);
}