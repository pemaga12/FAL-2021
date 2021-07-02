/*
 Genera todos los vectores que sean secuencia de cuasifibonacci, de tamaño n y que empiecen por k
 todos los elementos cumplen, que o bien, todos los elementos son iguales que el anterior con todos menos el primero, o 
 que eran igual que la suma de los dos anteriores
*/
#include <iostream>
#include <vector>

using namespace std;

bool numeroValido(vector<int> v, int pos) {
	if (pos == 2) return true;						//En caso de que haya dos elementos siempre será válido
	if (pos == 3 && (v[pos - 1] == v[pos - 2] + v[pos - 3])) return true;
	int sumaParcial = 0;
	
	for (int i = pos - 3; i < pos - 1; i++) {
		sumaParcial += v[i];
	}
	if((v[pos - 1] == v[pos - 2] && v[pos - 1] == v[pos - 3]) || (v[pos - 1] == sumaParcial)) return true;
	return false;
}

void generaSecuencias(
							//Datos del problema		
							int n,
							//Solución parcial
							vector<int> v,
							//Datos extra
							int pos) {

	//Solución
	if (pos == n) {
		for (int i = 0; i < n; i++) {
			cout << v[i];
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 10; i++) {
		v[pos] = i;
		if (numeroValido(v, pos + 1)) {
			generaSecuencias(n, v, pos + 1);
		}
	}


}


bool resuelveCaso() {
	int n, k, pos = 1;
	cin >> n;
	if (!cin) return false;
	cin >> k;
	vector<int> v(n);				//Vector usado para almacenar los valores
	v[0] = k;						//Primera posición es k
	generaSecuencias(n, v, pos);
	return true;
}

int main() {
	while (resuelveCaso());
}