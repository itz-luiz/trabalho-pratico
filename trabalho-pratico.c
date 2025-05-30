#include <stdio.h>
#include "pessoas/pessoas.h"
#include "data/data.h"

// Main
int main(){
    Pessoa pessoas[MAX];
    int opcao, TAM = tamanho();

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
            break;
            case 1: cadastroPessoa(pessoas);
                    printf("\n= Pessoa cadastrada =\n");
            break;
            case 2: listaPessoa(pessoas);
            break;
            case 3: printf("\nA media das idades e: %.1f\n", mediaIdade(pessoas, TAM));
            break;
            case 4: dataAtual();
            break;
            default: printf("\nOpcao invalida. Tente novamente.");
        }

        TAM = tamanho();
    } while(opcao != 0);
} // fim main()