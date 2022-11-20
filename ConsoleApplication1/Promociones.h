#pragma once
#include <string>
#include <sstream>

using namespace std;

class Promociones {
private:
	string nom;
	int descuento;
	int vec;
public:
	Promociones(string nomb, int desc) {
		nom = nomb;
		descuento = desc;
		vec = 0 + (rand() % 3);
	}

	string toString() {

		ostringstream ss;
		ss << "El restaurante:  ";
		ss << nom << " " << endl;
		ss << "Tiene ahora un: ";
		ss << descuento << "  % de desucuento en sus primeros:  ";
		ss << vec << "  pedidos" << endl;
		return(ss.str());
	}
	int getDesct() {
		return descuento;
	}
	string getNombre() {
		return nom;
	}
};