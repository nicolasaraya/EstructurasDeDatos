#include <iostream>
#include <vector>
using namespace std;

struct Nodo{
    bool fin;
    Nodo* siguiente[27];
};


class Trie{
    private:
        Nodo* root;
    public:
        Trie();
        ~Trie();
        void insert(string s);
        bool search(string s);
        vector<string> pred(string s);
        vector<string> Relleno(Nodo* n, vector<string> respuestas, string s);
};