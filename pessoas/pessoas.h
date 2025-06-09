#ifndef PESSOAS_H
#define PESSOAS_H

#include "../data/data.h"
// #include "../tipos.h"

#define MAX 100
#define MAX_STR 50
#define MAX_CPF 15

typedef struct{
    char nome[MAX_STR];
    char cpf[MAX_CPF];
    Data nascimento;
} Pessoa;

// Protótipos das funções
void inicializacao(Pessoa pessoas[]);
int tamanho();
void carregaPessoasArquivo(Pessoa pessoas[]); // Carrega as pessoas registradas no arquivo
void gravaPessoasArquivo(Pessoa pessoas[]);
void gravaTamanhoArquivo();
void cadastroPessoa(Pessoa pessoas[]);
void listaPessoa(Pessoa pessoas[]);
float mediaIdade(Pessoa pessoas[]);

#endif // PESSOAS_H