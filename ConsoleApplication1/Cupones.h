#pragma once
#include <string>
#include <sstream>

using namespace std;
class Cupon {
private:
	string s, nom;
	int din;

public:
	Cupon() {
		for (size_t i = 0; i <= 10; ++i) {
			char c = 65 + rand() % (90 - 65 + 1);
			s.push_back(c);
		}
		nom = s;
		din = 5 + (rand() % 30);
	}
	string toString() {
		ostringstream ss;
		ss << "Codigo del cupon: ";
		ss << nom << " " << endl;
		ss << "Valor de: ";
		ss << din<< " soles";
		return(ss.str());
	}
	int getDin() {
		return din;
	}
};
