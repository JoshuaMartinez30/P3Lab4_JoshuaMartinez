#include "Player.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
class Game{
public:
    Game();
    static void comenzar(int cantidad_jugadores_new, string nombre){
        vector<Player*> cantidad_jugadores;
        cantidad_jugadores.push_back(new Player(nombre, 0));          
        string nombre1;
        vector<string> Mazo;
        string carta = "";
        int conta = 1;
        for (int i = 1; i < cantidad_jugadores_new; i++){
            nombre1 = "bot-" + to_string(i);
            cantidad_jugadores.push_back(new Player(nombre1, 0));    
            nombre1 = "";
        }
        for (int i = 1; i <= 13; i++){
            if (i==1){
                carta = "A|O?";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|O?";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|O?";
                Mazo.push_back(carta);
                carta = "";
            }else if(i==13){
                carta = "K|O?";
                Mazo.push_back(carta);
                carta = "";                
            }else{
                carta = "" + to_string(i) + "|O?";
                Mazo.push_back(carta);
                carta = "";
            }
        }
        for (int i = 1; i <= 13; i++){
            if (i==1){
                carta = "A|<3";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|<3";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|<3";
                Mazo.push_back(carta);
                carta = "";
            }else if(i==13){
                carta = "K|<3";
                Mazo.push_back(carta);
                carta = "";                
            }else{
                carta = "" + to_string(i) + "|<3";
                Mazo.push_back(carta);
                carta = "";
            }
        }
        for (int i = 1; i <= 13; i++){
            if (i==1){
                carta = "A|-#";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|-#";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|-#";
                Mazo.push_back(carta);
                carta = "";
            }else if(i==13){
                carta = "K|-#";
                Mazo.push_back(carta);
                carta = "";                
            }else{
                carta = "" + to_string(i) + "|-#";
                Mazo.push_back(carta);
                carta = "";
            }
        }
        for (int i = 1; i <= 13; i++){
            if (i==1){
                carta = "A|<>";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|<>";
                Mazo.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|<>";
                Mazo.push_back(carta);
                carta = "";
            }else if(i==13){
                carta = "K|<>";
                Mazo.push_back(carta);
                carta = "";                
            }else{
                carta = "" + to_string(i) + "|<>";
                Mazo.push_back(carta);
                carta = "";
            }
        }    
        int tamanio = Mazo.size();
        int numero_random = 200 + rand() % (800);
        for (int i = 0; i < numero_random; i++) {
            int j = rand() % tamanio;
            int k = rand() % tamanio;
            swap(Mazo[j], Mazo[k]);
        }
        for (int i = 0; i < cantidad_jugadores_new; i++){
            for (int j = 0; j < 3; j++){
                cantidad_jugadores[i]->mano.push_back(Mazo.back());
                Mazo.pop_back();           
            }          
        }
        string cartajugador, numeros;
        int puntaje1, total_puntaje = 0;
        for (int i = 0; i < cantidad_jugadores_new; i++){
            if (i == 0){
                cout << cantidad_jugadores[0]->nombre << ": [" << cantidad_jugadores[0]->mano[0] << "," << cantidad_jugadores[0]->mano[1] << "," << cantidad_jugadores[0]->mano[2] << "]" << endl;
                int respuesta;
                cout << "->Tomar otra carta?[1-si|2-no]: ";
                cin >> respuesta;
                while (respuesta<1 || respuesta>2){
                    cout << "->Tomar otra carta?[1-si|2-no]: ";
                    cin >> respuesta;
                }
                int adicion = 3;
                while (respuesta == 1){
                    cantidad_jugadores[0]->mano.push_back(Mazo.back());
                    Mazo.pop_back();
                    for (int i = 0; i <=adicion; i++)
                    {
                        if (i==0){
                            cout << cantidad_jugadores[0]->nombre<<": [" << cantidad_jugadores[0]->mano[i] << ",";
                        }
                        
                        if (i<adicion && i!=0){
                            cout<< cantidad_jugadores[0]->mano[i] << ",";    
                        }
                        if (i==adicion){
                            cout<<cantidad_jugadores[0]->mano[i] << "]"<<endl;
                        }
                        
                    }   
                    cout << "->Tomar otra carta?[1-si|2-no]: ";
                    cin >> respuesta;
                    while (respuesta<1 || respuesta>2){
                    cout << "->Tomar otra carta?[1-si|2-no]: ";
                    cin >> respuesta;
                }
                    adicion++; 
                }
                for (int j = 0; j < cantidad_jugadores[0]->mano.size(); j++){
                    cartajugador = cantidad_jugadores[0]->mano[j];
                    puntaje1 = 0;
                    if (cartajugador[0] == '1' && cartajugador[1] == '0'){
                        numeros = cartajugador.substr(0, 2);
                        puntaje1 = stoi(numeros);
                        total_puntaje += puntaje1;
                    } else {
                        numeros = cartajugador.substr(0, 1);
                        if (numeros == "A"){
                            puntaje1 = 1;
                            total_puntaje += puntaje1;
                        } else if (numeros == "J"){
                            puntaje1 = 11;
                            total_puntaje += puntaje1;                            
                        } else if (numeros == "Q"){
                            puntaje1 = 12;
                            total_puntaje += puntaje1;                            
                        } else if (numeros == "K"){
                            puntaje1 = 13;
                            total_puntaje += puntaje1;
                        } else {
                            puntaje1 = stoi(numeros);
                            total_puntaje += puntaje1;
                        }            
                    }                  
                }
                cantidad_jugadores[0]->puntaje = total_puntaje;  
                total_puntaje = 0;                           
            } else {
                int contador1 = 2;
                for (int j = 0; j < 3; j++){
                    cartajugador = cantidad_jugadores[i]->mano[j];
                    puntaje1 = 0;
                    if (cartajugador[0] == '1' && cartajugador[1] == '0'){
                        numeros = cartajugador.substr(0, 2);
                        puntaje1 = stoi(numeros);
                        total_puntaje += puntaje1;
                    } else {
                        numeros = cartajugador.substr(0, 1);
                        if (numeros == "A"){
                            puntaje1 = 1;
                            total_puntaje += puntaje1;
                        } else if (numeros == "J"){
                            puntaje1 = 11;
                            total_puntaje += puntaje1;                            
                        } else if (numeros == "Q"){
                            puntaje1 = 12;
                            total_puntaje += puntaje1;                            
                        } else if (numeros == "K"){
                            puntaje1 = 13;
                            total_puntaje += puntaje1;
                        } else {
                            puntaje1 = stoi(numeros);
                            total_puntaje += puntaje1;
                        }            
                    }                 
                }
                if (total_puntaje < 27){
                    bool prueba = true;
                    while (prueba){
                        cantidad_jugadores[i]->mano.push_back(Mazo.back());
                        Mazo.pop_back();
                        contador1++;
                        cartajugador = cantidad_jugadores[i]->mano[contador1];
                        if (cartajugador[0] == '1' && cartajugador[1] == '0'){
                            numeros = cartajugador.substr(0, 2);
                            puntaje1 = stoi(numeros);
                            total_puntaje += puntaje1;
                        } else {
                            numeros = cartajugador.substr(0, 1);
                            if (numeros == "A"){
                                puntaje1 = 1;
                                total_puntaje += puntaje1;
                            } else if (numeros == "J"){
                                puntaje1 = 11;
                                total_puntaje += puntaje1;                            
                            } else if (numeros == "Q"){
                                puntaje1 = 12;
                                total_puntaje += puntaje1;                            
                            } else if (numeros == "K"){
                                puntaje1 = 13;
                                total_puntaje += puntaje1;
                            } else {
                                puntaje1 = stoi(numeros);
                                total_puntaje += puntaje1;
                            }            
                        }
                        int random1;
                        random1 = rand() % 100;
                        if (random1 < 50 && random1 > 45){
                            prueba = true;
                        } else {
                            prueba = false;
                            cantidad_jugadores[i]->puntaje = total_puntaje;  
                            total_puntaje = 0;   
                        }
                    }                                                                                              
                } else {
                    cantidad_jugadores[i]->puntaje = total_puntaje;  
                    total_puntaje = 0;   
                }                               
            }                           
        } 
        int contador = 1;
        int centinela=0;
        for (int i = 0; i < cantidad_jugadores_new; i++){
            if (centinela==0){
                if (cantidad_jugadores[i]->puntaje > 31 && centinela==0){
                    cout << "Perdedor: " << cantidad_jugadores[i]->nombre << " puntos: " << to_string(cantidad_jugadores[i]->puntaje) << endl;
                }    
            }
            if (centinela==1)
            {
                if (cantidad_jugadores[i]->puntaje <= 31){
                    cout << to_string(contador)<<". " << cantidad_jugadores[i]->nombre << " puntos: " << to_string(cantidad_jugadores[i]->puntaje) << endl;
                    contador++;
                }    
            }
            if(i==cantidad_jugadores_new-1 && centinela==0){
                i=0;
                centinela++;
            }                 
        }          
    }  
    ~Game(){} 
}; 