#include <iostream>
#include <bits/stdc++.h>
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int main(){

    
    srand(time(NULL));
    int n, it=100;
    double timeAinsert=0, timeApop=0, timeAat=0;
    double timeLinsert=0, timeLpop=0, timeLat=0;
    cout<<"Ingrese n:"<<endl;
    cin>>n;
    LinkedList *l = new LinkedList();
    ArrayList *a = new ArrayList();
	clock_t start = clock();

//test LinkedList
	for(int i=0; i<it; i++){
		start = clock();
    	for(int j=0; j<n; j++){
    		l->insert(j);
    	}
    	timeLinsert += ((double)clock() - start) / CLOCKS_PER_SEC;

    	start = clock();
    	for(int m=0; m<n; m++){
    		l->at(rand()%n);
    	}
    	timeLat += ((double)clock() - start) / CLOCKS_PER_SEC; 

    	start = clock();
    	for(int k=0; k<n; k++){
	    	l->pop();
    	}
    	timeLpop += ((double)clock() - start) / CLOCKS_PER_SEC;
    }

    delete l;






//test ArrayList;

    for(int i=0; i<it; i++){
    	start = clock();
    	for(int j=0; j<n; j++){
    		a->insert(j);
    	}
    	timeAinsert += ((double)clock() - start) / CLOCKS_PER_SEC;

    	start = clock();
    	for(int l=0; l<n; l++){
    		a->at(rand()%n);
    	}
    	timeAat += ((double)clock() - start) / CLOCKS_PER_SEC;  

    	start = clock();
    	for(int k=0; k<n; k++){
    		a->pop();
    	}
    	timeApop += ((double)clock() - start) / CLOCKS_PER_SEC;
    }
	







    printf("\nArrayList\nInsert: %.10f\nAt: %.10f\nPop: %.10f\n", timeAinsert/it, timeAat/it, timeApop/it);
    printf("\nLinkedList\nInsert: %.10f\nAt: %.10f\nPop: %.10f\n", timeLinsert/it, timeLat/it, timeLpop/it);


    return 0;
}
