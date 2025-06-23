#ifndef DATA_H
#define DATA_H

// Bibliotecas
#include <iostream>
#include <stdio.h> // Para usar scanf, fopen, fclose, etc.
#include <ctime>
#include <limits>
#include <ios>
using namespace std;

class Data{
private:
    int dia;
    int mes;
    int ano;

public:
    Data dataAtual();
    bool setDia(int dia);
    bool setMes(int mes);
    bool setAno(int ano);

    int getDia();
    int getMes();
    int getAno();

    int calcIdade(Data nascimento);
};

// Protótipo das funções
Data leData();

int diaMes(int mes);
string mesExtenso();
string diaSemana();
bool ehBissexto();
bool dataValida();

#endif // DATA_H