#include "data.hpp"
#include "../pessoas/pessoas.hpp"

// Funções set/get
bool Data::setDia(int dia){
    if(dia >= 1 && dia <= 31){
        this->dia = dia;
        return true;
    }
    return false;
}

bool Data::setMes(int mes){
    if(mes >= 1 && mes <= 12){
        this->mes = mes;
        return true;
    }
    return false;
}

bool Data::setAno(int ano){
    if(ano > 0){
        this->ano = ano;
        return true;
    }
    return false;
}

int Data::getDia(){
    return this->dia;
}

int Data::getMes(){
    return this->mes;
}

int Data::getAno(){
    return this->ano;
}

// Funções gerais
Data Data::dataAtual(){
    Data hoje;
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

int Data::calcIdade(Data nascimento){
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
    int dia, mes, ano;
    char barra; // Para recerber a / ao escrever dd/mm/aaaa

    cin >> dia >> barra >> mes >> barra >> ano;
    nascimento.setDia(dia);
    nascimento.setMes(mes);
    nascimento.setAno(ano);

    return nascimento;
}