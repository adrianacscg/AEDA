#include "veiculo.h"
#include <iostream>

using namespace std;

//Constructors
Veiculo::Veiculo(string mc, int m, int a) : marca(mc), mes(m), ano(a) {

}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil): Veiculo(mc, m, a), combustivel(c), cilindrada(cil) {

}

Automovel::Automovel(string mc, int m, int a, string c, int cil): Motorizado(mc, m, a, c, cil) {

}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado(mc, m, a, c, cil), carga_maxima(cm) {

}

Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo(mc, m, a), tipo(t) {

}

//Member Functions
string Motorizado::getCombustivel() const {
    return combustivel;
}

string Veiculo::getMarca() const {
    return marca;
}

int Veiculo::getAno() const {
    return ano;
}

int Veiculo::info() const {
    cout << marca << endl;
    cout << mes << endl;
    cout << ano << endl;
    int num_membros_dados = 3;
    return num_membros_dados;
}

int Motorizado::info() const {
    Veiculo::info();
    cout << combustivel << endl;
    cout << cilindrada << endl;
    int num_membros_dados = Veiculo::info() + 2;
    return num_membros_dados;
}

int Automovel::info() const {
    Motorizado::info();
    return Motorizado::info();
}

int Camiao::info() const {
    Motorizado::info();
    cout << carga_maxima << endl;
    int num_membros_dados = Motorizado::info() + 1;
    return num_membros_dados;
}

int Bicicleta::info() const {
    Veiculo::info();
    cout << tipo << endl;
    int num_membros_dados = Veiculo::info() + 1;
    return num_membros_dados;
}

bool Veiculo::operator<(const Veiculo &v) const {
    if(this->ano < v.ano ){
        this < v;
    }
    else if (this->ano == v.ano){
        if (this->mes < v.mes)
            this < v;
    }
    return 0;
}