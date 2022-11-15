﻿#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "Pedido.h"
#include "Cola.h"
#include <conio.h>
#include <fstream>
#include "Usuario.h"
#include <string>
#include "DLL.h"
#include "Restaurante.h"
#include "HashTable.h"
#include "Binarytree.h"
#include "Tarjeta.h"
#include "Lista.h"
Cola<Pedido*>* cola;
Usuario* usuario;
DLL<Restaurante*>* ress;
BinarySearchTree<Usuario*>* arbol;
HashTable<Tarjeta*>* hashing;
using namespace std;
string u;
int l = 0;

void IngresarTarjeta() {
	system("CLS");
	string nombr, titular;
	int nume, fecha, cods,sec,tarj;
	Tarjeta* tar;
	cout << "El nombre de su banco: " << endl;

	cout << "[1] = BCP [2] = Scotiabank [3] = BBVA [4] = Interbank" << endl;
	cin >> tarj;
	if (tarj == 1) nombr = "bcp";
	if (tarj == 2) nombr = "scotiabank";
	if (tarj == 3) nombr = "bbva";
	if (tarj == 4) nombr = "interba";

	
	cout << "Ingrese su numero de tarjeta: " << endl;
	cin >> nume;
	cout << "Ingrese su fecha de caducidad: " << endl;
	cin >> cods;
	cout << "Ingrese su contraseña secreta: " << endl;
	cin >> sec;

	tar = new Tarjeta(nume, cods, sec, nombr);
	hashing->insert(nombr, tar);
	/*hashing->displayy([](Tarjeta* value) -> void {
		cout << value->toString() << "|";
		
		});
	cin.get();
	cin.ignore();*/
}

void MostrarResta(int num) {
	char carac;
	ifstream menus;
	string res,com;
	Pedido* ped;
	

	switch (num)
	{
	case 'm':
		system("CLS");
		menus.open("McDonalds.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "McDonalds";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l= l+1;
		
		break;
	case'b':
		system("CLS");
		menus.open("BurgerKing.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "BurgerKing";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;
	case'l':
		system("CLS");
		menus.open("LaHamburguesa.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "La buena hamburguesa";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;
	case'k':
		system("CLS");
		menus.open("KFP.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "KFP";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;
	case'd':
		system("CLS");
		menus.open("DrSushi.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "DrSushi";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;
	case'e':
		system("CLS");
		menus.open("Bembos.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "Bembos";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;
	case'p':
		system("CLS");
		menus.open("Pizzahut.txt", ios::in);

		if (menus.is_open()) {
			carac = menus.get();
			cout << carac;
			while (!menus.eof()) {
				carac = menus.get();
				cout << carac;
			}
		}
		cout << endl;
		res = "Pizzahut";
		cout << "Ingrese el pedido que quiera hacer " << endl;
		cin >> com;
		ped = new Pedido(res, com, l);
		cola->enqueue(ped);
		l++;
		break;

	}
	
		
}
void procesaOpciones(char op) {
	usuario = arbol->getNom();
	char caracter;
	string res;
	string com;
	string usu;
	string bankey;
	int edad;
	string Direccion;
	int numero;
	char c;
	ifstream Restaurantes;
	ofstream pedidos;
	Pedido* ped;
	//Usuario* usuario;
	char *cod;
	string nom, dir;
	int lo;
	int tel, pos;
	int num,tarj;

	auto compareCriteria = [](Restaurante* a, Restaurante* b)->bool {
		return a->getNum() > b->getNum(); };
	auto compareRep = [](Restaurante* a, Restaurante* b)->bool {
		return a->getRep() > b->getRep(); };
	auto compareDem = [](Restaurante* a, Restaurante* b)->bool {
		return a->getDem() > b->getDem(); };


	switch (op) {
	case'0':

		pedidos.open("datos.txt", ios::out);
		if (pedidos.is_open()) {
			arbol->roadTree(
				[&](Usuario* value)-> void {
				pedidos << value->getNombre() << "|" << value->getDir() << "|" << value->getPed() << "\n";
				}
			);
			
		}
		pedidos.close();

		break;
	case'1':
		system("CLS");
		cout << "Direccion: "<< usuario->getDir()<<endl<<endl;
		ress->mostrar();
		Restaurantes.open("Restaurantes.txt", ios::in);

		if (Restaurantes.is_open()) {
			caracter = Restaurantes.get();
			cout << caracter;
			while (!Restaurantes.eof()) {
				caracter = Restaurantes.get();
				cout << caracter;
			}
		}
		cout << endl;
		do {

			cin >> numero;
			if (numero == 1) {
				system("CLS");
				ress->BubbleSort(compareDem);
				cout << "Direccion: " << usuario->getDir() << endl << endl;
				ress->mostrar();
				cout << "*******************************************************************************" << endl;
				cout << "[1] = Filtrar por Demora [2] = Filtrar por Reputacion [3] = Filtrar por Comida"<<endl;


			}
			else if (numero == 2) {
				system("CLS");
				ress->BubbleSort(compareRep);
				cout << "Direccion: " << usuario->getDir() << endl << endl;
				ress->mostrar();
				cout << "*******************************************************************************" << endl;
				cout << "[1] = Filtrar por Demora [2] = Filtrar por Reputacion [3] = Filtrar por Comida" << endl;
			}
			else if (numero == 3) {
				system("CLS");
				ress->BubbleSort(compareCriteria);
				cout << "Direccion: " << usuario->getDir() << endl << endl;
				ress->mostrar();
				cout << "*******************************************************************************" << endl;
				cout << "[1] = Filtrar por Demora [2] = Filtrar por Reputacion [3] = Filtrar por Comida"<<endl;
			}
			else if (numero > 3) {
				cout << "Ingrese un numero del 1 al 3 ";
	
			}
		} while (numero != 0);
		
		cout << "Ingrese el restaurante deseado" << endl << endl;
		cin >> c;
		MostrarResta(c);
		

		break;
	case'2':
		cola->mostrar();
		cin.get();
		cin.ignore();
		break;
	case'3':
		if (cola->esVacia() == true) {
			cout << "La cola esta vacia";
			cin.get();
			cin.ignore();
		}
		else {
			ped = cola->dequeue();
		/*	usuario = usuu->getNom();*/
			usuario = arbol->getNom();
			cout << "El pedido "<< " de:"<< usuario->toString()<<" que es " << ped->toString() << " ha sido terminado" << endl;
			cin.get();
			cin.ignore();
		}
			
		
		break;
	case'4':
		
		cola = new Cola<Pedido*>();
		hashing = new HashTable<Tarjeta*>(10);
		cout << "Cree su cuenta" << endl;
		cout << "Ingrese su nombre: ";
		cin >> nom;
		cout << "Ingrese su direccion: " << endl;
		cin >> dir;
		cout << "Ingrese su edad: " << endl;
		cin >> edad;
		cout << "Ingrese su numero: " << endl;
		cin >> tel;
		usuario = new Usuario(nom, dir, tel, cola,edad, hashing);
		arbol->insert(usuario);
		u = nom;
		break;
	case'5':
		
		cout << "PreOrden: ";
		arbol->preOrder();
		cout << endl;
		cout << "En Orden: ";
		arbol->enOrden();
		cout << endl;
		cout << "PosOrden: ";
		arbol->posOrden();
		cin.get();
		cin.ignore();
		
		break;
	case'6':
		IngresarTarjeta();

		break;
	case'7':
		cout << "El nombre de su banco: " << endl;

		cout << "[1] = BCP [2] = Scotiabank [3] = BBVA [4] = Interbank"<< endl;
		cin >> tarj;
		if (tarj == 1) bankey = "bcp";
		if (tarj == 2) bankey = "scotiabank";
		if (tarj == 3) bankey = "bbva";
		if (tarj == 4) bankey = "interba";
		
		hashing->displayk([](Tarjeta* value) -> void {
			cout << value->toString() << "|";

			}, bankey);
		cin.get();
		cin.ignore();
		break;
	}
	


}
void CrearUsuarioNu() {
	string nom, dir;
	Usuario* usr;
	
	int tel;
	int num;
	int edad;
	if (/*usuu->EsVacia() == true*/ arbol->EsVacia() == true) {
		
		cola = new Cola<Pedido*>();
		hashing = new HashTable<Tarjeta*>(10);
		cout << "Usted no tiene cuenta, cree su cuenta" << endl;
		cout << "Ingrese su nombre: ";
		cin >> nom;
		cout << "Ingrese su direccion: " << endl;
		cin >> dir;
		cout << "Ingrese su edad: " << endl;
		cin >> edad;
		cout << "Ingrese su numero: " << endl;
		cin >> tel;
		usr = new Usuario(nom, dir,tel,cola,edad, hashing);
		/*usuu->AgregarInicio(usr);*/
		arbol->insert(usr);
		u = nom;
	}
	else {
		return;
	}
}

void CrearUsuario() {
	string nom, dir;
	Usuario* usr;


	int tel;
	int num;
	int edad;
		cola = new Cola<Pedido*>();
		hashing = new HashTable<Tarjeta*>(10);
		cout << "Usted no tiene cuenta, cree su cuenta" << endl;
		cout << "Ingrese su nombre: ";
		cin >> nom;
		cout << "Ingrese su direccion: " << endl;
		cin >> dir;
		cout << "Ingrese su edad: " << endl;
		cin >> edad;
		cout << "Ingrese su numero: " << endl;
		cin >> tel;
		usr = new Usuario(nom, dir, tel, cola,edad,hashing);
		/*usuu->AgregarInicio(usr);*/
		arbol->insert(usr);

}

int main()
{
	ofstream pedidos;
	
	ress = new DLL<Restaurante*>();

	ress->insertarInicio(new Restaurante("McDonnalds  Hamburguesas ---  [m]", 1,4.7,14));
	ress->insertarInicio(new Restaurante("BurgerKing Hamburguesas ---  [b]", 1,4.5,22));
	ress->insertarInicio(new Restaurante("La buena hamburguesa Hamburguesas ---  [l]",1,3.7,30 ));
	ress->insertarInicio(new Restaurante("KFP PolloFrito ---  [k]", 2,4.8,20));
	ress->insertarFinal(new Restaurante("DrSushi Japones ---  [d]", 3,4.4,50));
	ress->insertarFinal(new Restaurante("Bembos Hamburguesas ---  [e]", 1,4.9,30));
	ress->insertarFinal(new Restaurante("PizzaHut Pizzas ---  [p]", 4,4.1,40));
	

	
	arbol = new BinarySearchTree<Usuario*>(
		[](Usuario* value)-> void {
			cout << value->getEdad() << "|";
		},
		[](Usuario* a, Usuario* b)-> bool {
			return a->getEdad() < b->getEdad();
		}, [&](Usuario* value)-> void {
			
			pedidos.open("datos.txt", ios::out);
			if (pedidos.is_open()) {
				
				pedidos << value->getNombre() << "|" << value->getDir() << "|" << value->getPed() << "\n";
			}
			pedidos.close();
			
		}

		);
	char op;
	
	do {
	
		CrearUsuarioNu();
		usuario = arbol->getNom();
		l++;

		system("CLS");
		cout << "************* PEDIDOS YA *****************        Saludos Usuario " << u  << endl;
		cout << "[1] - Registrar Pedido" << endl;
		cout << "[2] - Ver Pedidos" << endl;
		cout << "[3] - Finalizar Pedido" << endl;
		cout << "[4] - Crear nueva cuenta" << endl;
		cout << "[5] - Usuarios Creados" << endl;
		cout << "[6] - Añadir metodo de pago" << endl;
		cout << "[7] - Ver tarjetas añadidas" << endl;
		cout << "[0] - Salir" << endl;
		cout << "Ingrese Opcion:";
		cin >> op;
		procesaOpciones(op);
		
			

	} while (op != '0');

	cin.get();
	cin.ignore();
	return 0;
	
}

