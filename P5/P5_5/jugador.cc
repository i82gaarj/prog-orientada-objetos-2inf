#include "jugador.h"
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

void Jugador::setApuestas(){
	apuestas_.clear();
	string nombre_archivo = getDNI() + ".txt";

	ifstream archivo(nombre_archivo.c_str());

	if (!archivo){
		return;
	}

	char codigo[10], valor[10], cantidad[10];
	Apuesta aux;
	while(archivo.getline(codigo, 10, ',')){
		archivo.getline(valor, 10, ',');
		archivo.getline(cantidad, 10, '\n');

		aux.tipo = atoi(codigo);
		aux.valor = valor;
		aux.cantidad = atoi(cantidad);

		apuestas_.push_back(aux);
	}

	archivo.close();
}