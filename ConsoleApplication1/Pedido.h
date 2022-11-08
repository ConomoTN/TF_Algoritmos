#pragma once
#include<string>
#include <sstream>
using namespace std;

class Pedido {
	string x, y;
	int cod;
public:
	Pedido(string res, string ped, int codi) {
		this->x = res;
		this->y = ped;
		this->cod = 0;

	};
	string toString() {
		ostringstream ss;
		ss << "Pedido(";
		ss << x;
		ss << ", ";
		ss << y;
		ss << ")";
		return(ss.str());
	}
};