#include "dados.h"
#include <ctime>
#include <iostream>
#include <vector>


Dados::Dados(){
	srand(time(NULL)); // Inicializa generador
	d1_ = 1;
	d2_ = 1;

	lanzamientos1_ = 0;
	lanzamientos2_ = 0;

	sumatotal1_ = 0;
	sumatotal2_ = 0;

	v1_.resize(VECTOR_SIZE, 0);
	v2_.resize(VECTOR_SIZE, 0);
}


void Dados::lanzamiento(){

	d1_ = (rand() % 6) + 1;
	d2_ = (rand() % 6) + 1;

	lanzamientos1_++;
	lanzamientos2_++;

	sumatotal1_ += d1_;
	sumatotal2_ += d2_;

	Dados::pushDado1_();
	Dados::pushDado2_();
	
}

bool Dados::setDado1(int valor){

	if (valor >= 1 && valor <=6){

		d1_ = valor;
		lanzamientos1_++;
		sumatotal1_ += d1_;
		Dados::pushDado1_();

		return true;

	}
	else{
		return false;
	}

}

bool Dados::setDado2(int valor){

	if (valor >= 1 && valor <=6){

		d2_ = valor;
		lanzamientos2_++;
		sumatotal2_ += d2_;
		Dados::pushDado2_();

		return true;

	}
	else{
		return false;
	}

}


float Dados::getMedia1() const{

	if(lanzamientos1_ == 0){
		return 0;
	}
	else{
		return ((float)sumatotal1_ / lanzamientos1_);
	}

}

float Dados::getMedia2() const{

	if (lanzamientos2_ == 0){
		return 0;
	}
	else{
		return ((float)sumatotal2_ / lanzamientos2_);
	}

}

void Dados::getUltimos1(int v1[]) const{

	for (int i = 0; i < VECTOR_SIZE; i++){
		v1[i] = v1_[i];
	}


}

void Dados::getUltimos2(int v2[]) const{

	for (int i = 0; i < VECTOR_SIZE; i++){
		v2[i] = v2_[i];
	}

}


void Dados::pushDado1_(){

	for (int i = VECTOR_SIZE - 1; i > 0; i--){
		v1_[i] = v1_[i - 1]; 
	}
	v1_[0] = d1_;

}

void Dados::pushDado2_(){
	
	for (int i = VECTOR_SIZE - 1; i > 0; i--){
		v2_[i] = v2_[i - 1]; 
	}
	v2_[0] = d2_;

}

