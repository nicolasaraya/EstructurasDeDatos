#include <bits/stdc++.h>
#include "PriorityQueueUnsorted.h"


using namespace std;



PriorityQueueUnsorted::PriorityQueueUnsorted(){
    
}

PriorityQueueUnsorted::~PriorityQueueUnsorted(){
}

bool PriorityQueueUnsorted::empty(){  //O(1)
    return _arr.empty();
}

int PriorityQueueUnsorted::size(){ //O(1)
    return _arr.size();
}

int PriorityQueueUnsorted::top(){   //O(n)
    if(empty()) return INT_MIN;
    int min = _arr.at(0);
    int menor = 0; 
    for(int i = 0; i<_arr.size(); i++){
        if(_arr.at(i)<min){
            min=_arr.at(i);
            menor=i;
        }
    }
    return _arr.at(menor);

}

void PriorityQueueUnsorted::push(int n){   //O(1)
    _arr.push_back(n);
}

void PriorityQueueUnsorted::pop(){       //O(n)
    if(empty()) return;
    int min = _arr.at(0);
    int menor = 0; 
    for(int i = 0; i<_arr.size(); i++){
        if(_arr.at(i)<min){
            min=_arr.at(i);
            menor=i;
        }
    }
    _arr[menor]=_arr.back();
    _arr.pop_back();

}

void PriorityQueueUnsorted::print(){
    vector<int>::iterator it;
    for(it = _arr.begin(); it!=_arr.end(); it++){
        cout<<*it<<" ";

    }
    cout<<endl;
}

