#include "Controladora.h"
#include <vector>
#include <iostream>
using namespace std;

Controladora::Controladora(string dic, string pref, string res, int k){
    diccionario.open(dic);
    string line;

    while(!diccionario.eof()){
    	//cout <<"si";
        diccionario >> line;
        if(line.find("%") == -1){
        	listD.push_back(line);
        }
        
    }
   	diccionario.close();
       
    line.clear();

    prefijos.open(pref);
    while(!prefijos.eof()){
        prefijos>>line;
        if(line.find("%")==-1){
            listP.push_back(line);
        }
    }
    prefijos.close();



   	p = new Predictor(listD);



   	
}
