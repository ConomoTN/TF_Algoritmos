#pragma once
#include<string>
#include <sstream>
#include "Cola.h"
#include "Pedido.h"
using namespace std;

class Usuario {
	string x, y;
	int cod;
	Cola<Pedido*>* cola;

public:
	Usuario(string nom, string dir, int codi, Cola<Pedido*>* cola) {
		this->x = nom;
		this->y = dir;
		this->cod = 0;
		this->cola = cola;
	};
	string toString() {
		ostringstream ss;
		ss << x;
		return(ss.str());
	}
	void AgregarPedido(Pedido* ped);
	string getNombre();
	string getDir();
	int getNum();
	string getPed();



};


void Usuario::AgregarPedido(Pedido* ped)
{
	cola->enqueue(ped);
}
string Usuario::getNombre() {
	return x;
}
string Usuario::getDir() {
	return y;
}
int Usuario::getNum() {
	return cod;
}
string Usuario::getPed()
{
	ostringstream ss;
	Pedido* elem;
	do {
		elem = cola->dequeue();
		ss << " "<<elem->toString() << " | ";
	} while (!cola->esVacia());
	return(ss.str());
}