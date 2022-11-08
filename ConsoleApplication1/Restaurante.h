#pragma once
#include <string>
#include <sstream>

using namespace std;


class Restaurante
{
public:
	string x, y;
	int cod;
	float rep;
	int dem;
public:
	Restaurante(string nom, int codi,float rep, int dem) {
		this->x = nom;
		this->cod = codi;
		this->rep = rep;
		this->dem = dem;
	};
	string toString() {
		ostringstream ss;
		ss << "El restaurante:  ";
		ss << x << " " << endl;
		ss << "Reputacion de: ";
		ss << rep << "  y se demorara:  ";
		ss << dem << "  minutos" << endl;
		return(ss.str());
	}
	~Restaurante();

	string getNombre();
	string getDir();
	int getNum();
	int getRep();
	int getDem();
	string getPed();

private:

};


Restaurante::~Restaurante()
{
}
int Restaurante::getNum()
{
	return cod;
}

inline int Restaurante::getRep()
{
	return rep;
}

inline int Restaurante::getDem()
{
	return dem;
}
