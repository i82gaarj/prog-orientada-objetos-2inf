
using namespace std;

class Contador{
private:
	int valor_;
	int max_;
	int min_;

public:
	Contador(int valor = 0, int min = 0, int max = 1000):max_(max), min_(min){
		if (valor <= max && valor >= min){
			valor_ = valor;
		}
		else {
			valor_ = 0;
		}
	}

	Contador operator = (int valor);
	Contador operator = (const Contador &c);
	Contador operator ++ (const Contador &c);
	Contador operator -- (const Contador &c);
	friend Contador operator + (const Contador &c, int x);
	friend Contador operator + (int x, const Contador &c);
	Contador operator - ();
	Contador operator - ();

	bool undo(int n = 1);

	inline int get(){
		return valor_;
	}
};