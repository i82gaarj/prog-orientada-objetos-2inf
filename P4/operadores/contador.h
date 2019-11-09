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

	bool undo(int n = 1);

	inline int get() const{
		return valor_;
	}

	inline void setValor(int valor){
		valor_ = valor;
	}

	inline int getMin() const{
		return min_;
	}

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