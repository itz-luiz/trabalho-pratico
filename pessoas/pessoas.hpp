#ifndef PESSOAS_HPP
#define PESSOAS_HPP

// Bibliotecas
#include <iostream>
#include <iomanip>
#include <limits>
#include <ios>
#include <string>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream> // Para usar I/O de arquivos em C++
#include "../data/data.hpp"

using namespace std;

#define MAX 100

class Pessoa {
private:
    string nome; // Nome da pessoa
    string cpf; // CPF: 000.000.000-00
    Data nascimento; // Nascimento: dd/mm/aaaa

public:
    static int TAM;

    Pessoa();
    Pessoa(string nome);
    Pessoa(string nome, int dia, int mes, int ano);
    Pessoa(string nome, string cpf, int dia, int mes, int ano);

    virtual ~Pessoa(){};
    
    void setNome(string nome);
    string getNome();

    void setCPF(string cpf);
    string getCPF();

    void setNascimento(Data nascimento);
    Data getNascimento();

    virtual void leiaPessoa() = 0;
    virtual void escrevePessoa() = 0;
    virtual int getTipo() = 0;
};

// Protótipos das funções
void inicializacao(Pessoa* pessoas[]);
void finalizacao(Pessoa* pessoas[]);
int tamanho();

void carregaPessoasArquivo(Pessoa* pessoas[]); // Carrega as pessoas registradas no arquivo
void lePessoasArquivo(ifstream& arquivo, Pessoa*& pessoa); // Lê as pessoas registradas no arquivo (usando getline)
void escrevePessoasArquivo(ofstream& arquivo, Pessoa* pessoa); // Escreve as pessoas no arquivo, linha por linha
void gravaPessoasArquivo(Pessoa* pessoas[]);
void gravaTamanhoArquivo();

void listaPessoa(Pessoa* pessoas[], int n);
bool excluirPessoa(Pessoa* pessoas[]);
void apagarTodasPessoas(Pessoa* pessoas[]);

void pesquisaPessoaNome(Pessoa* pessoas[]);
bool pesquisaPessoaNomeRec(Pessoa* pessoas[], string chave, int n);
void pesquisaPessoaCPF(Pessoa* pessoas[]);

string leiaCPF();

// Funções apagadas
// void cadastroPessoa(Pessoa* pessoas[]);

#endif // PESSOAS_HPP