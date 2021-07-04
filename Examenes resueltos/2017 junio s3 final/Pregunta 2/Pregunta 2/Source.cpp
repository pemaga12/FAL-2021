#include <iostream>
#include <vector>

using namespace std;

void imprimeSolucion(vector<int> v, int n) {
	for (int i = 0; i < n; ++i) {

	}
}

void generaNumeros(
					//Datos del problema
					int n, int ini, int fin,
					//Solucion parcial
					int solParcial,
					int k,
					int ultimoNumero,
					//Marcaje
					vector<int> numerosUsados) {
	//Caso base
	if (k == n) {
		//imprimeSolucion(solParcial, n);
		cout << solParcial << endl;
	}

	//Caso recursivo
	int contadorMarcaje = ultimoNumero - ini;
	for (int i = ultimoNumero; i < fin + 1; ++i) {
		//Marcamos el numero para comprobar si lo podemos usar
		++numerosUsados[contadorMarcaje];
		if (numerosUsados[contadorMarcaje] <= i) {
			//Generamos el numero nuevo en la solución parcial
			solParcial *= 10;
			solParcial += i;					
			generaNumeros(n, ini, fin, solParcial, k + 1, i ,numerosUsados);
			//Deshacemos los cambios restauramos la solucion parcial
			solParcial -= i;
			solParcial /= 10;
		}
		--numerosUsados[contadorMarcaje];
		++contadorMarcaje;						//Incrementamos el contador para acceder al vector de marcaje
	}


}

bool resuelveCaso() {
	int n, ini, fin;
	cin >> n;
	if (!cin)return false;

	cin >> ini >> fin;
	int numerosPosibles = fin - ini + 1;						//Cantidad de numeros posibles que se pueden usar
	vector<int> valoresUsados(numerosPosibles, 0);				//Vector usado para saber cuantos numeros he usado
	int solParcial = 0;

	generaNumeros(n, ini, fin, solParcial, 0, ini ,valoresUsados);
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}