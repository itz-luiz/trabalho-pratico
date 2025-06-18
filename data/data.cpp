#include "data.hpp"
#include "../pessoas/pessoas.hpp"

Data dataAtual(){
    Data hoje = {0};
    // Receber o tempo atual
    time_t t = time(NULL);
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t); // Converte para o fuso horário local

    hoje.dia = tm_info->tm_mday;
    hoje.mes = tm_info->tm_mon + 1; 
    hoje.ano = tm_info->tm_year + 1900;
    
    return hoje;
} // fim dataAtual()

int calcIdade(Data nascimento){
    int idade;
    Data hoje = dataAtual();
        
    idade = hoje.ano - nascimento.ano;

    if(hoje.mes < nascimento.mes){
        idade--;
    } else if(hoje.mes == nascimento.mes && hoje.dia < nascimento.dia){
        idade--;
    }

    return idade;
} // fim calcIdade()

Data leData(){
    Data nascimento;
    scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return nascimento;
}