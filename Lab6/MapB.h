#include "ADTMap.h"
#include <vector>

using namespace std;

class MapB : public ADTMap{
    private:
        long long int colisiones, colisionesAt;
        int sz;
        int N;
        pair<string, int> null; 
        vector<pair<string,int>> hash; 
        void insertHash(pair<string,int>); 
        void newHash(); 
    public:
        MapB(int); 
        void insert(pair<string, int>);
        void erase(string);
        int at(string); 
        int size();
        bool empty();
        void print();
        void printColisiones();
};