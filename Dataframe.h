#pragma once
#include <iostream>
#include "Fila.h"
class Dataframe {
private:
	vector<Columna*>vCols;
	
public:
	string id;
	vector<Fila*>vFils; //se paso a public para merge, revisar
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
		//numCol++;
	}
	void addFil(Fila* f) {
		vFils.push_back(f);
		//counterFil++;
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

	long long filasSize() { return vFils.size(); }
	long long colSize() { return vCols.size(); }
};
