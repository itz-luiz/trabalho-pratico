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
#include "../data/data.hpp"
using namespace std;

#define MAX 100
#define MAX_STR 50
#define MAX_CPF 15

class Pessoa{
private:
    string nome;
    string cpf;
    Data nascimento;

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

// Protótipos das funções
void inicializacao(Pessoa pessoas[]);
int tamanho();
void carregaPessoasArquivo(Pessoa pessoas[]); // Carrega as pessoas registradas no arquivo
void gravaPessoasArquivo(Pessoa pessoas[]);
void gravaTamanhoArquivo();
void cadastroPessoa(Pessoa pessoas[]);
void listaPessoa(Pessoa pessoas[]);
void apagarTodasPessoas(Pessoa pessoas[]);

#endif // PESSOAS_H