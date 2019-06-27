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
		return 0;
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
	bool compare(string nc1, string op1, string val1, Fila* f) {
		if (nc1 == "") return 1;
		else if (op1 == "mayor") return mayor(f->getData(nc1), val1);
		else if (op1=="menor") return menor(f->getData(nc1), val1);
		else if (op1 == "igual") return igual(f->getData(nc1), val1);
		else if (op1 == "inicia") return inicia(f->getData(nc1), val1);
		else if (op1 == "finaliza") return finaliza(f->getData(nc1), val1);
		else if (op1 == "contenido") return contenido(f->getData(nc1), val1);
		else if (op1 == "noContenido") return noContenido(f->getData(nc1), val1);
	}
	bool mayor(string v1, string v2) {
		if (v1[0] >= 48 && v1[0] <= 57) {
			if (stod(v1) > stod(v2)) return 1;
			else return 0;
		}
		if (v1 > v2) return 1;
		return 0;
	}
	bool menor(string v1, string v2) {
		if (v1[0] >= 48 && v1[0] <= 57) {
			if (stod(v1) < stod(v2)) return 1;
			else return 0;
		}
		if (v1 < v2) return 1;
		return 0;
	}
	bool igual(string v1, string v2) {
		if (v1 == v2) return 1;
		return 0;
	}
	bool inicia(string v1, string v2) {
		for (long long i = 0; i < v2.size();i++) {
			if (v1[i] != v2[i]) return 0;
			return 1;
		}
	}
	bool finaliza(string v1, string v2) {
		if (v1[v1.size() - 1] == v2[0]) return 1;
		return 0;
	}
	bool contenido(string v1, string v2) {
		for (long long i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[0]) return 1;
		}
		return 0;
	}
	bool noContenido(string v1, string v2) {
		for (long long i = 0; i < v1.size(); i++) {
			if (v1[i] == v2[0]) return 0;
		}
		return 1;
	}

	void merge(vector<Fila*> &vec, long long ini, long long fin, string nombreColumna) {
		long long length = (fin - ini) + 1;
		vector<Fila*> aux(length);
		long long mid = (fin + ini) / 2;
		long long i = ini;
		long long j = mid + 1;
		for (long long k = 0; i <= mid || j <= fin; k++) {
			if (i > mid || j <= fin && vec[j]->getData(nombreColumna) < vec[i]->getData(nombreColumna)) {
				aux[k] = vec[j];
				j++;
			}
			else {
				aux[k] = vec[i];
				i++;
			}
		}
		for (long long k = 0; k < length; k++) {
			vec[ini + k] = aux[k];
		}
	}

	void sort(vector<Fila*> &vec, int i, int f, string nombreColumna) {
		if (i < f) {
			int mid = (f + i) / 2;
			sort(vec, i, mid, nombreColumna);
			sort(vec, mid + 1, f, nombreColumna);
			merge(vec, i, f, nombreColumna);
		}
	}

	void mergesort(vector<Fila*> &vec, string nombreColumna) {
		sort(vec, 0, vec.size() - 1, nombreColumna);
	}

	Dataframe* OrdenarMerge(string nombreColumna, long long idx) {
		Dataframe* nDF = new Dataframe(this->vDF[idx]);
		for (long long i = 1; i < nDF->filasSize(); i++) {
			mergesort(nDF->vFils, nombreColumna);
		}
		return nDF;
	}

	Dataframe* select(long long idx, vector<string>nCols) {
		Dataframe* nDF = new Dataframe("select_"+this->vDF[idx]->id);
		for (long long i = 0; i < this->vDF.at(idx)->colSize(); i++) {
			if (nCols[i] == this->vDF[idx]->atC(i)->getNombre()) {
				nDF->addCol(this->vDF[idx]->atC(i));
			}
		}
		vector<Fila*>nF;
		for (long long i = 0; i < this->vDF[idx]->filasSize(); i++) {
			for (long long j = 0; j < nDF->colSize(); j++) {
				nDF->addFil(this->vDF[idx]->atF(j));
			}
		}
		return nDF;
	}
};