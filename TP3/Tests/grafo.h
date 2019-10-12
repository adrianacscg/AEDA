#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};


template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template <class N, class A> 
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g){
    g.imprimir(out);
    return out;
}

// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }


//***********************************************************************
//***********************************************************************

//Constructors and destructors
template <typename N, typename A>
Grafo<N,A>::Grafo(){

}

template <typename N, typename A>
Grafo<N,A>::~Grafo() {
    for(auto element : nos)
        delete element;

}

template <typename N, typename A>
int Grafo<N,A>::numNos() const {
    return nos.size();
}

template <typename N, typename A>
int Grafo<N,A>::numArestas() const {
    int arestas_totais = 0;
    for (int i = 0; i < nos.size(); ++i) {
        arestas_totais += nos[i] -> arestas.size();
    }
    return arestas_totais;
}

template <typename N, typename A>
Grafo<N,A> & Grafo<N,A>::inserirNo(const N &dados) {
    bool no_existe = false;
    for (int i = 0; i < nos.size(); ++i) {
        if (nos[i] -> info == dados)
            no_existe = true;
        else
            continue;
    }

    if(no_existe)
        throw NoRepetido<N>(dados);


    nos.push_back(new No<N,A>(dados));
    return *this;
}

// excecao ArestaRepetida
template <class N>
class ArestaRepetida
{
public:
    N info1;
    N info2;
    ArestaRepetida(N inf1, N inf2) {
        info1 = inf1;
        info2 = inf2;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaRepetida<N> &ar)
{ out << "Aresta Repetida: " << ar.info1 << " , " << ar.info2;
    return out;}


//exceção ArestaInexistente
template <class N>
class ArestaInexistente{
public:
    N info1;
    N info2;
    ArestaInexistente(N inf1, N inf2) {
        info1 = inf1;
        info2 = inf2;
    }
};
template <class N>
std::ostream & operator<<(std::ostream &out, const ArestaInexistente<N> &ai)
{ out << "Aresta Inexistente: " << ai.info1 << " , " << ai.info2;
    return out;}


template <typename N, typename A>
Grafo<N,A> & Grafo<N,A>::inserirAresta(const N &inicio, const N &fim, const A &val) {
    bool no1_existe = false;
    for (int i = 0; i < nos.size(); ++i) {
        if (nos[i]->info == inicio)
            no1_existe = true;
        else
            continue;
    }

    bool no2_existe = false;
    for (int i = 0; i < nos.size(); ++i) {
        if (nos[i]->info == fim)
            no2_existe = true;
        else
            continue;
    }

    if (!no1_existe)
        throw NoInexistente<N>(inicio);

    else if (!no2_existe)
        throw NoInexistente<N>(fim);

    int index_inicio = 0;
    int index_final = 0;

    for (int j = 0; j < nos.size(); ++j) {
        if (nos[j]->info == inicio)
            index_inicio = j;
        else
            continue;
    }
    for (int k = 0; k < nos[index_inicio]->arestas.size(); ++k) {
        if (nos[index_inicio]->arestas[k].destino->info == fim) {
            throw (ArestaRepetida<N>(inicio, fim));
        }
        else
            continue;
    }


    nos[index_inicio]->arestas.push_back(Aresta<N,A>(nos[index_final], val));

    return *this;

}

template <typename N, typename A>
A & Grafo<N,A>::valorAresta(const N &inicio, const N &fim) {
    int index_inicio = 0;

    for (int j = 0; j < nos.size(); ++j) {
        if (nos[j]->info == inicio)
            index_inicio = j;
        else
            continue;
    }
    for (int i = 0; i < nos[index_inicio]->arestas.size() ; ++i) {
        if(nos[index_inicio]->arestas[i].destino->info == fim){
            return nos[index_inicio]->arestas[i].valor;
        }
        else
            continue;
    }

    throw (ArestaInexistente<N>(inicio, fim));

}

template <typename N, typename A>
Grafo<N,A> & Grafo<N,A>::eliminarAresta(const N &inicio, const N &fim) {
    int index_inicio = -2;
    int index_final = -2;

    for (int j = 0; j < nos.size(); ++j) {
        if (nos[j]->info == inicio)
            index_inicio = j;
        else
            continue;
    }

    for (int k = 0; k < nos.size(); ++k) {
        if (nos[k]->info == fim)
            index_final = k;
        else
            continue;
    }

    if(index_inicio == -2)
        throw (NoInexistente<N>(inicio));
    if(index_final == -2)
        throw (NoInexistente<N>(fim));

    for (int i = 0; i < nos[index_inicio]->arestas.size() ; ++i) {
        if(nos[index_inicio]->arestas[i].destino->info == fim){
            nos[index_inicio]->arestas.erase(nos[index_inicio]->arestas.begin()+i);
            return *this;
        }
        else
            continue;
    }
    throw (ArestaInexistente<N>(inicio, fim));
}

template <typename N, typename A>
void Grafo<N,A>::imprimir(std::ostream &os) const {
    for(int i=0 ; i<nos.size() ; i++){
        os << "( " << nos[i]->info;
        for(int j=0 ; j<nos[i]->arestas.size() ; j++){
            os << "[ " << nos[i]->arestas[j].destino->info << " " << nos[i]->arestas[j].valor << "] ";
        }
        os << ") ";
    }
}
