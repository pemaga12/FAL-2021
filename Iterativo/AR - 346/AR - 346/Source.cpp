#include <iostream>
#include <vector>

using namespace std;

//  {Pre: 0 < n <= longitud(v) <= 200.000 ^ ordenado(v, n)}
// Donde:
// ordenado(v, n) {i : 0 < i < n - 1 : v[i] < v[i - 1] }


// {
//	I:
//		1. Necesitamos decir cosas de todas las variables
//		Valores de a y b	
//		(0 <= a < b <= n) ^ 
//		ret = max i, j : (0 <= a <= i <= j < b) : (v[j] - v[i] < k) :  j - i + 1
//		a = min i : (0 <= i < b) ^ (v[b - 1] - v[a]) < k
//		
//		Cambiamos n por b, ya que en el invariante el maximo al que llegaremos es el final de la ventana, que es b 
// }

//		Complejidad: O(n)
//		Esto es debido a que a es menor que b, por lo que a nunca podrá llegar a infinito. En el momento en el que 
//		llega a b se incrementa b, por lo que a no crece indefinidamente. En el peor de los casos se dan n + n vueltas, o
// 		2 * n vueltas.

//		Cota:
//		2n - (a + b); El 2n es debido a que es posible que si a y b esten cerca del final se haga negativo, cosa que no puede ser

int problema(int n, int p, vector<int> v) {	/*return ret*/
	int i = 0;
	int ini = 0, fin = 1;
	int actual = 0, ret = 1;	// b - a

	while (fin < n) {
		if (v[fin] - v[ini] < p) {		//En caso de que aun no haya que mover la ventana
			actual++;
			fin++;
		}
		else {
			actual--;
			ini++;
		}
		if (actual > ret) {
			ret = actual;
		}
	}
	return ret;
}

// {Post: ret = max i, j: (0 <= i <= j < n) : (v[j] - v[i] < p) : j - i + 1}


bool resuelveCaso() {
	int nacimientos, periodo, aux;
	vector<int> v;
	cin >> nacimientos >> periodo;

	if (nacimientos == 0 && periodo == 0) {
		return false;
	}

	int i = 0;
	while (i != nacimientos) {
		cin >> aux;
		v.push_back(aux);
		i++;
	}

	cout << problema(nacimientos, periodo, v) << endl;
	return true;
}

int main() {
	while (resuelveCaso());
}