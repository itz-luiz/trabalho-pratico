#ifndef PESSOAS_H
#define PESSOAS_H

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
    void setNome(string nome);
    string getNome();

    void setCPF(string cpf);
    string getCPF();

    void setNascimento(Data nascimento);
    Data getNascimento();

    void leiaPessoa();
    void escrevePessoa();
};

// class Aluno : public Pessoa {
// private:


// public:

// };

// Protótipos das funções
void inicializacao(Pessoa pessoas[]);
void finalizacao(Pessoa pessoas[]);
int tamanho();

void carregaPessoasArquivo(Pessoa pessoas[]); // Carrega as pessoas registradas no arquivo
void lePessoasArquivo(ifstream& arquivo, Pessoa& pessoa); // Lê as pessoas registradas no arquivo (usando getline)
void escrevePessoasArquivo(ofstream& arquivo, Pessoa& pessoa); // Escreve as pessoas no arquivo, linha por linha
void gravaPessoasArquivo(Pessoa pessoas[]);
void gravaTamanhoArquivo();

void cadastroPessoa(Pessoa pessoas[]);
void listaPessoa(Pessoa pessoas[]);
void apagarTodasPessoas(Pessoa pessoas[]);

void pesquisaPessoaNome(Pessoa pessoas[]);
void pesquisaPessoaCPF(Pessoa pessoas[]);

#endif // PESSOAS_H