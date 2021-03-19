#include "MapB.h"
#include <iostream>

using namespace std; 

MapB::MapB(int N){
    this->N=N;
    sz=0;
    null = {"", INT16_MIN};
    hash.assign(N+1, null);
    colisiones=0;
    colisionesAt=0;
}

void MapB::insertHash(pair<string,int> par){
    int suma=0;
    for(int i = 0; i<par.first.size(); i++){
        suma += par.first[i];
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

void MapB::newHash(){
    vector<pair<string, int>> aux;
    N = N*2; 
    aux.assign(N+1, null);
    for(int i = 0; i<hash.size(); i++){
        if(hash[i]!=null){
            string s = hash[i].first;
            long long int suma=0;
            for(int i = 0; i<s.size(); i++){
                suma += s[i];
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
void MapB::insert(pair<string,int> par){
    if(size()>=N/2) newHash();
    insertHash(par); 
    sz++;
    
}
void MapB::erase(string s){
    int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma+=s[i];
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
int MapB::at(string s){
    int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma+=s[i];
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
int MapB::size(){
    return sz;
}
bool MapB::empty(){
    if(size()==0) return true;
    return false;
}

void MapB::print(){
    for(int i = 0; i<hash.size(); i++){
        if(hash[i]!=null) cout<<hash[i].first<<" "<<hash[i].second<<endl;
    }
}
void MapB::printColisiones(){
    cout<<"MapB"<<endl<<"Colisiones Insert: "<<colisiones<<endl<<"Colisiones at: "<<colisionesAt<<endl;
}