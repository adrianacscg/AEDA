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



int ParqueEstacionamento::posicaoCliente(const string &nome) const
{   vector<string> nomes;
    for(auto cliente : clientes){
        nomes.push_back(cliente.nome);
    }
    return sequentialSearch(nomes, nome);
}


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

bool ParqueEstacionamento::entrar(const string & nome)
{
	if ( vagas == 0 ) return false;
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == true ) return false;
	clientes[pos].presente = true;
	vagas--;
	clientes[pos].frequencia = clientes[pos].frequencia + 1;        //atualizar valor de frequencia
	return true;
}


bool ParqueEstacionamento::sair(const string & nome)
{
	int pos = posicaoCliente(nome);
	if ( pos == -1 ) return false;
	if ( clientes[pos].presente == false ) return false;
	clientes[pos].presente = false;
	vagas++;
	return true;
}


void ParqueEstacionamento::ordenaClientesPorFrequencia()
{
    insertionSort(clientes);
}


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


ostream & operator<<(ostream & os, const ParqueEstacionamento & pe)
{
    for(int i = 0; i < pe.clientes.size(); i++) {
        os << pe.clientes.at(i).nome << endl;
        os << pe.clientes.at(i).presente << endl;
        os << pe.clientes.at(i).frequencia << endl;
    }
    return os;
}


InfoCartao ParqueEstacionamento::getClienteAtPos(vector<InfoCartao>::size_type p) const
{
    InfoCartao info;
    if(0 <= p && p <= clientes.size()-1)
        return clientes.at(p);
    else
        throw PosicaoNaoExistente(p);
}

PosicaoNaoExistente::PosicaoNaoExistente(int p): posicao(p) {}

int PosicaoNaoExistente::getValor() {
    return posicao;
}

bool InfoCartao::operator<(const InfoCartao &ic) {
    if(this->frequencia > ic.frequencia)    //a frequencia é ordenada de forma decrescente
        return true;
    else if(this->frequencia == ic.frequencia)
        return (this->nome < ic.nome);            //os nomes são ordenados de forma crescente
    else
        return false;
}
