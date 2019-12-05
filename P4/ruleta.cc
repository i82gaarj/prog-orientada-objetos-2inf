#include "ruleta.h"
#include "crupier.h"
#include "jugador.h"
#include <list>
#include <fstream>
#include <cstring>

using namespace std;

bool Ruleta::setBola(int bola){
	if (bola >= 0 && bola <= 36){
		bola_ = bola;
		nbolas_++;
		return true;
	}
	else{
		return false;
	}
}

bool Ruleta::addJugador(Jugador jugador){
	for(list<Jugador>::iterator it = jugadores_.begin(); it != jugadores_.end(); it++){
		if (it -> getDNI() == jugador.getDNI()){
			return false;
		}
	}

	jugadores_.push_back(jugador);

	string nombrefichero = jugador.getDNI() + ".txt";
	fstream archivo(nombrefichero.c_str(), ios::in);

	if (archivo.is_open()){
		archivo.close();
		return true;
	}
	else{
		archivo.close();
		archivo.open(nombrefichero.c_str(), ios::out);
		archivo.close();
		return true;
	}
		
	
}

int Ruleta::deleteJugador(string dni){
	if (jugadores_.empty()){
		return -1;
	}

	for(list<Jugador>::iterator it = jugadores_.begin(); it != jugadores_.end(); it++){
		if (it -> getDNI() == dni){
			jugadores_.erase(it);
			return 1;
		}
	}
	return -2;
}

void Ruleta::escribeJugadores(){
	ofstream archivo("jugadores.txt", ios::out);
	if (!archivo){
		return;
	}

	for(list <Jugador>::iterator it = jugadores_.begin(); it != jugadores_.end(); it++){
		archivo << it -> getDNI() + ",";
		archivo << it -> getCodigo() + ",";
		archivo << it -> getNombre() + ",";
		archivo << it -> getApellidos() + ",";
		archivo << it -> getDireccion() + ",";
		archivo << it -> getLocalidad() + ",";
		archivo << it -> getProvincia() + ",";
		archivo << it -> getPais() + ",";
		archivo << it -> getDinero() << endl;
	}

	archivo.close();
}

void Ruleta::leeJugadores(){
	jugadores_.clear();

	ifstream archivo("jugadores.txt");
	if (!archivo){
		return;
	}
	char dni[8];
	char codigo[20];
	char nombre[30];
	char apellidos[60];
	char direccion[50];
	char localidad[50];
	char pais[30];
	char dinero[10];

	while(archivo.getline(dni, 8, ',')){

		archivo.getline(codigo, 20, ',');

		Jugador j(dni, codigo);

		archivo.getline(nombre, 30, ',');
		j.setNombre(nombre);

		archivo.getline(apellidos, 60, ',');
		j.setApellidos(apellidos);

		archivo.getline(direccion, 50, ',');
		j.setDireccion(direccion);

		archivo.getline(localidad, 50, ',');
		j.setLocalidad(localidad);

		archivo.getline(pais, 30, ',');
		j.setPais(pais);

		archivo.getline(dinero, 10, '\n');
		j.setDinero(atoi(dinero));

		jugadores_.push_back(j);
	}

	archivo.close();
}

int Ruleta::deleteJugador(Jugador j){
	return Ruleta::deleteJugador(j.getDNI());
}

void Ruleta::getPremios(){
	list <Jugador>::iterator it;

	int gananciasBanca = 0;

	for (it = jugadores_.begin(); it != jugadores_.end(); it++){
		getPremiosJugador(it, gananciasBanca);
	}

	escribeJugadores();
	setBanca(getBanca() + gananciasBanca);
	
	gananciasBanca_ = gananciasBanca;
}

void Ruleta::getPremiosJugador(list <Jugador> :: iterator jugador, int &gananciasBanca){
	string nombreFichero = (*jugador).getDNI() + ".txt";
	ifstream fichero(nombreFichero.c_str());
	if (!fichero){
		return;
	}

	char codigo[10], valor[10], cantidad[10];

	int premio = 0;

	while(fichero.getline(codigo, 10, ',')){
		fichero.getline(valor, 10, ',');
		fichero.getline(cantidad, 10, '\n');

		switch(atoi(codigo)){
			case 1:{
				if (atoi(valor) == getBola()){
					premio += atoi(cantidad) * 35;
					gananciasBanca -= atoi(cantidad) * 35;
				}
				else {
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
				}
			}break;
			case 2:{
				if (getBola() == 0){
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
					break;
				}
				string resultado;
				if (getBola() == (1 || 3 || 5 || 7 || 9 || 12 || 14 || 16 || 18 || 19 || 21 || 23 || 25 || 27 || 30 || 32 || 34 || 36)){
					resultado = "rojo";
				}
				else{
					resultado = "negro";
				}

				if(strcmp(resultado.c_str(), valor) == 0){
					premio += atoi(cantidad);
					gananciasBanca -= atoi(cantidad);
				}
				else{
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
				}
			}break;
			case 3:{
				if(getBola() == 0) {
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);		
					break;
				}

				string resultado;

				if((getBola() % 2) == 0){
					resultado = "par";
				}
				else {
					resultado = "impar";
				}

				if(strcmp(resultado.c_str(), valor) == 0) {
					premio += atoi(cantidad);
					gananciasBanca -= atoi(cantidad);
				}
				else {
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
				}
			}break;
			case 4:{
				if(getBola() == 0) {
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
					break;
				}


				string resultado;

				if(getBola() <= 18){
					resultado = "bajo";
				}
				else {
					resultado = "alto";
				}

				if(strcmp(resultado.c_str(), valor) == 0) {
					premio += atoi(cantidad);
					gananciasBanca -= atoi(cantidad);
				}
				else {
					premio -= atoi(cantidad);
					gananciasBanca += atoi(cantidad);
				}
			}break;
		}
	}
	(*jugador).setDinero((*jugador).getDinero() + premio);
	fichero.close();
}