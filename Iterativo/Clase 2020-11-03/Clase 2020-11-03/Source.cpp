/*
Dado un vector v, alteralo de tal forma que en la 
primera parte estén todos los elementos menores o iguales
que lo que hay en la primera posición, y en la segunda parte
esten los elementos mayores que en esa posición.

P.E.:  [28, 11, 100, 3, 78] = [28, 3, 1, || 100, 78]

v[0] será 28
*/
#include <iostream>
#include <vector>

using namespace std;

/*
{Pre: 0 <= n <= longitud(v) ^ P = v[0]}
*/

// Cota: n - a + b
// Complejidad: O(n)

vector<int> function(vector<int> v, int n, int k) {
	//Llevaremos dos indices, uno a la derecha del todo y otro a la izquierda
	int a = 0, b = n - 1;
	int p = v[0];

	while (b > a) {
		if (v[a] <= p) {
			++a;
		}
		else if (v[b] > p) {
			--b;
		}
		else {
			swap(v[a], v[b]);
			++a;
			--b;
		}
	}
	return v;
}

/*
{Post: Ex. k : 0 <= k <= n : 
							p.t. i : 0 <= i <= k : v[i] <= p ^
							p.t. j : k < j < n : v[i] > P
}
*/



void resuelveCaso() {
	int n, k,aux;
	vector<int> v;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		v.push_back(aux);
	}

	v = function(v, n, k);
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;	
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) resuelveCaso();
}