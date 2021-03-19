#include <vector>
#include "Predictor.h"
using namespace std;

Predictor::Predictor(vector<string> s){
	t = new Trie();
	
	for (int i = 0; i < s.size(); ++i){
    	t->insert(s[i]);
    	if(t->search(s[i])){
    		cout << s[i] << endl;
    	}
    }

}
Predictor::~Predictor(){}
vector<string> Predictor::Search(vector<string> p, int k){
	for(int i=0; i<p.size(); i++){
		

	}
}