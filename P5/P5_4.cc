#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	std::vector <int> v;
	v.resize(5);

	for (std::vector <int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << "Introduce valor: " << std::endl;
		std::cin >> *it;
	}

	std::cout << "Introduce opción (1 para ordenar ascendente, 2 descendente)\n";
	int opcion = 0;
	std::cin >> opcion;

	if (opcion == 1){
		std::sort(v.begin(), v.end());

		std::cout << "Vector ordenado ascendente:\n";

		for (std::vector <int>::iterator it = v.begin(); it != v.end(); it++){
			std::cout << "Valor: " << *it << std::endl;
		}
	}

	else if (opcion == 2){
		std::sort(v.begin(), v.end(), std::greater <int>());

		std::cout << "Vector ordenado descendente:\n";

		for (std::vector <int>::iterator it = v.begin(); it != v.end(); it++){
			std::cout << "Valor: " << *it << std::endl;
		}
	}
	else{
		std::cout << "Opción incorrecta\n";
	}
}