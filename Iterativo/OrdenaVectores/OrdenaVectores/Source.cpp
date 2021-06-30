/*
Dados dos vectores, de tamaño n, ordenados, tenemos que juntarlos en otro vector de tamaño 2n de tal forma que 
los valores de ese vector queden ordenados de forma creciente
*/
#include <iostream>
#include <vector>

using namespace std;

//	{Pre: 0 <= n <= longitud(v) = longitud(k) ^
//		  ordenado(v, n) ^ ordenado(k,n) ^
//		  longitud(w) = 2*n
//	}
// Donde:
// Ordenado(v,n) : p.t. i : 0 < i < n : v[i] > v[i - 1]
//
vector<int> ordena(vector<int> v, vector<int> k, vector<int> w, int n) {
	int i = 0;					//Variable para v
	int j = 0;					//Variable para j

	while ((i < n) && (j < n)) {
		if (v[i] <= k[j]) {
			w.push_back(v[i]);
			++i;
		}
		else {
			w.push_back(k[j]);
			++j;
		}

	}
	//Hay que volcar lo que queda
	while (i < n) {
		w.push_back(v[i]);
		i++;
	}
	while (j < n) {
		w.push_back(k[j]);
		j++;
	}

	return w;
}

//	{Post: Ordenado(w, 2*n) ^ 
// p.t. i : 0 <= i < n : freq(w[i], w, 2*n) = freq(w[i], v, n) + freq(w[i], k, n)
// }
//


void resuelveCaso() {
	int n, aux;
	vector<int> v, k, w;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	for (int i = 0; i < n; i++) {
		cin >> aux;
		k.push_back(aux);
	}

	w = ordena(v, k, w, n);
	for (int i = 0; i < 2 * n; i++) {
		cout << w[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
	return 0;
}