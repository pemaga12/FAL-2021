/*
Supon que ganas un concurso del media markt, y te dicen que te puedes llevar todo lo que te entre en un carro, siempre y cuando no se desborde.
La gracia est� en elegir aquello que a parte de lo que mas cerca se quede del peso m�ximo, lo que m�s valor tenga.

Que necesitamos saber?

Peso maximo
n� productos, y por cada producto el peso y el valor


Poda: Necesitamos hacer una estimaci�n optimista 

*/
#include <iostream>
#include <vector>

using namespace std;

void mochila(
						//Descripcion del problema
						vector<float> peso,
						vector<float> valor,
						float capacidad,
						int n,					//Numero de objetos
						//Solucion parcial
						vector<bool> sol,
						int k,					//Productos seleccionados
						float beneficioActual,		//beneficioActual
						float pesoActual,
						//Mejor soluci�n encontrada
						vector<bool> mejorSol,
						float &valorMejor,
						//Marcaje
						float estimacionOptimista
						) {

	//Caso base
	if (n == k) {
		if (beneficioActual > valorMejor) {
			for (int i = 0; i < n; i++) {
				mejorSol[i] = sol[i];
			}
			valorMejor = beneficioActual;		
		}
		return;
	}

	//Caso recursivo

	//Caso 1: a�adimos el objeto k + 1 a la mochila (si entra)
	if (pesoActual + peso[k] > capacidad) {
		sol[k] = true;
		mochila(peso, valor, n, capacidad, sol, k + 1, beneficioActual + valor[k], pesoActual + peso[k], mejorSol, valorMejor, estimacionOptimista - valor[k]);
	}
	//Caso 2: No a�adimos el objeto a la mochila
	if (beneficioActual + estimacionOptimista - valor[k] > valorMejor) {
		sol[k] = false;
		mochila(peso, valor, n, capacidad, sol, k + 1, beneficioActual, pesoActual, mejorSol, valorMejor, estimacionOptimista - valor[k]);
	}
}

bool resuelveCaso() {
	//.....
	int n = 3444;		//Numero de productos que hay
	vector<int> valor;
	int estimacionOptimista = 0;
	for (int i = 0; i < n; i++) {
		estimacionOptimista += valor[i];
	}
	//.....
}
int main() {
	while (resuelveCaso());
	return 0;
}

//Estimacion optimista es la suma de todos los productos desde k+1 hasta el final