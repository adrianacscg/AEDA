#include "parque.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>

using namespace std;



ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):
	lotacao(lot), numMaximoClientes(nMaxCli) {
    numClientes = 0;
    vagas=lot; 
}

ParqueEstacionamento::~ParqueEstacionamento() {}

vector<InfoCartao> ParqueEstacionamento::getClientes() const { return clientes; }

unsigned int ParqueEstacionamento::getNumLugares() const { return lotacao; }

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const { return lotacao-vagas; }


// a imnplementar
int ParqueEstacionamento::posicaoCliente(const string &nome) const
{   vector<string> nomes;
    for(auto cliente : clientes){
        nomes.push_back(cliente.nome);
    }
    return sequentialSearch(nomes, nome);
}

//a implementar
int ParqueEstacionamento::getFrequencia(const string &nome) const
{
    for (auto cliente : clientes) {
        if (cliente.nome == nome)
            return cliente.frequencia;
        else
            continue;
    }
    throw ClienteNaoExistente(nome);

}

ClienteNaoExistente::ClienteNaoExistente(string nome) {
    name = nome;
}
string ClienteNaoExistente::getNome() {
    return name;
}


// a alterar/atualizar ?
bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
 	if ( numClientes == numMaximoClientes ) return false;
	if ( posicaoCliente(nome) != -1 ) return false;
	InfoCartao info;
	info.nome = nome;
    info.presente = false;
    info.frequencia = 0;
	clientes.push_back(info);
	numClientes++;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::retiraCliente(const string & nome)
{
	for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
		if ( it->nome == nome ) {
			if ( it->presente == false ) {
				clientes.erase(it);
				numClientes--;
				return true;
			}
			else return false;
		}
	return false;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	clientes[pos].frequencia = clientes[pos].frequencia + 1;
	return true;
}

// a alterar/atualizar ?
bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}

		
// a implementar
void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    insertionSort(clientes);
}


// a implementar
void ParqueEstacionamento::ordenaClientesPorNome()
{
    ordenaClientesPorFrequencia();
    //Bubble Sort

    for(unsigned int j = clientes.size()-1; j > 0; j--){

        for(unsigned int i = 1; i<=j;i++){
            if(clientes[i].nome < clientes[i-1].nome){
                swap(clientes[i], clientes[i-1]);
            }
        }
    }
}



// a implementar
vector<string> ParqueEstacionamento::clientesGamaUso(int n1, int n2)
{
    vector<string> nomes;
    ordenaClientesPorFrequencia();
    for(auto cliente : clientes){
        if(cliente.frequencia >= n1 && cliente.frequencia<=n2)
            nomes.push_back(cliente.nome);
        else
            continue;
    }
    return nomes;
}


// a implementar
ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    return os;
}


// a implmentar
InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    InfoCartao info;
    return info;
}
/*
bool InfoCartao::operator==(const InfoCartao &ic) {
    return this->nome == ic.nome;

}
*/
bool InfoCartao::operator<(const InfoCartao &ic) {
    if(this->frequencia > ic.frequencia)    //a frequencia é ordenada de forma decrescente
        return true;
    else if(this->frequencia == ic.frequencia)
        return (this->nome < ic.nome);            //os nomes são ordenados de forma crescente
    else
        return false;
}
