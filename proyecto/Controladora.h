#include "Predictor.h"
#include <vector>
#include <fstream>

using namespace std;
class Controladora {
	private:
		Predictor *p;
		vector<string> listD, listP;
		ifstream diccionario, prefijos, resultados;
    	
	public:
		Controladora(string dic, string pref, string res, int k);
		~Controladora();
		void Busqueda(string s);

};