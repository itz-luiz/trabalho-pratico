#ifndef DATA_H
#define DATA_H

// #include "../tipos.h"

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

// Protótipo das funções
Data dataAtual();

int calcIdade(Data nascimento);

#endif // DATA_H