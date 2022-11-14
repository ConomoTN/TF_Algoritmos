#pragma once
#include <string>
#include <sstream>
using namespace std;

class Tarjeta {

private:
	int _numero, _fecha, _cod;
	string nom;
public:
	Tarjeta(int num, int fecha, int cod, string nomb) {
		this->_numero = num;
		this->_fecha = fecha;
		this->_cod = cod;
		this->nom = nomb;
	};
	string toString() {
		ostringstream ss;
		ss << "Tarjeta: ";
		ss << _numero;
		ss << ", ";
		ss << _fecha;
		ss << " ***";
		return(ss.str());
	}
};