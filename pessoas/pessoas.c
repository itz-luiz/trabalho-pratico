#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pessoas.h"
#include "../data/data.h"

// Variaveis globais
int TAM = 0;

// Funções
void inicializacao(Pessoa pessoas[]){
    printf(
        "\n= Trabalho Pratico ="
        "\nLuiz Felipe Volpe P. Brandao\n"
    );
    TAM = tamanho();
    carregaPessoasArquivo(pessoas);
}

int tamanho(){
    FILE* tamanhoArq = fopen("tamanho.dat", "r");

    if(tamanhoArq == NULL){
        tamanhoArq = fopen("tamanho.dat", "w");
        TAM = 0;
        fprintf(tamanhoArq, "%d", TAM);
    } else{
        fscanf(tamanhoArq, "%d", &TAM);
    }
    
    return TAM;
}

void carregaPessoasArquivo(Pessoa pessoas[]){
    FILE* arquivo = fopen("pessoas.dat", "rb");
    if(arquivo){
        fread(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
} // fim carregaPessoasArquivo()

void gravaPessoasArquivo(Pessoa pessoas[]){
    FILE* arquivo = fopen("pessoas.dat", "wb");
    if(arquivo){
        fwrite(pessoas, sizeof(Pessoa), TAM, arquivo);
        fclose(arquivo);
    }
} // fim carregaPessoasArquivo()

void gravaTamanhoArquivo(){
    FILE* tamanho = fopen("tamanho.dat", "w");
    if(tamanho){
        fprintf(tamanho, "%d", TAM);
    }
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
        printf("\n%0d/%0d/%0d",
            pessoas[i].nascimento.dia,
            pessoas[i].nascimento.mes,
            pessoas[i].nascimento.ano
        );
        // printf("\n%d", calcIdade(pessoas, i));
        printf("\n");
    }
} // fim listaPessoa()

float mediaIdade(Pessoa pessoas[]){
    float soma = 0;

    for(int i=0; i<TAM; i++){
        soma += calcIdade(pessoas[i].nascimento);
    }

    return soma/TAM;
} // fim mediaIdade()