#include <iostream>
#include <vector>

using namespace std;

/*
	La jugada es ver cual es el umbral probando. Por ejemplo:
	v = [400, 500, 100, 100] u = 800
	u = 100 : 100 + 100 + 100 + 100 = 400 : T
	u = 200 : 200 + 200 + 100 + 100 = 600 : T
	u = 300 : 300 + 300 + 100 + 100 = 800 : T
	u = 400 : 400 + 400 + 100 + 100 = 1000 : F
	Buscamos a partir de que u se hace false
	lower_bound() del falso

	Empezaremos por el 0, y el umbral será el sueldo más alto.
	La busqueda binaria será entre 0 y maxSueldo + 1
	[0, maxSueldo + 1)
*/

bool posible(vector<int> sueldos, int n, int presupuesto, int umbral) {
	int restante = presupuesto;
	int i = 0; 
	while ((i < n) && (restante >= 0)) {
		restante -= min(sueldos[i], umbral);
		++i;
	}
	return restante >= 0;		//Si queda o no dinero
}

int calculaUmbral(vector<int> v, int presupuesto, int n, int maxSalario) {
	//Recive los sueldos, el presupuesto y cuantos son
	int a = 0;
	int b = maxSalario + 1;
	while (a < b) {
		int m = (a + b) / 2;
		if (posible(v, n, presupuesto, m)) {
			a = m + 1;
		}
		else {
			b = m;
		}
	}
	// !posible(a) (a == b)
	return a - 1;
}

bool resuelveCaso() {
	int u, n, aux, maxSalario = 0;
	vector<int> v;
	cin >> u;
	if (!cin) return false;
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		maxSalario = max(maxSalario, aux);
		v.push_back(aux);
	}

	cout << calculaUmbral(v, u, n, maxSalario) << endl;
}

int main() {
	while (resuelveCaso());
	return 1;
}