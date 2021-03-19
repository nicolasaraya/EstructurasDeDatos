#include <vector>
#include <iostream>

using namespace std;

class Iterador{
    private:
        vector<int>::iterator it;
        vector<int> st; 
    public:
        Iterador(vector<int> *stck);
        ~Iterador();
        bool hasNext();
        int next();
};