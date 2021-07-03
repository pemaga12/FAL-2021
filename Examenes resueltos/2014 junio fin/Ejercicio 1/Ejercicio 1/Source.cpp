#include <iostream>
#include <vector>

using namespace std;

void precioMinimo(		//Descripcion del problema
						int nProductos,
						int nTiendas,
						float precios[50][50],

						//Solucion parcial
						int k,						//En cada paso elijo en que tienda compro cada producto
						vector<int> solParcial,		//Tienda donde compramos el producto i. Tamaño = MAX_PRODUCTOS
							
						//Mejor solucion encontrada
						vector<int> mejorSolucion,	
						float &mejorCoste,
						
						//Marcaje
						float costeActual,
						vector<int> compradoPorTienda	//Cuantas cosas se han comprado en la tienda
						) {
	//Caso base
	if (k == nProductos) {
		if (mejorCoste > costeActual) {
			mejorCoste = costeActual;
			for (int i = 0; i < nProductos; ++i) {
				mejorSolucion[i] = solParcial[i];
			}
		}
		return;
	}
	//Comprar el producto k en la tienda i
	//Caso recursivo. Probamos a comprar el producto k en cada tienda
	for (int i = 0; i < nTiendas; ++i) {
		if (compradoPorTienda[i] == 3) continue;
		
		solParcial[k] = i;
		compradoPorTienda[i]++;
		
		if(costeActual < mejorCoste)
			precioMinimo(nProductos, nTiendas, precios, k + 1, solParcial, mejorSolucion, mejorCoste, costeActual + precios[k][i], compradoPorTienda);

		compradoPorTienda[i]--;
		
	}

}

void resuelveCaso() {
	int n, m, aux;
	cin >> n >> m;
	
	int precios[50][50];	//Lista de precios en los supermercados
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> precios[i][j];			//La i es el producto
		}
	}
	vector<int> compradoPorTienda(m, 0);	//Cuantos productos se han comprado por tienda

	precioMinimo(n, m, precios, )
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
}