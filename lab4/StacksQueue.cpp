#include "StacksQueue.h"
#include <iostream>

using namespace std;

//push_back pop_back back size empty

StacksQueue::StacksQueue(){
}

StacksQueue::~StacksQueue(){
    st1.clear();
    st2.clear();
}
void StacksQueue::push(int x){
    if(st2.empty()){
        st1.push_back(x);
    }
    else{
        while(!st2.empty()){
            st1.push_back(st2.back());
            st2.pop_back();
        }
        st1.push_back(x);
    }
}
void StacksQueue::pop(){
    if(st2.empty()){
        while(!st1.empty()){
            st2.push_back(st1.back());
            st1.pop_back();
        }
        if(!st2.empty()) st2.pop_back();
    }
    else{
        st2.pop_back();
    }
}
int StacksQueue::front(){
    if(st2.empty()){
        while(!st1.empty()){
            st2.push_back(st1.back());
            st1.pop_back();
        }
        if(!st2.empty()) return st2.back();
    }
    else{
        return st2.back();
    }
}
int StacksQueue::size(){
    return st1.size()+st2.size();
}
bool StacksQueue::empty(){
    if(size()==0) return true;
    else return false;
}

Iterador StacksQueue::begin(){
    if(st2.empty()){
        while(!st1.empty()){
            st2.push_back(st1.back());
            st1.pop_back();
        }
    }
    vector<int>* stack = &st2;
    Iterador i(stack);
    return i;
}

