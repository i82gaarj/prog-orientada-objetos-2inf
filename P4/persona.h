#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

// Clase Persona: gestiona los datos de una persona
class Persona{
private:
	int edad_;

	string dni_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;

public:
	Persona(string dni, string nombre = "", string apellidos = "", int edad = 0, string direccion = "", string localidad = "", string provincia = "", string pais = "");

	/* mayor: devuelve true si la persona es mayor de edad,
   	en caso contrario devuelve false */
	bool mayor();

	inline string getDNI() const{
		return dni_;
	}

	inline int getEdad() const{
		return edad_;
	}

	inline string getNombre(){
		return nombre_;
	}

	inline string getApellidos() const{
		return apellidos_;
	}

	inline string getApellidosyNombre() const{
		return apellidos_ + ", " + nombre_;
	}

	inline string getDireccion() const{
		return direccion_;
	}

	inline string getLocalidad() const{
		return localidad_;
	}

	inline string getProvincia(){
		return provincia_;
	}

	inline string getPais(){
		return pais_;
	}

	inline void setDNI(string dni){
		dni_ = dni;
	}

	inline void setNombre(string nombre){
		nombre_ = nombre;
	}

	bool setEdad(int edad);

	inline void setApellidos(string apellidos){
		apellidos_ = apellidos;
	}

	inline void setDireccion(string direccion){
		direccion_ = direccion;
	}

	inline void setLocalidad(string localidad){
		localidad_ = localidad;
	}

	inline void setProvincia(string provincia){
		provincia_ = provincia;
	}

	inline void setPais(string pais){
		pais_ = pais;
	}
};

#endif