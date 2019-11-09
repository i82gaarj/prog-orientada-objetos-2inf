
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	

	int a = -1;

	srand(time(NULL));

	int b = (rand() % 10) + 1;

	cout << "Introduce un numero";

	while(a != b){

		cin >> a;

	}
	cout << "Número correcto\n";
	return 0;
}