#pragma once
#include <sstream>
#include <fstream>
#include "Dataframe.h"
class Driver {
public:
	Dataframe * dataframe;
	long long numCol = 0;
	long long counterCol = 0;
	long long counterFil = 0;
public:
	Driver() {
		dataframe = new Dataframe("exampledb.csv");
	}
	~Driver() {}
	int addFile(string filename) {
		ifstream f(filename);
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir\n";
			return 0;
		}
		while (f >> line) {
			stringstream ss(line);
			if (numCol == 0) {
				while (getline(ss, num, ',')) {
					Columna* auxCo = new Columna(num.c_str(), numCol);
					dataframe->addCol(auxCo);
					numCol++;
				}
			}
			else {
				Fila* auxF = new Fila(counterFil);
				while (getline(ss, num, ',')) {
					dataframe->atC(counterCol)->agregar(num.c_str());
					auxF->addCol(dataframe->atC(counterCol));
					counterCol++;
				}
				dataframe->addFil(auxF);
				counterFil++;
			}
			counterCol = 0;
		}
		f.close();
	}
};