#pragma once
#include <iostream>
#include "Fila.h"
#include "IndexMethods.h"
class Dataframe {
private:
	vector<Columna*>vCols;
	vector<Fila*>vFils;
	map<string, AVLTree<Fila*, string>*> mapTree;
public:
	string id;
	vector<string>nombreCols;
	long long numCol = 0;
	long long counterCol = 0;
	long long counterFil = 0;

	Dataframe(string i): id(i) {}
	Dataframe(Dataframe* df) {
		for (long long i = 0; i < df->nombreCols.size(); i++) {
			addCol(df->atF(0)->getColmap()->at(df->nombreCols[i]));
			numCol++;
		}
		id = "modded_"+df->id;
	}
	~Dataframe() {}

	void addCol(Columna* c) {
		vCols.push_back(c);
		nombreCols.push_back(c->getNombre());
	}
	void addFil(Fila* f) {
		vFils.push_back(f);
	}


	vector<Fila*>getFils() { return vFils; }
	vector<Columna*>getCols() { return vCols; }
	Columna* atC(long long idx) { return vCols.at(idx); }
	Fila* atF(long long idx) { return vFils.at(idx); }

	void printD() {
		cout << "Mostrando Dataframe "<< id << endl << endl;
		for (long long i = 0; i < vCols.size(); i++) {
			if (vCols[i]->getNombre().size() < 8) {
				cout << vCols[i]->getNombre() << "\t\t";
			}
			else if (vCols[i]->getNombre().size() >= 8) {
				for (int u = 0; u < 8; u++) {
					cout << vCols[i]->getNombre()[u];
				}
				cout << "..\t";
			}
		}
		cout << endl;
		for (long long i = 0; i < vFils.size(); i++) {
			for (long long j = 0; j < vCols.size(); j++) {
				if (vFils[i]->getData(vCols[j]->getNombre()).size() < 8) {
					cout << vFils[i]->getData(vCols[j]->getNombre()) << "\t\t";
				}
				else if (vFils[i]->getData(vCols[j]->getNombre()).size() >= 8) {
					for (int u = 0; u < 8; u++) {
						cout<<vFils[i]->getData(vCols[j]->getNombre())[u];
					}
					cout << "..\t";
				}
			}
			cout << endl;
		}
	}

	long long filasSize() { return vFils.size(); }
	long long colSize() { return vCols.size(); }

	map<string, AVLTree<Fila*, string>*> getMapTree() { return mapTree; }
	void setTree(string nombreColumna, AVLTree<Fila*, string>*auxT) { mapTree[nombreColumna] = auxT;}
};
