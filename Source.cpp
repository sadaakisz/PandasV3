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
	d1.getDF(idxDF)->printD(), e();
}
void mostrar() {
	cout << "Introduzca el indice del dataframe a mostrar: ";
	e(), d1.printvDF(), e(), e();
	cin >> idxDF;
	d1.getDF(idxDF-1)->printD(), e();
}
void indexar() {
	string nombreColumna;
	cout << "Introduzca el indice del dataframe a indexar: ";
	e(), d1.printvDF(), e();
	cin >> idxDF, e();
	cout << "Introduzca el nombre de la columna del dataframe a indexar: ", e(), e();
	cin >> nombreColumna, e();
	d1.index(idxDF-1, nombreColumna);
	cout << "Indexado exitoso! La altura del arbol generado es: ";
	cout<< d1.vDF[idxDF - 1]->getMapTree()[nombreColumna]->Height(), e(), e();
}
void ordenar() {
	string nombreColumna;
	cout << "Introduzca el indice del dataframe a ordenar: ";
	e(), d1.printvDF(), e();
	cin >> idxDF, e();
	cout << "Introduzca el nombre de la columna del dataframe a ordenar: ", e(), e();
	cin >> nombreColumna, e();
	d1.vDF.push_back(d1.mergesort(idxDF - 1, nombreColumna)), idxDF++;
	cout << "Ordenamiento exitoso! Imprimiendo el nuevo dataframe generado: ";
	d1.vDF[idxDF-1]->printD(), e(), e();
}
void seleccionar() {
	vector<string>nCols;
	string col;
	cout << "Introduzca el indice del dataframe a indexar: ";
	e(), d1.printvDF(), e();
	cin >> idxDF, e();
	int numero;
	cin >> numero;
	for (int i = 0; i < numero; i++) {
		e(), cout << "Nombre de la columna 1: ";
		cin >> col;
		nCols.push_back(col);
	}
	//d1.vDF.push_back(d1.select(idxDF - 1, nCols)), idxDF++;
}
void opciones() {
	cout << "\tOpciones:", e(), e();
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
	string opcion;
	while (opcion != "8") {
		opciones();
		do {
			cin >> opcion;
		} while (opcion[0] < 48 || opcion[0] > 57);
		Console::Clear();
		switch (opcion[0])
		{
		case '1':
			importF();
			break;
		case '2':
			mostrar();
			break;
		case '3':
			indexar();
			break;
		case '4':
			ordenar();
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		default:
			break;
		}
	}
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