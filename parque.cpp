#include "parque.h"
#include <vector>
#include <algorithm>

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

    //atualiza os dados
    vagas--;
    clientes[index].presente = true;

    return true;
}
/*
bool ParqueEstacionamento::retiraCliente(const string &nome) {
    int index = posicaoCliente(nome);
    if(clientes[index].presente == true)
        return false;

}
*/
