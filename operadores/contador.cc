#include "contador.h"

Contador :: Contador operator = (const Contador &c){
	Contador aux;
	aux.valor_ = c.valor_;
	return aux;
}

Contador :: Contador operator = (){

}