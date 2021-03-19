#ifndef Map
#define Map
#include <iostream>
using namespace std; 

class ADTMap{
    public:
        virtual void insert(pair<string, int>) = 0;
        virtual void erase(string) = 0;
        virtual int at(string) = 0; 
        virtual int size() = 0;
        virtual bool empty() = 0;
};
#endif