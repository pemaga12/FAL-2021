#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
//Lo hago como si me pasaran n
// {Pre: 0 <= n < longitud(n) ^ i : 0 <= i < n : v[i] > 0 ^ k > 0 
//  ^ p.t i : 0 <= i < n : v[i] > 0 }

int bolsa(vector<int> v, int n) {		//return ret
	int a = 0, b = 0;					//b = 0, debido a que puede haber un vector vacio
	int ret = 0;
	int sumaActual = 0;
	int tam = v.size();


	while (b < tam || (sumaActual > n)){
		if (sumaActual < n) {
			sumaActual += v[b];
			b++;
		}
		else{
			sumaActual -= v[a];
			a++;
		}
		if (sumaActual == n) {
			ret++;
		}
	}
	

	return ret;
}

// {Post: ret = # i , j: 0 <= i < j < n : suma(v, i, j) = k }
// Donde
// suma(v, a, b) = Suma a, b : a <= i <= b : v[i]


vector<int> separaNumero(int n) {
	int longitud = to_string(n).size(), aux;
	int back = longitud;
	longitud--;
	vector<int> v;
	int base = pow(10, longitud);

	for (int i = 0; i < back; i++) {
		aux = n / base % 10;
		base = base / 10;
		v.push_back(aux);
	}
	return v;
}

void resuelveCaso() {
	int n, sumaClave, digitos;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sumaClave >> digitos;
		vector<int> v = separaNumero(digitos);
		cout << bolsa(v, sumaClave) << endl;
	}
}

int main() {
	resuelveCaso();
	return 0;
}