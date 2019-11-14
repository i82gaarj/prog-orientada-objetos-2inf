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

	std::sort(v.begin(), v.end());

	std::cout << "Vector ordenado ascendente:\n";

	for (std::vector <int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << "Valor: " << *it << std::endl;
	}

	std::sort(v.begin(), v.end(), std::greater <int>());

	std::cout << "Vector ordenado descendente:\n";

	for (std::vector <int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << "Valor: " << *it << std::endl;
	}
}