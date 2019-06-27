#include <iostream>
#include <conio.h>
#include "Driver.h"
using namespace std;
void e() {
	cout << endl;
}
void main() {
	Driver d1;
	d1.addFile("exampletsv.tsv");
	d1.getDF(0)->printD(), e();
	Dataframe* df2 = new Dataframe(d1.getDF(0));
	d1.vDF.push_back(df2);
	d1.getDF(1)->printD(), e();
	d1.vDF.push_back(d1.filter(0, "Nombres", "mayor", "G", "Apellidos", "contenido", "v"));
	d1.getDF(2)->printD(), e();
	vector<string>nCols;
	nCols.push_back("Edad");
	nCols.push_back("Vivo");
	d1.vDF.push_back(d1.select(0,nCols));
	d1.getDF(3)->printD(), e();
	d1.exportFile(d1.getDF(2), "Edad_Vivo.tsv");
	d1.vDF.push_back(d1.mergesort(0, "Apellidos"));
	d1.getDF(4)->printD(), e();
	d1.vDF.push_back(d1.mergesort(0, "Edad"));
	d1.getDF(5)->printD(), e();
	_getch();
}