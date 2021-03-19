#include <bits/stdc++.h>
#include "PriorityQueueHeap.h"

using namespace std;

PriorityQueueHeap::PriorityQueueHeap(){
    _arr.push_back(INT_MIN);
}

PriorityQueueHeap::~PriorityQueueHeap(){
}

bool PriorityQueueHeap::empty(){  //O(1)
    if(_arr.size()>1) return false;
    else return true; 
}

int PriorityQueueHeap::size(){  //O(1)
    return _arr.size()-1;
}

int PriorityQueueHeap::top(){ //O(1)
    if(empty()) return INT_MIN;
    return _arr.at(1);
}

void PriorityQueueHeap::push(int n){   //O(log n)
    _arr.push_back(n);
    upHeap(size());   //O(log n) en peor caso
}

void PriorityQueueHeap::pop(){     //O(log n)
    if(empty()) return;
    _arr[1]=_arr.back(); 
    _arr.pop_back();
    downHeap(1);  //O(log n) en peor caso
}

void PriorityQueueHeap::upHeap(int pos){     //O(log n) en peor caso
    int posUp = (pos)/2;
    if(posUp<1) return;
    if(_arr.at(posUp) > _arr.at(pos)){ 
        swap(_arr[pos], _arr[posUp]);
        upHeap(posUp);
    }
}
void PriorityQueueHeap::downHeap(int pos){  //O(log n) en peor caso
    int l = (2*pos);
    int r = (2*pos)+1;
    if(l > size()) return;
    if(l == size()){
        if(_arr.at(pos)>_arr.at(l)){
            swap(_arr[pos], _arr[l]);
        }
        return;
    }
    if(_arr.at(pos)>_arr.at(l) || _arr.at(pos) > _arr.at(r)   ){
        int menor;
        if(_arr.at(l) <= _arr.at(r) ) menor = l;
        else menor = r;
        swap(_arr[pos], _arr[menor]);
        downHeap(menor);
    } 
}
void PriorityQueueHeap::print(){
    for(int i = 0; i<_arr.size(); i++) cout<<_arr.at(i)<<" ";
    cout<<endl;
}

