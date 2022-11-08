#include <functional>
#include "Nodo.h"
#include "Restaurante.h"


template<class T>
class DLL {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	DLL() { inicio = NULL, fin = NULL; }
	~DLL();
	void insertarInicio(T v);
	void insertarFinal(T v);
	void mostrar();
	void BubbleSort(std::function<bool(T, T)>compare);
	void swap(T& a, T& b);
	
};

//------------------------------------------------------------------------------
template<class T>
DLL<T>::~DLL() {
	Nodo<T>* temp;
	while (inicio != NULL) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = NULL;
	}
	delete inicio;
	inicio = NULL;
}

//------------------------------------------------------------------------------
template<class T>
void DLL<T>::insertarInicio(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);

	if (inicio == NULL)
		this->inicio = this->fin = nodo;
	else {
		nodo->siguiente = inicio;
		inicio->anterior = nodo;
		/*inicio->anterior = nodo;
		nodo->siguiente = inicio;*/
	}
	inicio = nodo;
	//delete nodo;
	nodo = NULL;
}

//------------------------------------------------------------------------------
template<class T>
void DLL<T>::insertarFinal(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);

	if (inicio == NULL) {
		inicio = fin = nodo;
	}
	else {
		fin->siguiente = nodo;
		nodo->anterior = fin;

	}
	fin = nodo;


}

//------------------------------------------------------------------------------
template<class T>
void DLL<T>::mostrar() {
	Nodo<T>* nodo = inicio;
	do {
		Restaurante* pto = (Restaurante*)(nodo->valor);
		cout << pto->toString();
		if (nodo != NULL)
			cout << endl;
		nodo = nodo->siguiente;
	} while (nodo != NULL);
	cout << endl;
}

template<class T>
inline void DLL<T>::BubbleSort(function<bool(T, T)> compare)
{
	Nodo<T>* aux = inicio;
	if (aux == nullptr) throw "No se puede ordernar listas vacias";
	while (aux != fin) {
		if (compare(aux->valor, aux->siguiente->valor)) {
			swap(aux->valor, aux->siguiente->valor);
			if (aux != inicio)
				aux = aux->anterior;
			continue;
		}
		aux = aux->siguiente;
	}
}


template<class T>
inline void DLL<T>::swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

//------------------------------------------------------------------------------





