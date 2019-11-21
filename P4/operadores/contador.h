#ifndef CONTADOR_H
#define CONTADOR_H
#include <list>

using namespace std;

class Contador{
private:
	int valor_;
	int max_;
	int min_;

	int ncambios_;
	list <int> cambios_;

public:
	Contador(int valor = 0, int min = 0, int max = 1000);

	Contador operator = (const int &i);

	Contador operator = (const Contador &c);

	Contador operator ++ (void);

	Contador operator -- (void);

	Contador operator ++ (int);

	Contador operator -- (int);

	Contador operator + (int x);
	friend Contador operator + (int x, Contador c);

	Contador operator - (int x);
	friend Contador operator - (int x, Contador c);

	// undo: deshace los "x" ultimos cambios, "x" se recibe como parámetro
	// Devuelve true si lo hizo correctamente, y devuelve false si se le pasa un valor no permitido
	bool undo(int n = 1);

	// get: devuelve el valor actual del contador
	inline int get() const{
		return valor_;
	}

	inline void setValor(int valor){
		valor_ = valor;
	}

	// getMin: devuelve el valor mínimo del contador
	inline int getMin() const{
		return min_;
	}

	// getMax: devuelve el valor máximo del contador
	inline int getMax() const{
		return max_;
	}

	inline void setMin(int min){
		min_ = min;
	}

	inline void setMax(int max){
		max_ = max;
	}
};

#endif