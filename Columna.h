#pragma once
#include <string>
#include <vector>
#include "Fila.h"
using namespace std;

class Columna {
protected:
	bool defined = 0;
	string nombreColumna;
	string tipoColumna="undefined";
	
	vector<bool>*dBool = nullptr;
	vector<string>*dString = nullptr;
	vector<double>*dDouble = nullptr;
	vector<long long>*dLong = nullptr;

public:
	long long indice;
	Columna(string nombre, long long idx) : nombreColumna(nombre), indice(idx) {}
	~Columna() {}

	string getNombre() { return nombreColumna; }
	void setNombre(string nombre) { nombreColumna = nombre; }

	string getTipo() { return tipoColumna; }

	long long size() {
		if (tipoColumna == "bool") return dBool->size();
		else if (tipoColumna == "string") return dString->size();
		else if (tipoColumna == "double") return dDouble->size();
		else if (tipoColumna == "long") return dLong->size();
	}

	string checkType(string d) {
		if (d == "true" || d == "false" || d == "1" || d == "0") return "bool";
		else if (d[0] >= 65 && d[0] <= 122) return "string";
		else if (d[0] >= 48 && d[0] <= 57) {
			if ((double)stoll(d) != stod(d)) return "double";
			else if ((double)stoll(d) == stod(d)) return "long";
		}
		else return "unknown";
	}
	void agregar(string data) {
		if (defined == 0) {
			tipoColumna = checkType(data);
			if (tipoColumna == "bool") dBool = new vector<bool>;
			else if (tipoColumna == "string") dString = new vector<string>;
			else if (tipoColumna == "double") dDouble = new vector<double>;
			else if (tipoColumna == "long") dLong = new vector<long long>;
			defined = 1;
		}
		if (tipoColumna == "bool") {
			if (data == "false" || data == "0") dBool->push_back(false);
			else if (data == "true" || data == "1") dBool->push_back(true);
		}
		else if (tipoColumna == "string") dString->push_back(data);
		else if (tipoColumna == "double") dDouble->push_back(stod(data));
		else if (tipoColumna == "long") dLong->push_back(stoll(data));
	}
	string getData(long long index) {
		if (tipoColumna == "bool") return to_string(dBool->at(index));
		else if (tipoColumna == "string") return dString->at(index);
		else if (tipoColumna == "double") return to_string(dDouble->at(index));
		else if (tipoColumna == "long") return to_string(dLong->at(index));
		else return "string";
	}
};