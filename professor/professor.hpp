#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

// Bibliotecas
#include "../pessoas/pessoas.hpp"

class Professor : public Pessoa{
private:
    string especializacao;
    const int tipo = 2;

public:
    Professor(string nome, string cpf, int dia, int mes, int ano, string especializacao) : Pessoa(nome, cpf, dia, mes, ano), especializacao(especializacao) {};
    Professor(string nome, int mes, int dia, int ano) : Pessoa(nome, mes, dia, ano) {};
    Professor(string esp);

    Professor() {};
    ~Professor() {};

    void setEspecializacao(string esp);
    string getEspecializacao();

    int getTipo();

    void leiaPessoa();
    void escrevePessoa();
};

// Funções de pesquisa
void pesquisaProfessorNome(Pessoa* pessoas[]);
void pesquisaProfessorCPF(Pessoa* pessoas[]);

// Funções de excluir pessoas
bool apagarProfessor(Pessoa* pessoas[]);
void apagarTodosProfessores(Pessoa* pessoas[]);

// Funções de listar
void listaProfessores(Pessoa* pessoas[]);
void listarProfessoresAniversariantes(Pessoa* pessoas[], int mes);

void escreveProfessorArquivo(ofstream& arquivo, Pessoa* pessoa);

#endif // PROFESSOR_HPP