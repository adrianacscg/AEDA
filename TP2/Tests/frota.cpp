#include "frota.h"
#include <string>

using namespace std;

void Frota::adicionaVeiculo(Veiculo *v1){
    veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    int num_veiculos = veiculos.size();
    return num_veiculos;
}

int Frota::menorAno() const {

    if(veiculos.empty())
        return 0;
    else{
        int menor_ano = 3000;
        for(auto veiculo : veiculos){
            if(veiculo -> getAno() < menor_ano){
                menor_ano = veiculo -> getAno();
            }
            else
                continue;
        }
        return menor_ano;
    }
}

ostream & operator<< (ostream &o, const Frota &f) {
    for(auto veiculo : f.veiculos){
        o << veiculo->info();
    }
    return o;
}
vector<Veiculo*> Frota::operator()(int anoM) const {
    vector<Veiculo*> v;
    for (auto vehicle : veiculos) if (vehicle->getAno() == anoM) v.push_back(vehicle);

    return v;
}