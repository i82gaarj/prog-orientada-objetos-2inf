#ifndef DADOS_H
#define DADOS_H
#include <vector>
#include <cstdlib>
#define VECTOR_SIZE 5

// Clase Dados. Gestiona el lanzamiento de dos dados
class Dados{
private:

	int d1_, d2_, lanzamientos1_, lanzamientos2_, sumatotal1_, sumatotal2_;

	std::vector <int> v1_, v2_;

	// pushDado1_: envía el valor del lanzamiento del dado 1 al vector y desplaza los siguientes
	void pushDado1_();
	// pushDado2_: envía el valor del lanzamiento del dado 2 al vector y desplaza los siguientes
	void pushDado2_();

public:
	// Constructor: inicializa las variables y el generador de numeros aleatorios
	Dados();

	// lanzamiento: Genera dos numeros aleatorios para los dos dados
	void lanzamiento();

	// getDado1: devuelve el valor del dado 1
	inline int getDado1() const{
		return d1_;
	}

	// getDado2: devuelve el valor del dado 2
	inline int getDado2() const{
		return d2_;
	}

	// setDado1: comprueba que el valor está entre 1 y 6
	// Si no está en ese rango, devuelve false
	// Si está en el rango, lo asigna al dado 1 y devuelve true
	bool setDado1(int valor);

	// setDado2: comprueba que el valor está entre 1 y 6
	// Si no está en ese rango, devuelve false
	// Si está en el rango, lo asigna al dado 2 y devuelve true
	bool setDado2(int valor);

	// getSuma: devuelve la suma de los dos dados
	inline int getSuma() const{
		return d1_ + d2_;
	}

	// getDiferencia: devuelve la diferencia entre el mayor y el menor valor
	int getDiferencia() const{
		return abs(d2_ - d1_); // valor absoluto ya que no nos interesan números negativos
	}


	// getLanzamientos1: devuelve el número de veces que se ha lanzado el dado 1
	inline int getLanzamientos1() const{
		return lanzamientos1_;
	}
	// getLanzamientos2: devuelve el número de veces que se ha lanzado el dado 2
	inline int getLanzamientos2() const{
		return lanzamientos2_;
	}

	// getMedia1: devuelve la media de los valores que han salido en el dado 1
	float getMedia1() const;
	// getMedia2: devuelve la media de los valores que han salido en el dado 2
	float getMedia2() const;

	// getUltimos1: devuelve los ultimos valores que se han obtenido en el lanzamiento del dado 1
	void getUltimos1(int v1[]) const;
	// getUltimos2: devuelve los ultimos valores que se han obtenido en el lanzamiento del dado 2
	void getUltimos2(int v2[]) const;

};


#endif