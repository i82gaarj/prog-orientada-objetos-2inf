#include "persona.h"

Persona::Persona(string dni, string nombre, string apellidos, int edad, string direccion, string localidad, string provincia, string pais){
	dni_ = dni;
	edad_ = edad;
	nombre_ = nombre;
	apellidos_ = apellidos;
	direccion_ = direccion;
	localidad_ = localidad;
	provincia_ = provincia;
	pais_ = pais;
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


/* mayor: devuelve true si la persona es mayor de edad,
   en caso contrario devuelve false */
bool Persona::mayor(){
	if(edad_ >= 18){
		return true;
	}
	else{
		return false;
	}
}