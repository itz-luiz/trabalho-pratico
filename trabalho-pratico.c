#include <stdio.h>
#include "pessoas/pessoas.h"
#include "data/data.h"

extern int TAM;

// Main
int main(){
    Pessoa pessoas[MAX];
    inicializacao(pessoas); // Inicialização do sistema
    
    int opcao;

    do{
        printf(
            "\n= Menu ="
            "\n0 - Sair"
            "\n1 - Cadastrar pessoas"
            "\n2 - Listar pessoas"
            "\n3 - Media de idade da turma"
            "\n\nOpcao: "
        );

        scanf("%d", &opcao);

        switch(opcao){
            case 0: printf("\nObrigado por usar o programa!");
                    gravaPessoasArquivo(pessoas);
                    gravaTamanhoArquivo();
            break;
            case 1: cadastroPessoa(pessoas);
                    printf("\n= Pessoa cadastrada =\n");
            break;
            case 2: listaPessoa(pessoas);
            break;
            case 3: printf("\nA media das idades e: %.1f\n", mediaIdade(pessoas));
            break;
            case 4: printf("\n%d", TAM);
            break;
            default: printf("\nOpcao invalida. Tente novamente.");
        }
    } while(opcao != 0);

    return 0;
} // fim main()