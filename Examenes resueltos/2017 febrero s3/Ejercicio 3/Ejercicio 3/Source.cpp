#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
No puede haber una pieza de color verde sobre otra verde
No puede haber mas piezas verdes que azules en ningun momento
Siempre empieza por el color rojo
El numero de piezas rojas tiene que ser mayor a la suma de verde mas azules


*/

void generaTorres(
					//Datos del problema
					int altura, 
					int azul,
					int rojo, 
					int verde,
					//Solucion parcial
					vector<string> solParcial,
					int k,
					//Marcaje
					vector<int> piezasUsadas,
					int sumaNoRojas,
					int posiblesRojas					//A cada vuelta, cuantas rojas se podrían llegar a colocar
					) {
	//Caso base
	if (k == altura) {
		for (int i = 0; i < altura; ++i) {
			cout << solParcial[i] << " ";
		}
		cout << endl;
		return;
	}
	//Caso recursivo
		//Por cada pieza comprobamos si es posible meterla
	for (int i = 0; i < 3; ++i) {
		//Probaremos pieza por pieza
		//1. pieza azul
		if(i == 0 && )
	}

}

bool resuelveCaso() {
	int altura, azul, rojo, verde;
	cin >> altura >> azul >> rojo >> verde;
	if (altura == 0 && azul == 0 && rojo == 0 && verde == 0) return false;

	//Vector usado para el marcaje, en el que guardaremos las piezas usadas
	vector<int> piezasUsadas(3, 0);
	//Vector para la solución parcial
	vector<string> solParcial;
	//La solución siempre empieza por rojo
	solParcial.push_back("rojo");
	++piezasUsadas[1];
	//Numero de posibles fichas rojas que se podran colocar
	int posiblesRojasRestantes = min(altura, rojo);
	posiblesRojasRestantes--;
	generaTorres(altura, azul, rojo, verde, solParcial, 1, piezasUsadas, 0 ,posiblesRojasRestantes);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}