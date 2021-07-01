#include <iostream>
#include <string>

using namespace std;

int nSumdivisibles(int d, int k, int sumaAcumulada, int digitosActuales, int &solFinal) {
	//Caso base
	if (digitosActuales == k) {
		solFinal++;
		return 1;
	}
	//Caso recursivo
	digitosActuales++;
	for (int i = 0; i < 10; i++) {
		//Poda
		if ((sumaAcumulada + i) % digitosActuales == 0) 
			//Llamada recursiva
			nSumdivisibles(d, k, sumaAcumulada + i, digitosActuales, solFinal);
	}
}


//d: digito por el que empieza
//k: cantidad de digitos que tiene que tener
bool resuelveCaso() {
	int d, k;
	int digitosActuales = 1;
	int solFinal = 0;

	cin >> d;
	if (d == 0) return false;
	cin >> k;
	nSumdivisibles(d, k, d, digitosActuales, solFinal);
	//cout << nSumdivisibles(d, k, d, digitosActuales, solFinal) << endl;
	cout << solFinal << endl;
	return true;
}


int main() {
	while (resuelveCaso());
}