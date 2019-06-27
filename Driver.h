#pragma once
#include <sstream>
#include <fstream>
#include "FilterMethods.h"
#include "SortMethods.h"
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

		#pragma region FileHandler
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir\n";
			return 0;
		}
		#pragma endregion
		#pragma region FormatHandler
		char separator;
		if (filename[filename.size() - 3] == 'c') separator = ',';
		else if (filename[filename.size() - 3] == 't') separator = '\t';
		else { cout << "Formato no valido"; return 0; }
		#pragma endregion

		while (getline(f,line,'\n')) {
			stringstream ss(line);
			if (auxD->numCol == 0) {
				while (getline(ss, num, separator)) {
					Columna* auxCo = new Columna(num.c_str(), auxD->numCol);
					auxD->addCol(auxCo);
					auxD->numCol++;
				}
			}
			else {
				Fila* auxF = new Fila(auxD->counterFil);
				while (getline(ss, num, separator)) {
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
		return 0;
	}
	int exportFile(Dataframe* df, string filename) {
		ofstream archivo(filename, ios::out);

		#pragma region FormatHandler
		char separator;
		if (filename[filename.size() - 3] == 'c') separator = ',';
		else if (filename[filename.size() - 3] == 't') separator = '\t';
		else { cout << "Formato no valido"; return 0; }
		#pragma endregion

		for (long long i = 0; i < df->filasSize(); i++) {
			for (long long j = 0; j < df->colSize(); j++) {
				archivo << df->atF(i)->getData(df->nombreCols[j]);
				if (j != df->colSize() - 1) archivo << separator;
			}
			archivo << endl;
		}
		archivo.close();
	}

	Dataframe* filter(long long idx, string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") {
		Dataframe* nDF = new Dataframe(this->vDF[idx]);
		for (long long i = 0; i < this->vDF[idx]->counterFil; i++) {
			if (compare(nc1, op1, val1, this->vDF[idx]->atF(i)) && compare(nc2, op2, val2, this->vDF[idx]->atF(i))) {
				nDF->addFil(this->vDF[idx]->atF(i));
			}
		}
		return nDF;
	}

	Dataframe* mergesort(long long idx, string nombreColumna) {
		sort(this->vDF[idx]->getFils(), 0, this->vDF[idx]->getFils().size() - 1, nombreColumna);
		Dataframe* nDF = new Dataframe(this->vDF[idx]);
		for (long long i = 0; i < this->vDF[idx]->getFils().size(); i++) {
			nDF->addFil(this->vDF[idx]->getFils().at(i));
		}
		return nDF;
	}

	Dataframe* select(long long idx, vector<string>nCols) {
		Dataframe* nDF = new Dataframe("select_"+this->vDF[idx]->id);
		for (long long i = 0; i < nCols.size(); i++) {
			for (long long j = 0; j < this->vDF.at(idx)->colSize(); j++) {
				if (nCols[i] == this->vDF[idx]->atC(j)->getNombre()) {
					nDF->addCol(this->vDF[idx]->atC(j));
					j = this->vDF.at(idx)->colSize() - 1;
				}
			}
		}
		for (long long i = 0; i < this->vDF[idx]->filasSize(); i++) {
			Fila* auxF = new Fila(i);
			for (long long j = 0; j < nDF->colSize(); j++) {
				auxF->addCol(nDF->atC(j));
			}
			nDF->addFil(auxF);
		}
		return nDF;
	}

	void index(long long idx, string nombreColumna) {
		AVLTree<Fila*, string>*t = new AVLTree<Fila*, string>([=](Fila*f) { return f->getData(nombreColumna); });
		for (auto row : this->vDF[idx]->getFils()) {
			t->Add(row);
		}
		this->vDF[idx]->setTree(nombreColumna, t);
	}
};