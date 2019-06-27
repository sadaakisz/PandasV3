#pragma once
#include "Fila.h"

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
