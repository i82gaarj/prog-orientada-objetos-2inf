#include "contador.h"
#include <list>

Contador::Contador(int valor, int min, int max):max_(max), min_(min){
	ncambios_ = 0;
	if (valor <= max && valor >= min){
		valor_ = valor;
	}
	else if (max <= min){
		valor_ = 0;
		min_ = 0;
		max_ = 1000;
	}
	else {
		valor_ = 0;
	}

	ncambios_++;
	cambios_.push_back(valor_);
}

Contador Contador::operator = (const Contador &c){
	setValor(c.get());
	setMin(c.getMin());
	setMax(c.getMax());

	ncambios_++;
	cambios_.push_back(valor_);

	return *this;
}

Contador Contador::operator = (const int &i){
	if (i >= max_){
		valor_ = max_;
	}
	else if (i <= min_){
		valor_ = min_;
	}
	else{
		valor_ = i;
	}

	ncambios_++;
	cambios_.push_back(valor_);

	return *this;
}

Contador Contador::operator ++ (int){
	Contador aux = *this;

	if (valor_ >= max_){
		valor_ = max_;
	}
	else{
		valor_++;
	}

	ncambios_++;
	cambios_.push_back(valor_);

	return aux;
}

Contador Contador::operator -- (void){
	if (valor_ <= min_){
		valor_ = min_;
	}
	else{
		--valor_;
	}

	ncambios_++;
	cambios_.push_back(valor_);

	return *this;
}

Contador Contador::operator ++ (void){
	if (valor_ >= max_){
		valor_ = max_;
	}
	else{
		++valor_;
	}

	ncambios_++;
	cambios_.push_back(valor_);

	return *this;
}

Contador Contador::operator -- (int){ // postfijo
	Contador aux = *this;
	if (valor_ <= min_){
		valor_ = min_;
	}
	else{
		valor_--;
	}

	ncambios_++;
	cambios_.push_back(valor_);

	return aux;
}

Contador operator + (int x, Contador c){
	Contador aux(c);
	int nuevo_valor = x + aux.get();

	if (nuevo_valor > aux.getMax()){
		aux.setValor(aux.getMax());
	}
	else if (nuevo_valor < aux.getMin()){
		aux.setValor(aux.getMin());
	}
	else{
		aux.setValor(nuevo_valor);
	}

	aux.ncambios_++;
	aux.cambios_.push_back(aux.valor_);

	return aux;
}

Contador Contador::operator + (int x){ // c + x
	int nuevo_valor = valor_ + x;
	if ((nuevo_valor) < min_){
		valor_ = min_;
	}
	else if ((nuevo_valor) > max_){
		valor_ = max_;
	}
	else{
		valor_ = nuevo_valor;
	}
	ncambios_++;
	cambios_.push_back(valor_);
	return *this;
}

Contador Contador::operator - (int x){ // c - x
	int nuevo_valor = valor_ - x;

	if ((nuevo_valor) < min_){
		valor_ = min_;
	}
	else if ((nuevo_valor) > max_){
		valor_ = max_;
	}
	else{
		valor_ = nuevo_valor;
	}

	ncambios_++;
	cambios_.push_back(valor_);
	
	return *this;
}

Contador operator - (int x, Contador c){
	Contador aux(c);
	int nuevo_valor = x - aux.get();

	if (nuevo_valor > aux.getMax()){
		aux.setValor(aux.getMax());
	}
	else if (nuevo_valor < aux.getMin()){
		aux.setValor(aux.getMin());
	}
	else{
		aux.setValor(nuevo_valor);
	}

	aux.ncambios_++;
	aux.cambios_.push_back(aux.valor_);

	return aux;
}

bool Contador::undo(int x){
	if (x >= ncambios_ || x < 1){
		return false;
	}
	else{
		for (int i = 0; i < x; i++){
			cambios_.pop_back();
			valor_ = cambios_.back();
			ncambios_--;
		}
		return true;
	}
}
