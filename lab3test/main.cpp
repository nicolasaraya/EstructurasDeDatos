#include <iostream>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;

void SolucionUno(vector<int> array, vector<int> q){
    int n=array.size();
    for(int i=0; i<q.size(); i++){
        for(int j=q[i]; j<n; j++){
            if(array[q[i]]<array[j]){
                //cout<<array[j]<<" ";
                break;
            }
            if(j==n-1){
                //cout<<"-1"<<" ";
            }
        }
    }
    //cout<<endl;
}

int* Preprocesado(vector<int> array){
    int n = array.size();
    int* ans = new int[n];
    stack<int> s;
    for(int i = 0; i<n; i++){
        int size=s.size();
        for(int j=0; j<size; j++){
            if(array[s.top()]>=array[i] ) break;
            else{
                ans[s.top()] = array[i];
                s.pop();
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()]=-1;
        s.pop();
    }
    return ans;
}



void SolucionDos(vector<int> array, vector<int> q){
    int* ans = Preprocesado(array);
    for(int i = 0; i<q.size(); i++){
        //cout<<ans[q[i]]<<" ";
    }
    //cout<<endl;
}
void Creciente(vector<int>* array){
    int n=array->size();
    array->clear();
    for(int i=0; i<n; i++){
        array->push_back(i+1);
    }
}
void Decreciente(vector<int>* array){
    int n=array->size();
    array->clear();
    for(int i=0; i<n; i++){
        array->push_back(n-i);
    }
}
void NoOrdenado(vector<int>* array){
    srand(time(NULL));
    int n=array->size();
    array->clear();
    for(int i=0; i<n; i++){
        array->push_back(rand()%(n+1));
    }   
}
void Print(vector<int> array){
    int n=array.size();
    for(int i=0; i<n; i++){
        cout<<array.at(i)<<" ";
        if(i==n-1){cout<<endl;}
    }
}

int main(){
    srand(time(NULL));
    int n, rep=100;
    cin>>n;
    vector<int> array;
    vector<int> q;
    vector<int>* a = &array;
    
    
    for(int i=0; i<n; i++){
        q.push_back(i);
        array.push_back(i);
    }

    ////////////////////////////7
    cout<<"Creciente:"<<endl;
    clock_t start = clock();
    for(int i=0; i<rep; i++){
        SolucionUno(array,q);
    }
    double time;
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionUno: "<<time/rep<<endl;
    ///////////////////////////////////////////
    start = clock();
    for(int i=0; i<rep; i++){
        SolucionDos(array,q);
    }
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionDos: "<<time/rep<<endl<<endl;
    ///////////////////////////////////////////
    Decreciente(a);
    cout<<"Decreciente:"<<endl;
    start = clock();
    for(int i=0; i<rep; i++){
        SolucionUno(array,q);
    }
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionUno: "<<time/rep<<endl;
    ///////////////////////////////////////////
    start = clock();
    for(int i=0; i<rep; i++){
        SolucionDos(array,q);
    }
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionDos: "<<time/rep<<endl<<endl;
    ///////////////////////////////////////////
    NoOrdenado(a);
    cout<<"NoOrdenado:"<<endl;
    start = clock();
    for(int i=0; i<rep; i++){
        SolucionUno(array,q);
    }
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionUno: "<<time/rep<<endl;
    ///////////////////////////////////////////
    start = clock();
    for(int i=0; i<rep; i++){
        SolucionDos(array,q);
    }
    time = (double)(clock()-start)/CLOCKS_PER_SEC;
    cout<<"solucionDos: "<<time/rep<<endl<<endl;







    
    return 0;
}
