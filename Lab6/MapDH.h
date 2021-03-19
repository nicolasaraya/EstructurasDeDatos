#include "ADTMap.h"
#include <vector>

using namespace std;

class MapDH : public ADTMap{
    private:
        long long int colisiones, colisionesAt;
        int sz;
        int z; 
        int N;
        vector<pair<string,int>> hash;
        pair<string, int> null; 
        void insertHash(pair<string,int>); 
        void newHash(); 
    public:
        MapDH(int); 
        void insert(pair<string, int>);
        void erase(string);
        int at(string); 
        int size();
        bool empty();
        void print();
        void printColisiones();
};