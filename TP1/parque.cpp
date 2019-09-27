#include "parque.h"
//#include <vector>
//#include <algorithm>

using namespace std;

ParqueEstacionamento ::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : numMaximoClientes(nMaxCli), lotacao(lot) {
    vagas = lot;
    clientes.clear();
}

unsigned int ParqueEstacionamento::getNumLugares() const {
    return lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
    return numMaximoClientes;
}


bool ParqueEstacionamento::adicionaCliente(const string &nome) {


    if(clientes.size() < numMaximoClientes)   {

        InfoCartao novoCliente;
        novoCliente.nome = nome;
        novoCliente.presente = false;

        clientes.push_back(novoCliente);

        return true;
    }

    return false;
}


int ParqueEstacionamento::posicaoCliente(const string &nome) const {

    for(unsigned int i=0; i <= clientes.size(); i++) {
        if (clientes[i].nome == nome) {
            return i;
        } else
            continue;
    }

    return -1;
}


bool ParqueEstacionamento::entrar(const string &nome) {

    if(posicaoCliente(nome) == -1)      //cliente não existe
        return false;


    int index = posicaoCliente(nome);
    if(clientes[index].presente)        //cliente já está no parque
        return false;


    if(vagas == 0)                          //parque está cheio
        return false;


    vagas--;
    clientes[index].presente = true;        //atualiza os dados

    return true;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) {

    if(posicaoCliente(nome) == -1)      //cliente não existe
        return false;

    int index = posicaoCliente(nome);
    if(clientes[index].presente == true)                //cliente está ainda dentro do parque
        return false;

    clientes.erase(clientes.begin()+index);     //apaga o nome do cliente do vetor clientes
    clientes.erase(clientes.begin()+index);     //apaga o estado do cliente (presente) do vetor

    return true;

}

bool ParqueEstacionamento::sair(const string &nome) {
    if(posicaoCliente(nome) == -1)      //cliente não existe
        return false;

    int index = posicaoCliente(nome);
    if(clientes[index].presente == false)                //cliente não está dentro do parque
        return false;

    clientes[index].presente = false;           //atualiza os dados do cliente e vagas
    vagas ++;

    return true;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    int num_lugares = lotacao-vagas;
    return num_lugares;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    int num_clientes = clientes.size();
    return num_clientes;
}

const ParqueEstacionamento & ParqueEstacionamento::operator+= (const ParqueEstacionamento & p2){
    vagas = vagas + p2.vagas;
    int *ptr_p1 = (int*) &numMaximoClientes;
    int  *ptr_p2 = (int*) &p2.numMaximoClientes;
    *ptr_p1 += *ptr_p2;
    


}

