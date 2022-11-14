#ifndef __COLA_H__
#define __COLA_H__
#include "Nodo.h"
#include <iostream>
#include "Pedido.h"
#include <functional>

using namespace std;

template<class T>
class Cola {
private:
	typedef function<int(T*, char*)>Comp;

	Nodo<T>* inicio;
	Nodo<T>* fin;
	Comp comparar;
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}

	void enqueue(T v);
	T dequeue();
	bool esVacia();
	void mostrar();
	T buscarCodigo(char* codigo);
};

template<class T>
bool Cola<T>::esVacia() {
	return (inicio == NULL);
}

template<class T>
void Cola<T>::enqueue(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {

		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}

template<class T>
T Cola<T>::dequeue() {
	if (esVacia() == true) return 0;
	T dato = inicio->valor;

		if (inicio == fin) {
			inicio = NULL;
			fin = NULL;
		}
		else {
			inicio = inicio->siguiente;
		}
		return dato;
	
	
}
template<class T>
void Cola<T>::mostrar()
{
	Nodo<T>* nodo = inicio;
	if (esVacia()==true) {
		cout << "La cola esta vacia";
	}
	else {
		do {
			Pedido* ped = (Pedido*)(nodo->valor);
			cout << ped->toString();
			if (ped != NULL)
				cout << "->";
			nodo = nodo->siguiente;
		} while (nodo != nullptr);
		cout << "\n";
	}
	
}

//template<class T>
//T Cola<T>::buscarCodigo(char* codigo)
//{
//	
//}

#endif
