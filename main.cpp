#include <iostream>
#include <stdio.h>
#include "pessoas/pessoas.hpp"
#include "data/data.hpp"
using namespace std;

extern int TAM;

// Main
int main(){
    Pessoa pessoas[MAX];
    inicializacao(pessoas); // Inicialização do sistema
    
    int opcao;
    Data hoje = dataAtual();

    do{
        cout << endl << "= Menu ="
             << endl << "0 - Sair"
             << endl << "1 - Cadastrar pessoas"
             << endl << "2 - Listar pessoas"
             << endl << "3 - Pesquisar pessoa por nome"
             << endl << "4 - Pesquisar pessoa por CPF"
             << endl << "5 - Excluir pessoa especifica"
             << endl << "6 - Excluir todas as pessoas cadastradas"
             << endl << endl << "Opcao: ";

        cin >> opcao;

        switch(opcao){
            case -1: cout << endl << "= DEBUG =" << endl
                          << TAM << endl
                          << hoje.getDia() << "/" << hoje.getMes() << "/" << hoje.getAno() << endl
                          << endl;
            break;
            
            case 0: finalizacao(pessoas);
            break;

            case 1: cadastroPessoa(pessoas);
            break;
            
            case 2: if(TAM == 0){
                        cout << endl << "= Nao ha nenhuma pessoa cadastrada" << endl;
                    } else {
                        listaPessoa(pessoas);
                    }
            break;
            
            case 3: pesquisaPessoaNome(pessoas);
            break;
            
            case 4: pesquisaPessoaCPF(pessoas);
            break;

            case 5: excluirPessoa(pessoas);
            break;
            
            case 6: apagarTodasPessoas(pessoas);
            break;
            
            default: printf("\nOpcao invalida. Tente novamente.");
        }
    } while(opcao != 0);

    return 0;
} // fim main()