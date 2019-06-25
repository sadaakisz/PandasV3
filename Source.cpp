#include <iostream>
#include <conio.h>
#include "Driver2.h"
using namespace std;
void e() {
	cout << endl;
}
void main() {
	/*Columna* c1 = new Columna("Nombres", 0);
	c1->defineColumna("Hector");
	c1->agregar("Hector");
	c1->agregar("Juan");
	c1->agregar("Carlos");
	Columna* c2 = new Columna("Telefono", 1);
	c2->defineColumna("998562311");
	c2->agregar("998562311");
	c2->agregar("997543245");
	c2->agregar("946336751");
	Fila* f1 = new Fila(0);
	Fila* f2 = new Fila(1);
	Fila* f3 = new Fila(2);
	f1->addCol(c1);
	f1->addCol(c2);
	f2->addCol(c1);
	f2->addCol(c2);
	f3->addCol(c1);
	f3->addCol(c2);
	cout << f1->getData("Nombres"), e();
	cout << f1->getData("Telefono"), e();
	cout << f2->getData("Nombres"), e();
	cout << f2->getData("Telefono"), e();
	cout << f3->getData("Nombres"), e();
	cout << f3->getData("Telefono"), e();*/
	/*
	Dataframe* d1 = new Dataframe("Dataframe1");
	Columna* c1 = new Columna("Nombres", 0);
	Columna* c2 = new Columna("Apellidos", 1);
	Columna* c3 = new Columna("Edad", 2);
	Columna* c4 = new Columna("Altura", 3);
	Columna* c5 = new Columna("Vivo", 4);
	Fila* f1 = new Fila(0);
	c1->agregar("Hector");
	c2->agregar("Suzuki");
	c3->agregar("18");
	c4->agregar("1.70");
	c5->agregar("true");
	f1->addCol(c1);
	f1->addCol(c2);
	f1->addCol(c3);
	f1->addCol(c4);
	f1->addCol(c5);
	Fila* f2 = new Fila(1);
	c1->agregar("Carlos");
	c2->agregar("Mazzarri");
	c3->agregar("23");
	c4->agregar("1.75");
	c5->agregar("true");
	f2->addCol(c1);
	f2->addCol(c2);
	f2->addCol(c3);
	f2->addCol(c4);
	f2->addCol(c5);
	Fila* f3 = new Fila(2);
	c1->agregar("Juan");
	c2->agregar("Leyva");
	c3->agregar("18");
	c4->agregar("1.70");
	c5->agregar("true");
	f3->addCol(c1);
	f3->addCol(c2);
	f3->addCol(c3);
	f3->addCol(c4);
	f3->addCol(c5);

	d1->addCol(c1);
	d1->addCol(c2);
	d1->addCol(c3);
	d1->addCol(c4);
	d1->addCol(c5);
	d1->addFil(f1);
	d1->addFil(f2);
	d1->addFil(f3);

	d1->printD();*/
	Driver d1;
	d1.addFile("exampledb.csv");
	d1.dataframe->printD();
	_getch();
}