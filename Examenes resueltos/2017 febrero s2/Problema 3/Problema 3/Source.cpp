#include <vector>
#include <iostream>

/*
DA TLE, FALTA PODA, PERO FUNCIONA
*/

using namespace std;

void dibujaSolucion(vector<int> solucionParcial) {
	for (int i = 0; i < solucionParcial.size(); ++i) {
		cout << solucionParcial[i] << " ";
	}
	cout << endl;
}

void generaSecuencias(
							//Datos del problema
							int n,
							//Solucion parcial
							vector<int> solucionParcial,
							int k,									//Posicion del vector por la que vamos
							//Marcaje
							vector<int> posiciones,					//Posiciones en las que se están almacenando los numeros
							vector<bool> colocado,					//Indica si un numero ha sido totalmente colocado, es decir, si se ha puesto dos veces o no
							//Solucion
							int &solucion							//Parametro E/S usado para guardar la solucion del problema
						) {
	//Caso base
	if (k == 2 * n) {
		++solucion;
		dibujaSolucion(solucionParcial);
		return;
	}
	//Caso recursivo
	for (int i = 0; i < n; ++i) {
		if (colocado[i] == false && (posiciones[i] == -1 || k - posiciones[i] == i + 2)) {				//En caso de que esté en una posición válida
			if (posiciones[i] == -1) posiciones[i] = k; 											//En caso de que no estuviera colocado antes
			else colocado[i] = true;																//En caso de que ya hubiera un numero colocado se marca como que está totalmente colocado
			solucionParcial[k] = i + 1;
			generaSecuencias(n, solucionParcial, k + 1, posiciones, colocado, solucion);
			//Deshago los cambios anteriores
			if (colocado[i]) colocado[i] = false;
			else posiciones[i] = -1;		
		}
	}
}

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) return false;

	int solucion = 0;
	vector<int> solucionParcial(2*n);					//Vector en el que almacenaremos la solucionParcial
	vector<int> posiciones(n, -1);						//Indica donde se coloca por primera vez un numero. Inicialmente está en -1 todos los valores, ya que no se ha colocado ninguno
	vector<bool> colocadoTotalmente(n, false);			//Indica si se ha colocado totalmente un numero. Inicialmente todos están a false
	generaSecuencias(n, solucionParcial, 0, posiciones, colocadoTotalmente, solucion);
	cout << "Solucion: " << solucion << endl;
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}