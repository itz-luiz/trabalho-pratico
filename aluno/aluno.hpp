#ifndef ALUNO_HPP
#define ALUNO_HPP

// Bibliotecas
#include "../pessoas/pessoas.hpp"

class Aluno : public Pessoa{
private:
    string matricula;
    const int tipo = 1;

public:
    Aluno(string nome, string cpf, int dia, int mes, int ano, string matricula) : Pessoa(nome, cpf, dia, mes, ano), matricula(matricula) {};
    Aluno(string nome, int dia, int mes, int ano) : Pessoa(nome, dia, mes, ano) {};
    Aluno(string matricula);
    
    Aluno() {};
    ~Aluno() {};

    void setMatricula(string mat);
    string getMatricula();
    
    int getTipo();

    void leiaPessoa();
    void escrevePessoa();
};

// Funções de pesquisa
void pesquisaAlunoNome(Pessoa* pessoas[]);
void pesquisaAlunoCPF(Pessoa* pessoas[]);

// Funções de excluir pessoas
bool apagarAluno(Pessoa* pessoas[]);
void apagarTodosAlunos(Pessoa* pessoas[]);

// Funções de listar
void listaAlunos(Pessoa* pessoas[]);
void listarAlunosAniversariantes(Pessoa* pessoas[], int mes);

void escreveAlunoArquivo(ofstream& arquivo, Pessoa* pessoa);

#endif // ALUNO_HPP