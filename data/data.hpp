#ifndef DATA_H
#define DATA_H

// Bibliotecas
#include <iostream>
#include <stdio.h> // Para usar scanf, fopen, fclose, etc.
#include <ctime>
#include <limits>
#include <ios>
using namespace std;


typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

// Protótipo das funções
Data dataAtual();
Data leData();

int calcIdade(Data nascimento);

#endif // DATA_H