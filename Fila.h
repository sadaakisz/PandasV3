#pragma once
#include "Columna.h"
#include <map>
typedef map<string, Columna*>colmap;
class Fila {
protected:
	long long indice;
	colmap* cols;
public:
	Fila(long long idx) : indice(idx) { cols = new colmap; }
	void addCol(Columna* c) {
		(*cols)[c->getNombre()] = c;
	}
	string getData(string name) {
		return cols->at(name)->getData(indice);
	}
	colmap* getColmap() {
		return cols;
	}
};