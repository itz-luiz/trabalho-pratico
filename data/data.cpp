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

Data::Data(){
    dia = 0;
    mes = 0;
    ano = 0;
}

Data::Data(int Ano){
    dia = 0;
    mes = 0;
    setAno(ano);
}

Data::Data(int dia, int mes, int ano){
    setDia(dia);
    setMes(mes);
    setAno(ano);
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
Data dataAtual(){
    Data hoje;
    // Receber o tempo atual
    time_t t = time(NULL);
    struct tm *tm_info;

    tm_info = localtime(&t); // Converte para o fuso horário local

    hoje.setDia(tm_info->tm_mday);
    hoje.setMes(tm_info->tm_mon + 1); 
    hoje.setAno(tm_info->tm_year + 1900);
    
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

int diaMes(int mes, int ano){
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2){
        if(ehBissexto(ano)){
            return 29;
        } else {
            return 28;
        }
    } else {
        return diasPorMes[mes - 1];
    }
}

bool ehBissexto(int ano){
    bool bissexto = false;
    
    if (ano % 400 == 0){
        bissexto = true;
    } else if (ano % 100 != 0 && ano % 4 == 0){
        bissexto = true;
    }

    return bissexto;
}

bool dataValida(int dia, int mes){
    bool valida = true;
    if(dia < 0 || dia > 31){
        valida = false;
    } else if(mes < 0 || mes > 12){
        valida = false;
    }

    return valida;
}

string mesExtenso(int mes){
    string mesPorExtenso = " ";
    string extenso[] = {
        "Janeiro",
        "Fevereiro",
        "Marco",
        "Abril"
        "Maio",
        "Junho",
        "Julho",
        "Agosto",
        "Setembro",
        "Outubro",
        "Novembro",
        "Dezembro"
    };

    if(mes > 0 && mes < 12){
        mesPorExtenso = extenso[mes - 1];
    }

    return mesPorExtenso;
}