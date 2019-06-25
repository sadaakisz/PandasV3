#pragma once
#include <sstream>
#include <fstream>
#include "Dataframe.h"
class Driver {
public:
	vector<Dataframe*>vDF;
public:
	Driver() {}
	~Driver() {}
	Dataframe* getDF(long long idx) {
		return vDF.at(idx);
	}
	int addFile(string filename) {
		Dataframe* auxD = new Dataframe(filename);
		ifstream f(filename);
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir\n";
			return 0;
		}
		while (getline(f,line,'\n')) {
			stringstream ss(line);
			if (auxD->numCol == 0) {
				while (getline(ss, num, ',')) {
					Columna* auxCo = new Columna(num.c_str(), auxD->numCol);
					auxD->addCol(auxCo);
					auxD->numCol++;
				}
			}
			else {
				Fila* auxF = new Fila(auxD->counterFil);
				while (getline(ss, num, ',')) {
					auxD->atC(auxD->counterCol)->agregar(num.c_str());
					auxF->addCol(auxD->atC(auxD->counterCol));
					auxD->counterCol++;
				}
				auxD->addFil(auxF);
				auxD->counterFil++;
			}
			auxD->counterCol = 0;
		}
		vDF.push_back(auxD);
		f.close();
	}
	Dataframe* filter(long long idx, string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {
		colmap* nCols = new colmap();
		for (long long i = 0; i < vDF.at(idx)->counterFil; i++) {
			nCols = this->getDF(idx)->atF(i)->getColmap();
		}
		vector<Fila*>nFils;
		Dataframe* nDF = new Dataframe(nCols);
	}
};