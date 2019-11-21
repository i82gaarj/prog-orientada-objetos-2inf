#include <iostream>
#include <vector>
#include <algorithm>
#include "jugador.h"
#include "persona.h"

using namespace std;

bool sort_dni_asc(const Jugador j1, const Jugador j2){
	return j1.getDNI() < j2.getDNI();
}

bool sort_dni_desc(const Jugador j1, const Jugador j2){
	return j1.getDNI() > j2.getDNI();
}

int main(){
	vector <Jugador> v;

	int n;
	cout << "Introduce tamaño vector de jugadores:" << endl;
	cin >> n;

	for (int i = 0; i < n; i++){
		cout << "JUGADOR " << i + 1 << endl;
		cout << "Introduce DNI: " << endl;
		string dni;
		cin >> dni;

		cout << "Introduce codigo (parámetro obligatorio): " << endl;
		string codigo;
		cin >> codigo;

		Jugador j(dni, codigo);
		v.push_back(j);
	}

	cout << "Introduce opción (1 para ordenar ascendente, 2 descendente)\n";
	int opcion = 0;
	cin >> opcion;

	if (opcion == 1){
		sort(v.begin(), v.end(), sort_dni_asc);

		cout << "Vector ordenado ascendente:\n";
	}

	else if (opcion == 2){
		sort(v.begin(), v.end(), sort_dni_desc);

		cout << "Vector ordenado descendente:\n";
	}
	else{
		cout << "Opción incorrecta\n";
	}

	for (vector <Jugador>::iterator it = v.begin(); it != v.end(); it++){
		cout << "DNI "
			 << it -> getDNI()
			 << " - Codigo "
			 << it -> getCodigo()
			 << endl
			 << endl;
	}
}