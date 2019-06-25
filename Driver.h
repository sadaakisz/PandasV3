#pragma once
#include <sstream>
#include <fstream>
#include "Dataframe.h"
/*class Driver {
public:
	vector<Dataframe*>vDataframe;
	long long dataframeNum = 0;
public:
	Driver() {}
	~Driver() {}
	int addFile(string filename) {

		Dataframe* auxD=new Dataframe(filename);
		long long numCol = 0;
		long long numFil = 0;
		long long contCol = 0;

		ifstream f(filename);
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir\n";
			return 0;
		}
		stringstream s(line);
		while (getline(s, num, ',')) {
			Columna* auxCo = new Columna(num.c_str(), numCol);
			auxD->addCol(auxCo);
			numCol++;
		}
		while (f >> line) {
			stringstream ss(line);
			Fila* auxF = new Fila(numFil);
			while (getline(ss, num, ',')) {
				auxD->atC(contCol)->agregar(num.c_str());
				auxF->addCol(auxD->atC(contCol));
				contCol++;
			}
			contCol = 0;
		}
	}
};*/