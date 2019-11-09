#include "dados.cc"
#include <iostream>

void mostrar_menu(){
	std::cout << "DADOS\n\n";
	std::cout << "1. Lanzar dados\n";
	std::cout << "2. Mostrar dado 1\n";
	std::cout << "3. Mostrar dado 2\n";
	std::cout << "4. Establecer un valor determinado para el dado 1\n";
	std::cout << "5. Establecer un valor determinado para el dado 2\n";
	std::cout << "6. Obtener la suma de los dos dados\n";
	std::cout << "7. Obtener la diferencia entre el mayor y el menor valor\n";
	std::cout << "8. Salir\n";

}



int main(){
	Dados d;

	int opcion;

	while (opcion != 8){

		mostrar_menu();

		std::cin >> opcion;

		if (opcion == 1){
			d.lanzamiento();
			std::cout << "Se han lanzado los dados.\n\n";
		}

		else if (opcion == 2){

			std::cout << "dado 1 = " << d.getDado1() << "\n";

		}

		else if (opcion == 3){

			std::cout << "dado 2 = " << d.getDado2() << "\n";	
			
		}

		else if (opcion == 4){
			std::cout << "Introduce un valor: ";
			int valor;
			std::cin >> valor;
			
			if (d.setDado1(valor)){
				std::cout << "Se ha establecido el valor del dado 1.\n\n";
			}
			else{
				std::cout << "No se ha establecido el valor del dado 1, se encuentra fuera del rango 1-6.\n\n";
			}
		}

		else if (opcion == 5){
			std::cout << "Introduce un valor: ";
			int valor;
			std::cin >> valor;
			
			if (d.setDado2(valor)){
				std::cout << "Se ha establecido el valor del dado 2.\n\n";
			}
			else{
				std::cout << "No se ha establecido el valor del dado 2, se encuentra fuera del rango 1-6.\n\n";
			}
		}

		else if (opcion == 6){

			std::cout << "La suma es " << d.getSuma() << "\n";

		}

		else if (opcion == 7){

			std::cout << "La diferencia es " << d.getDiferencia() << "\n";

		}

	}


}