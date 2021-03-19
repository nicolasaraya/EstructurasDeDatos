#include "MapG.h"
#include <iostream>

using namespace std; 

MapG::MapG(int N){
    this->N=N;
    sz=0;
    null = {"", INT16_MIN};
    hash.assign(N+1, null);
    z=33; 
    colisiones=0;
    colisionesAt=0;
}

void MapG::insertHash(pair<string,int> par){
    long long int suma=0;
    for(int i = 0; i<par.first.size(); i++){
        suma = suma*z + par.first[i]; 
    } 
    int hashresult = suma%N;
    if(hash[hashresult] == null) hash[hashresult] = par;
    else{
        if(hash[hashresult].first == par.first) return;
        hashresult++;
        colisiones++;
        if(hashresult>N-1) hashresult = 0;
        while(hash[hashresult] != null ){
            hashresult++;
            colisiones++;
            if(hashresult>N-1) hashresult = 0;
        }
        hash[hashresult] = par; 
    }
}

void MapG::newHash(){
    vector<pair<string, int>> aux;
    N = N*2; 
    aux.assign(N+1, null);
    for(int i = 0; i<hash.size(); i++){
        if(hash[i]!=null){
            string s = hash[i].first;
            long long int suma=0;
            for(int i = 0; i<s.size(); i++){
                suma = suma*z + s[i]; 
            }
            int hashresult = suma % N;
            if(aux.at(hashresult)!=null){
                hashresult++; 
                if(hashresult>N-1) hashresult = 0;
                while(aux[hashresult]!=null){
                    hashresult++;
                    if(hashresult>N-1) hashresult = 0;
                }
            }
            aux[hashresult] = hash[i];
            }
    } 
    hash = aux;
}
void MapG::insert(pair<string,int> par){
    if(size()>=N/2) newHash();
    insertHash(par); 
    sz++;
    
}
void MapG::erase(string s){
    long long int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma = suma*z + s[i]; 
    }
    int hashresult = suma%N; 
    if(hash[hashresult]!=null){
        if(hash[hashresult].first==s) {
            hash[hashresult]=null;
            sz--;
        }
        else{
            hashresult++;
            if(hashresult>N-1) hashresult = 0;
            while(hash[hashresult].first!=s){
                hashresult++;
                if(hashresult>N-1) hashresult=0;
                if(hashresult==suma%N) break; 
            }
            if(hash[hashresult].first==s){ 
                hash[hashresult] = null;
            }
        }
    }
}
int MapG::at(string s){
    long long int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma = suma*z + s[i]; 
    }
    int hashresult = suma%N;
    if(hash[hashresult]!=null){
        if(hash[hashresult].first==s) return hash[hashresult].second;
        else{
            hashresult++;
            colisionesAt++;
            if(hashresult>N-1) hashresult = 0;
            while(hash[hashresult].first!=s){
                hashresult++;
                colisionesAt++;
                if(hashresult>N-1) hashresult=0;
                if(hashresult==suma%N) break; 
            }
            if(hash[hashresult].first==s) return hash[hashresult].second;
            else return INT16_MIN;
        }
    }
}
int MapG::size(){
    return sz;
}
bool MapG::empty(){
    if(size()==0) return true;
    return false;
}

void MapG::print(){
    for(int i = 0; i<hash.size(); i++){
        if(hash[i]!=null) cout<<hash[i].first<<" "<<hash[i].second<<endl;
    }
}
void MapG::printColisiones(){
    cout<<"MapG"<<endl<<"Colisiones Insert: "<<colisiones<<endl<<"Colisiones at: "<<colisionesAt<<endl;
}