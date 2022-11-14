#pragma once
#include "Nodo.h"
#include "Pedido.h"
#include <string>
#include "Usuario.h"
#include <functional>

using namespace std;
typedef unsigned int uint;

template<class T>
class Lista {
private:
	Nodo<T>* inicio;
	int longitud;
public:
	Lista(): inicio(NULL),longitud(0){}
	~Lista(){}
	uint longi();
	void AgregarInicio(T v);
	void AgregarFinal(T v);
	void AgregarenPosicion(T v, int pos);
	T ObtenerPos(uint pos);
	void Mostrar();
	bool EsVacia();
	T getNom();
	void swap(T& a, T& b);
	void swap2(Nodo<T>* a, Nodo<T>* b);
	void Intercambio(int l);
	T getByCriteria(function<bool(T)> criteria) {
		Nodo<T>* aux = inicio;
		while (aux) {
			if (criteria(aux->valor))return aux->valor;
			aux = aux->siguiente;
		}
	}

	
};
template<class T>
uint Lista<T>::longi() {
	return longitud;
}
template<class T>
T Lista<T>::ObtenerPos(uint pos) {
	if (pos >= 0 && pos < longitud) {
		Nodo<T>* aux = inicio;
		for (int i = 0; i < pos; i++) {
			aux = aux->siguiente;
		}
		return aux->valor;
	}
	else {
		return nullptr;
	}
}

template<class T>
void Lista<T>::AgregarInicio(T v)
{
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);
	if (inicio == NULL) {
		inicio = nuevo;
		nuevo->siguiente = inicio;
		longitud++;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio)
			aux = aux->siguiente;
		nuevo->siguiente = inicio;
		aux->siguiente = nuevo;
		inicio = nuevo;
		aux = NULL;
		longitud++;
	}
	nuevo = NULL;
}

template<class T>
void Lista<T>::AgregarFinal(T v)
{
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);
	if (inicio == NULL) {
		AgregarInicio(v);
		return;
	}
	else {
		Nodo<T>* aux = inicio;
		while (aux->siguiente != inicio)
			aux = aux->siguiente;
		aux->siguiente = nuevo;
		nuevo->siguiente = inicio;
		longitud++;
	}

}

template<class T>
void Lista<T>::AgregarenPosicion(T v, int pos)
{
	Nodo<T>* nuevo;
	nuevo = new Nodo<T>(v);
	int i = 1;
	Nodo<T>* aux = inicio;
	while (i < pos) {
		aux = aux->siguiente;
		i++;
	}
	nuevo->siguiente = aux->siguiente;
	aux->siguiente = nuevo;
}

template<class T>
void Lista<T>::Mostrar()
{
	Nodo<T>* nodo = inicio;
	cout << "L-> ";
	do {
		Pedido* pto = (Pedido*)(nodo->valor);
		cout << pto->toString();
		if (nodo != NULL)
			cout << "->";
		nodo = nodo->siguiente;                                   

	} while (nodo != inicio);
	cout << "\n";
}
template<class T>
bool Lista<T>::EsVacia() {
	return (inicio ==NULL);
}


template<class T>
T Lista<T>::getNom() {
	T dato = inicio->valor;
	return dato;
}

template<class T>
inline void Lista<T>::swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}
template<class T>
inline void Lista<T>::swap2(Nodo<T>* a, Nodo<T>* b)
{
	Nodo<T>* c = a;
	a = b;
	b = c;
}

template<class T>
inline void Lista<T>::Intercambio(int l)
{
	Nodo<T>* ini = inicio;
	Nodo<T>* aux = inicio;
	int i = 0;
	while (i < l) {
		aux = aux->siguiente;
		i++;
	}
	swap2(ini,aux);

}
