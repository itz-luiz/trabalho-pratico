#include <stdio.h>
#include <time.h>
#include <string.h>
#include "../tipos.h"
#include "pessoas.h"
#include "../data/data.h"

// Cadastrar variáveis globais
int TAM = 0; 

// Funções
int tamanho(){
    return TAM;
}

void cadastroPessoa(Pessoa pessoas[]){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nInsira o nome da pessoa: ");
    fgets(pessoas[TAM].nome, MAX_STR, stdin);

    fflush(stdin);
    printf("Insira o CPF (xxx.xxx.xxx-xx): ");
    fgets(pessoas[TAM].cpf, MAX_CPF, stdin);

    printf("Insira a data de nacimento da pessoa (DD/MM/AAAA): ");
    scanf("%d/%d/%d",
        &pessoas[TAM].nascimento.dia,
        &pessoas[TAM].nascimento.mes,
        &pessoas[TAM].nascimento.ano
    );

    TAM++;
} // fim cadastroPessoa()

void listaPessoa(Pessoa pessoas[]){
    for(int i=0; i<TAM; i++){
        printf("\n%s", pessoas[i].nome);
        printf("%s", pessoas[i].cpf);
        printf("\n%d/%d/%d",
            pessoas[i].nascimento.dia,
            pessoas[i].nascimento.mes,
            pessoas[i].nascimento.ano
        );
        // printf("\n%d", calcIdade(pessoas, i));
        printf("\n");
    }
} // fim listaPessoa()

float mediaIdade(Pessoa pessoas[], int n){
    float soma = 0;

    for(int i=0; i<n; i++){
        soma += calcIdade(pessoas, i);
    }

    return soma/n;
} // fim mediaIdade()