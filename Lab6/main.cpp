#include <iostream>
#include "MapB.h"
#include "MapG.h"
#include "MapDH.h"
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    int n; 
    cin>>n;
    MapB* mb = new MapB(n/2);
    MapG* mg = new MapG(n/2);
    MapDH* dh = new MapDH(n/2); 
    vector<string> pal;
    for(int i = 0; i<n; i++){
        string s;
        s += 97 + rand()%24;
        s += 97 + rand()%24;
        s += 97 + rand()%24;
        s += 97 + rand()%24;
        s += 97 + rand()%24;
        pal.push_back(s);
        mb->insert(make_pair(s, rand()%50));
        mg->insert(make_pair(s, rand()%50));
        dh->insert(make_pair(s, rand()%50));
    }
    for(int i = 0; i<n; i++){
        mb->at(pal[i]);
        mg->at(pal[i]);
        dh->at(pal[i]);
    }
    mb->printColisiones();
    mg->printColisiones();
    dh->printColisiones();
    return 0; 
}