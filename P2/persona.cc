#include "persona.h"

Persona::Persona(string dni, string nombre, string apellidos, int edad, string direccion, string localidad, string provincia, string pais){
	setDNI(dni);
	setEdad(edad);
	setNombre(nombre);
	setApellidos(apellidos);
	setDireccion(direccion);
	setLocalidad(localidad);
	setProvincia(provincia);
	setPais(pais);
}


bool Persona::setEdad(int edad){
	if (edad >= 0){
		edad_ = edad;
		return true;
	}
	else{
		return false;
	}
}


bool Persona::mayor(){
	if(edad_ >= 18){
		return true;
	}
	else{
		return false;
	}
}