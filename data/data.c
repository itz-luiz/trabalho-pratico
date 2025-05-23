#include <stdio.h>
#include <time.h>
#include "../tipos.h"
#include "data.h"
#include "../pessoas/pessoas.h"

Data dataAtual(){
    Data hoje = {0};
    // Receber o tempo atual
    time_t t = time(NULL);
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t); // Converter para o fuso horário local

    hoje.dia = tm_info->tm_mday;
    hoje.mes = tm_info->tm_mon + 1; 
    hoje.ano = tm_info->tm_year + 1900;

    // printf("Today is: %02d/%02d/%04d\n", hoje.dia, hoje.mes, hoje.ano);
    
    return hoje;
} // fim dataAtual()

int calcIdade(Pessoa pessoas[], int n){
    int idade;
    Data hoje = dataAtual();
        
    idade = hoje.ano - pessoas[n].nascimento.ano;

    if(hoje.mes < pessoas[n].nascimento.mes){
        idade--;
    } else if(hoje.mes == pessoas[n].nascimento.mes && hoje.dia < pessoas[n].nascimento.dia){
        idade--;
    }

    return idade;
} // fim calcIdade()