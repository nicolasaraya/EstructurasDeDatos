#include "ADTMap.h"
#include <vector>

using namespace std;

class MapG : public ADTMap{
    private:
        int z;  
        int sz;
        int N;
        long long int colisiones, colisionesAt;
        vector<pair<string,int>> hash;
        pair<string, int> null; 
        void insertHash(pair<string,int>); 
        void newHash(); 
        
    public:
        MapG(int); 
        void insert(pair<string, int>);
        void erase(string);
        int at(string); 
        int size();
        bool empty();
        void print();
        void printColisiones();
};