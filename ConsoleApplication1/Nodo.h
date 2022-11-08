#pragma once


template<class T>

class Nodo {
public:
	T valor;
	Nodo<T>* siguiente;
	Nodo<T>* anterior;
public:
	Nodo(T v, Nodo<T>* sig = NULL,Nodo<T>*ant = NULL) {
		valor = v;
		siguiente = sig;
		anterior = ant;
	}

};