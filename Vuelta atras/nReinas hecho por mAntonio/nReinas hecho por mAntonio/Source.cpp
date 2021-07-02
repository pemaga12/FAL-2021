/*
Dado un tablero de nxn se pide averiguar de que forma se pueden colocar n reinas
(Version poco optima, ya que se recorre la solución con cada vuelta, pero funciona)
*/

#include<iostream>
#include<vector>

using namespace std;

bool seComen(vector<int> v, int k) {
	for (int i = 0; i < k - 1; ++i) {
		//Ataca v[k - 1] a v[i]?
		if (abs(k - 1 - i) == abs(v[k - 1] - v[i])) return true;
	}
	return false;
}

int cuentaPosiciones(
					//Datos de problema
					int n, 
					//Solución parcial
					vector<int> v, int k
					//Marcaje
					vector<bool> cogido
					) {

	//En caso de que la solución sea la correcta
	if (n == k) return 1;
	
	
	int ret = 0;
	for (int i = 0; i < n; i++) {
		//Modifico la solución parcial
		v[k] = i;
		//Compruebo si cumple la condición
		if (!cogido[i], !seComen(v, k + 1)) {
			cogido[i] = true;
			ret += cuentaPosiciones(n, v, k + 1, cogido);
			cogido[i] = false;
		}
		//No hace falta deshacer cambios porque no he modificado v[i]
	}
	return ret;
}

bool resuelveCaso() {
	int n, pos = 0;
	cin >> n;
	vector<int> v(n);
	vector<bool> cogidas(n, false);
	if (!cin) return false;
	cout << cuentaPosiciones(n, v, pos, cogidas) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
