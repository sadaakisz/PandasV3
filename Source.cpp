#include <iostream>
#include <locale.h>
#include <conio.h>
#include "Driver.h"
using namespace std;
using namespace System;
Driver d1;
long long idxDF = -1;
void e() {
	cout << endl;
}
void importF() {
	string filename;
	cout << "\tIngrese el nombre del archivo a importar: ";
	cin >> filename;
	while (!d1.findFile(filename)) {
		e(), cout << "\tError! Ingrese un nombre de archivo existente: ";
		cin >> filename;
	}
	e();
	d1.addFile(filename), idxDF++;
	d1.getDF(idxDF)->printD(), e();
}
void logo() {
	e(), cout << "     ________________________________________________________________________", e(), cout << "    |                                                                        |", e();
	cout << "    |   ______                    __________                                 |", e();
	cout << "    |   ___  / _____________ ________  ____/____________ _______ ________    |", e();
	cout << "    |   __  /  _  __ \\_  __ `/  _ \\_  /_   __  ___/  __ `/_  __ `__ \\  _ \\   |", e();
	cout << "    |   _  /___/ /_/ /  /_/ //  __/  __/   _  /   / /_/ /_  / / / / /  __/   |", e();
	cout << "    |   /_____/\\____/_\\__, / \\___//_/      /_/    \\__,_/ /_/ /_/ /_/\___/     |", e();
	cout << "    |                /____/                                                  |", e();
	cout << "    |________________________________________________________________________|", e(), e(), e();
}
void intro() {
	Console::SetWindowPosition(0, 0);
	Console::SetWindowSize(230, 60);
	string filename;
	//setlocale(LC_ALL, "spanish");
	logo();
	cout << "\tIngrese el nombre del archivo a importar: ";
	cin >> filename;
	while (!d1.findFile(filename)) {
		e(), cout << "\tError! Ingrese un nombre de archivo existente: ";
		cin >> filename;
	}
	e();
	d1.addFile(filename), idxDF++;
	cout << "Mostrando Dataframe 1_", e(), e();
	d1.getDF(idxDF)->printD(), e();
}
void opciones() {
	e();
	cout << "\t1. Importar archivo", e();
	cout << "\t2. Mostrar Dataframe", e();
	cout << "\t3. Indexar Dataframe", e();
	cout << "\t4. Ordenar Dataframe", e();
	cout << "\t5. Seleccionar Elementos", e();
	cout << "\t6. Filtrar datos", e();
	cout << "\t7. Exportar Dataframe", e();
	cout << "\t8. Salir del programa", e(), e();
}
void menu() {
	intro();
	opciones();
	string opcion;
	do {
		cin >> opcion;
	} while (opcion[0] < 48 || opcion[0] > 57);
	switch (opcion[0])
	{
	case '1':
		importF();
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	default:
		break;
	}
	_getch();
}
void main() {
	/*
	Driver d1;
	d1.addFile("exampletsv.tsv");
	d1.getDF(0)->printD(), e();
	Dataframe* df2 = new Dataframe(d1.getDF(0));
	d1.vDF.push_back(df2);
	d1.getDF(1)->printD(), e();
	d1.vDF.push_back(d1.filter(0, "Nombres", "mayor", "G", "Apellidos", "contenido", "v"));
	d1.getDF(2)->printD(), e();
	vector<string>nCols;
	nCols.push_back("Edad");
	nCols.push_back("Vivo");
	d1.vDF.push_back(d1.select(0,nCols));
	d1.getDF(3)->printD(), e();
	d1.exportFile(d1.getDF(2), "Edad_Vivo.tsv");
	d1.vDF.push_back(d1.mergesort(0, "Apellidos"));
	d1.getDF(4)->printD(), e();
	d1.vDF.push_back(d1.mergesort(0, "Edad"));
	d1.getDF(5)->printD(), e();
	d1.index(0, "Apellidos");
	//d1.vDF[0]->getMapTree()["Apellidos"]->getNode()->e;
	e();
	cout << d1.vDF[0]->getMapTree()["Apellidos"]->Height(), e();
	d1.index(2, "Apellidos");
	e();
	cout << d1.vDF[2]->getMapTree()["Apellidos"]->Height(), e();
	_getch();*/
	menu();
}