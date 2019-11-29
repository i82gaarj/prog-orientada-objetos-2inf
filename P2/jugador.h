#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <string>
#include <list>

using namespace std;

struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador: public Persona{
private:
	int dinero_;
	string codigo_;
	list <Apuesta> apuestas_;

public:
	Jugador(string dni, string codigo, string nombre = "", string apellidos = "", int edad = 0, string direccion = "", string localidad = "", string provincia = "", string pais = ""):Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
		codigo_ = codigo;
		dinero_ = 1000;
	}

	inline string getCodigo() const{
		return codigo_;
	}

	inline void setCodigo(string codigo){
		codigo_ = codigo;
	}

	inline void setDinero(int dinero){
		dinero_ = dinero;
	}

	inline int getDinero() const{
		return dinero_;
	}

	inline list <Apuesta> getApuestas() const{
		return apuestas_;
	}

	// setApuestas: borra las apuestas actuales y lee del fichero "DNI.txt" las nuevas, siendo DNI el DNI del jugador
	void setApuestas();
};

#endif