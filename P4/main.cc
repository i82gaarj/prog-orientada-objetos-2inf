#include "ruleta.h"
#include "crupier.h"
#include <iostream>
#include <list>

using namespace std;

void mostrar_menu(){
    cout << "Selecciona una opcion" << endl
         << "1. Cargar jugadores desde jugadores.txt" << endl
         << "2. Guardar jugadores en jugadores.txt" << endl
         << "3. Ver el estado de la ruleta, dinero de la banca y el de los jugadores" << endl
         << "4. Girar ruleta" << endl
         << "5. Eliminar a un jugador" << endl
         << "6. Añadir a un jugador" << endl
         << "7. Salir" << endl;
}

int main(){
    Crupier c("1234A", "3A5R");
    Ruleta r(c);

    int opcion;

    do{
        mostrar_menu();
        cin >> opcion;
        switch (opcion){
            case 1:{
                r.leeJugadores();
            }break;

            case 2:{
                r.escribeJugadores();
            }break;

            case 3:{
                int njugadores, gananciasBanca, sumaDinero, nvecesbola;
                r.getEstadoRuleta(njugadores, sumaDinero, nvecesbola, gananciasBanca);
                cout << "Banca: " << r.getBanca() << endl
                     << "Numero de jugadores: " << njugadores << endl
                     << "Numero de veces que se ha lanzado la bola: " << nvecesbola << endl
                     << "Ganancias banca: " << gananciasBanca << endl;
                list <Jugador> jugadores = r.getJugadores();
                for (list <Jugador>::iterator it = jugadores.begin(); it != jugadores.end(); it++){
                    cout << it -> getDNI() << " tiene "
                         << it -> getDinero() << " euros" << endl;
                }
            }break;

            case 4:{
                r.giraRuleta();
                r.getPremios();
                cout << "Ha salido el " << r.getBola() << endl
                     << "Ganancias banca:" << r.getGananciasBanca() << endl;
            }break;

            case 5:{
                string dni;
                cout << "Introduce el DNI del jugador que desea eliminar: ";
                cin >> dni;
                r.deleteJugador(dni);
            }break;

            case 6:{
                string dni, codigo;
                cout << "Introduce DNI: " << endl;
                cin >> dni;
                cout << "Introduce codigo: " << endl;
                cin >> codigo;
                Jugador j(dni, codigo);
                r.addJugador(j);
            }break;

            default:{
                cout << "Opcion no valida\n";
            }break;
        }
    }while(opcion != 7);
}