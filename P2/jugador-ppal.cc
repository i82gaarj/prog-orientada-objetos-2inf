#include "jugador.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;
int main(){

    string dni, codigo;

    cout << "Introduce DNI del jugador: ";
    cin >> dni;
    cout << "Introduce código del jugador: ";
    cin >> codigo;

    Jugador j(dni, codigo);
    j.setApuestas();
    list <Apuesta> apuestas = j.getApuestas();

    cout << "Apuestas del jugador con DNI " << j.getDNI() << endl;
    for(list <Apuesta>::iterator it = apuestas.begin(); it != apuestas.end(); it++){
        cout << it -> tipo << " - " << it -> valor << " - " << it -> cantidad << endl;
    }

}