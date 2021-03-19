#include <iostream>
#include "Trie.h"
#include <fstream>
#include <vector>
//$include "Controladora.h"

using namespace std;

int main(int argc, char const *argv[]){
    Trie* t = new Trie();
    //t->insert("domtor");
    //t->insert("precio");
    
    t->insert("hola");
    t->insert("profesor");
    t->insert("productor");
    t->pred("pr");
    
    //Controladora *c = new Controladora(argv[1], argv[2], argv[3], 4);
   /* t->insert("hola");
    
    t->insert("chao");

    if(t->search("ola")==false){
        cout<<"si martina, el nico es weta"<<endl;
    }
    t->search("hola");
    */
  /*	vector<string> list;
    ifstream hola;
    string line;
    hola.open("hola.txt");

    while(!hola.eof()){
    	cout <<"si";

        hola >> line;
        if(line.find("%") == -1){
        	list.push_back(line);
        }
        
    }
   	hola.close();
    for (int i = 0; i < list.size(); ++i){
    	t->insert(list[i]);
    	if(t->search(list[i])){
    		cout << list[i] << endl;
    	}
    }
    //printf(list);
    //sort(list.begin(), list.end());
    //printf(list);*/
    return 0;
}
