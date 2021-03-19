#include "MapDH.h"
#include <iostream>

using namespace std; 

MapDH::MapDH(int N){
    this->N=N;
    sz=0;
    null = {"", INT16_MIN};
    hash.assign(N+1, null);
    z=33; 
    colisiones=0;
    colisionesAt=0; 
}

void MapDH::insertHash(pair<string,int> par){
    long long int suma=0;
    for(int i = 0; i<par.first.size(); i++){
        suma = suma*z + par.first[i]; 
    }
    int j=0; 
    int hashresult = (suma%N + j*(13-(suma%13)) ) % N;
    while(hash[hashresult]!=null){
        if(hash[hashresult].first==par.first) return; 
        j++;
        colisiones++;
        hashresult = (suma%N + j*(13-(suma%13)) ) % N;
    }
    hash[hashresult]=par;
    sz++;
}

void MapDH::newHash(){
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
            int j=0; 
            int hashresult = (suma%N + j*(13-(suma%13)) ) % N;
            while(aux[hashresult]!=null){
                j++;
                hashresult = (suma%N + j*(13-(suma%13)) ) % N;
            }
            aux[hashresult] = hash[i];
        }
    } 
    hash = aux;
}
void MapDH::insert(pair<string,int> par){
    if(size()>=(N/2)) newHash();
    insertHash(par); 
    
}
void MapDH::erase(string s){
    long long int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma = suma*z + s[i]; 
    }
    int j = 0; 
    int hashresult = (suma%N + j*(13-(suma%13)) ) % N;
    if(hash[hashresult]!=null){
        if(hash[hashresult].first==s) {
            hash[hashresult]=null;
            sz--;
        }
        else{
            while(hash[hashresult].first!=s){
                j++;
                hashresult = (suma%N + j*(13-(suma%13)) ) % N;
                if(hashresult == (suma%N) % N) return;
            }
            hash[hashresult] = null;
            sz--; 
        }
    }

}
int MapDH::at(string s){
    long long int suma=0;
    for(int i = 0; i<s.size(); i++){
        suma = suma*z + s[i]; 
    }
    int j = 0; 
    int hashresult = (suma%N + j*(13-(suma%13)) ) % N;
    if(hash[hashresult]!=null){
        if(hash[hashresult].first==s) return hash[hashresult].second;
        else{
            while(hash[hashresult].first!=s){
                j++;
                colisionesAt++;
                hashresult = (suma%N + j*(13-(suma%13)) ) % N;
                if(hashresult == (suma%N) % N) return INT16_MIN;
            }
            return hash[hashresult].second;
        }
    }
}
int MapDH::size(){
    return sz;
}
bool MapDH::empty(){
    if(size()==0) return true;
    return false;
}

void MapDH::print(){
    for(int i = 0; i<N; i++){
        if(hash[i]!=null) cout<<hash[i].first<<" "<<hash[i].second<<endl;
    }
}
void MapDH::printColisiones(){
    cout<<"MapDH"<<endl<<"Colisiones Insert: "<<colisiones<<endl<<"Colisiones at: "<<colisionesAt<<endl;
}