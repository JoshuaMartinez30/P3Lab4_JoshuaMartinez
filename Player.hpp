#include <iostream>
#include <vector>
using namespace std;
class Player{
    private:
    string nombre;
    int puntaje;
    vector<string> mano;
    friend class Game;
    public:
    Player(){}
    Player(string nombre_new, int puntaje_new){
        this->nombre = nombre_new;
        this->puntaje = puntaje_new;
    }
    ~Player(){}
};