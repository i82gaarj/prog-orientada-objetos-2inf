#ifndef RULETA_H
#define RULETA_H

#include <list>
#include "jugador.h"
#include "crupier.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Ruleta{
private:
	int banca_;
	int bola_;
	list <Jugador> jugadores_;
	Crupier crupier_;
	int nbolas_;
	int gananciasBanca_;

public:
	Ruleta(Crupier c):crupier_(c){
		setBanca(1000000);
		bola_ = -1;
		srand(time(NULL));
	}

	inline int getBanca() const{
		return banca_;
	}

	inline bool setBanca(int banca){
		if (banca > 0){
			banca_ = banca;
			return true;
		}
		else{
			return false;
		}
	}

	bool setBola(int bola);

	inline int getBola() const{
		return bola_;
	}

	inline const Crupier getCrupier(){
		return crupier_;
	}

	inline void setCrupier(Crupier crupier){
		crupier_ = crupier;
	}

	inline const list <Jugador> getJugadores(){
		return jugadores_;
	}

	bool addJugador(Jugador jugador);

	int deleteJugador(string dni);
	int deleteJugador(Jugador jugador);

	void escribeJugadores();
	void leeJugadores();

	inline void giraRuleta(){
		setBola(rand() % 37);
	}
	
	void getPremios();

	void getPremiosJugador(list <Jugador> :: iterator player, int &gananciasBanca);

	int getSumaDinero(){
		int sumaDineroJugadores = 0;
		for (list <Jugador>::iterator it = jugadores_.begin(); it != jugadores_.end(); it++){
			sumaDineroJugadores += it -> getDinero();
		}
		return (sumaDineroJugadores + banca_);
	}

	void getEstadoRuleta(int &njugadores, int &sumaDinero, int &nvecesbola, int &gananciasBanca){
		njugadores = jugadores_.size();
		sumaDinero = getSumaDinero();
		nvecesbola = nbolas_;
		gananciasBanca = gananciasBanca_;
	}
};

#endif