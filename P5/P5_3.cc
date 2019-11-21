#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main(){
	vector <int> v;
	v.resize(5);

	for (vector <int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "Introduce valor: " << endl;
		cin >> *it;
	}

	std::sort(v.begin(), v.end());

	cout << "Vector ordenado ascendente:\n";

	for (vector <int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "Valor: " << *it << endl;
	}

	std::sort(v.begin(), v.end(), std::greater <int>());

	cout << "Vector ordenado descendente:\n";

	for (vector <int>::iterator it = v.begin(); it != v.end(); it++){
		cout << "Valor: " << *it << endl;
	}
}