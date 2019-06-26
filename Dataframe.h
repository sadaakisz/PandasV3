#pragma once
#include <iostream>
#include "Fila.h"
class Dataframe {
private:
	vector<Columna*>vCols;
	vector<Fila*>vFils;
	string id;
public:
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
	}
	~Dataframe() {}

	void addCol(Columna* c) {
		vCols.push_back(c);
		nombreCols.push_back(c->getNombre());
	}
	void addFil(Fila* f) {
		vFils.push_back(f);
	}
	Columna* atC(long long idx) { return vCols.at(idx); }
	Fila* atF(long long idx) { return vFils.at(idx); }

	void printD() {
		for (long long i = 0; i < vCols.size(); i++) {
			cout << vCols[i]->getNombre() << "\t";
		}
		cout << endl;
		for (long long i = 0; i < vFils.size(); i++) {
			for (long long j = 0; j < vCols.size(); j++) {
				cout << vFils[i]->getData(vCols[j]->getNombre()) << "\t";
			}
			cout << endl;
		}
	}
};
