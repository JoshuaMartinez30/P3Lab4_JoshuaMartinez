#include <iostream>
#include "Game.hpp"
using namespace std;
int main(){
    int opcion;
    char respuesta='s';
    while (respuesta=='s' || respuesta=='S'){
        cout<<"(1) Jugar 31"<<endl;
        cout<<"(0) Salir"<<endl;
        cout<<"->Ingrese: ";
        cin>>opcion;
        if (opcion==1){
            string nombre_jugador;
            int cantidad_jugadores;
            cout<<"->Ingrese el numero de jugadores(2-10):";
            cin>>cantidad_jugadores;
            while (cantidad_jugadores<2 || cantidad_jugadores>10 ){
               cout<<"->Ingrese el numero de jugadores(2-10):";
                cin>>cantidad_jugadores;
            }
            cout<<"->Ingrese su nombre: ";
            cin>>nombre_jugador;
            Game::comenzar(cantidad_jugadores, nombre_jugador);
        }else if(opcion==0){
            respuesta='d';
        }
    }
}