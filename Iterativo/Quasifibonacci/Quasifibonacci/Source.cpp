/*

Un vector es cuasifibonacci si 
o v[i] = v[i - 1] o bien v[i] = v[i - 1] + v[i - 2] 

p.e. el vector {1,1,1,1,1,1} es de cuasifibonacci

Y que la suma de los elementos no sume cierto k
*/
#include <iostream>
#include <vector>

using namespace std;

bool cuasifibonacci(vector<int> v, int n, int k) {
	int i = 2;
	//Caso base
	if (v[0] != v[1] && (v[0] + v[i] > k)) return false;
	int sumaParcial = v[0] + v[1];
	
	while ((i < n) && ((v[i] == v[i - 1]) || (v[i] == v[i - 1] + v[i - 2])) 
		&& (sumaParcial < k)) {
		sumaParcial += v[i];
		++i;
	}
	
	return (i == n);
}

void resuelveCaso() {
	vector<int> v; 
	int tam, aux, k;

	cin >> tam;
	cin >> k;
	for (int i = 0; i < tam; i++) {
		cin >> aux;
		v.push_back(aux);
	}
	cout << cuasifibonacci(v, tam, k) << endl;
}

int main() {
	int nCasos;
	cin >> nCasos;
	for (int i = 0; i < nCasos; i++) {
		resuelveCaso();
	}
}