#include <iostream>
#include <vector>

using namespace std;

void escribeVector(vector<int> v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void generaVectores(
					//Datos del problema
					int n, 
					int d, 
					int e, 
					//Solucion parcial
					vector<int> solParcial,
					int k,
					//Marcaje
					int repeticiones
					) {
	//Caso base
	if (k == n) {
		escribeVector(solParcial);
		return;
	}

	//Caso recursivo  -> Solo hay dos posibilidades. Añadir el numero repetido en caso de ser posible, o añadir el siguiente
	if (repeticiones < d) {
		solParcial[k] = solParcial[k - 1];
		generaVectores(n, d, e, solParcial, k + 1, ++repeticiones);
	}
	//En otro caso añadimos el siguiente numero
	if (solParcial[k - 1] != 9) {			//Supongo que detrás del 9 no viene el 0
		solParcial[k] = solParcial[k - 1] + 1;
		generaVectores(n, d, e, solParcial, k + 1, 1);
	}

}

bool resuelveCaso() {
	int n, d, e;
	cin >> n >> d >> e;


	if (n == 0 && d == 0 && e == 0) return false;

	vector<int> solParcial(n);
	solParcial[0] = e;
	generaVectores(n, d, e, solParcial, 1, 1);

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}