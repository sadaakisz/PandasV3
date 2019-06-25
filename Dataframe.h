#pragma once
#include <iostream>
#include "Fila.h"
class Dataframe {
private:
	vector<Columna*>vCols;
	vector<Fila*>vFils;
	string id;
public:
	long long numCol = 0;
	long long counterCol = 0;
	long long counterFil = 0;

	Dataframe(string i): id(i) {}
	Dataframe(colmap* cm) {
		numCol = cm->size();
		counterCol = cm->begin()->second->size();
		for (auto it = cm->begin(); it != cm->end(); ++it) {
			addCol((*it).second);
		}
		for (long long i = 0; i < counterCol; i++) {
			Fila* auxF = new Fila(i);
			for (long long j = 0; j < numCol;j++) {
				auxF->addCol(this->atC(j));
			}
			this->addFil(auxF);
		}
	}
	~Dataframe() {}

	void addCol(Columna* c) {
		vCols.push_back(c);
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
