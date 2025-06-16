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

    do{
        cout << "\n= Menu ="
             << "\n0 - Sair"
             << "\n1 - Cadastrar pessoas"
             << "\n2 - Listar pessoas"
             << "\n3 - Apagar todas as pessoas cadastradas"
             << "\n\nOpcao: ";

        cin >> opcao;

        switch(opcao){
            case -1: cout << endl << "= DEBUG =" << endl
                          << TAM
                          << pessoas[0].getNome()
                          << endl;
            break;
            case 0: cout << endl << "Obrigador por usar o programa" ;
                    gravaPessoasArquivo(pessoas);
                    gravaTamanhoArquivo();
            break;
            case 1: cadastroPessoa(pessoas);
            break;
            case 2: if(TAM == 0){
                        cout << endl << "= Nao ha nenhuma pessoa cadastrada" << endl;
                    } else {
                        listaPessoa(pessoas);
                    }
            break;
            case 3: apagarTodasPessoas(pessoas);
            break;
            default: printf("\nOpcao invalida. Tente novamente.");
        }
    } while(opcao != 0);

    return 0;
} // fim main()