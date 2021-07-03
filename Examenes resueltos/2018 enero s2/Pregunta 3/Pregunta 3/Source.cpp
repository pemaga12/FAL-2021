/*
3
1 2
2
1 2
7 5


2 3
2 3
4 1 5
20 1 15
15 1 5


3 6
2 3 6
2 2 5 4 8 9
10 25 6 12 20 8
5 14 10 10 13 9
16 16 17 12 11 5

*/



#include <iostream>
#include <vector>

using namespace std;

void distribucionQuitanieves(
							//Datos del problema	
							int m, int n, vector<int> aMaquinas, vector<int> aCarreteras, int calidades[50][50], 
							//Marcaje
							int &mejorSolucion, vector<bool> mMaquinas, vector<bool>mCarreteras, int maquinaActual, int solParcial, int mejorPosibilidad) {
	//Caso base
	if (maquinaActual == m) {
		if (solParcial > mejorSolucion) mejorSolucion = solParcial;
		return;
	}
	//Caso recursivo
	for (int i = 0; i < n; i++) {	//Por cada carretera vamos a comprobar si sirve la maquina
		if (!mCarreteras[i] && aMaquinas[maquinaActual] <= aCarreteras[i]) {
			mCarreteras[i] = true;
			mMaquinas[maquinaActual] = true;
			if(solParcial + mejorPosibilidad + calidades[maquinaActual][i] > mejorSolucion)		//Aqui hacemos la poda, aunque no logro entender por que le tengo que sumar la calidad, cuando deberia restarla
				distribucionQuitanieves(m, n, aMaquinas, aCarreteras, calidades, mejorSolucion, mMaquinas, mCarreteras, maquinaActual + 1, solParcial + calidades[maquinaActual][i], mejorPosibilidad - calidades[maquinaActual][i]);
		}
		mCarreteras[i] = false;
		mMaquinas[maquinaActual] = false;
	}
}

void resuelveCaso() {
	int m, n, aux, mejorCalidad = 0;
	cin >> m >> n;
	vector<int> aMaquinas;
	vector<int> aCarreteras;
	for (int i = 0; i < m; ++i) {
		cin >> aux;
		aMaquinas.push_back(aux);
	}
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		aCarreteras.push_back(aux);
	}
	int calidades[50][50];

	int mejorSolucion = 0;
	int mejorSolucionFila = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> aux;
			mejorSolucionFila = max(mejorSolucionFila, aux);
			calidades[i][j] = aux;
		}
		mejorSolucion += mejorSolucionFila;
	}
	vector<bool> maquinas(m, false);				//Indica si las máquinas han sido seleccionadas
	vector<bool> carreteras(n, false);				//Indica si las carreteras han sido seleccionadas
	int maquinaActual = 0;
	int solParcial = 0;
	distribucionQuitanieves(m, n, aMaquinas, aCarreteras, calidades, mejorCalidad, maquinas, carreteras, maquinaActual, solParcial, mejorSolucion);
	cout << mejorCalidad << endl;
}

int main() {
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}