#include <vector>
#include <string>
#include "Trie.h"
using namespace std;

class Predictor {
	private:
		Trie *t;
		vector<string> res;
		
	public:
		Predictor(vector<string> s);
		~Predictor();
		vector<string> Search(vector<string> p, int k);

};