#ifndef TIPOS_H
#define TIPOS_H

#define MAX 100
#define MAX_STR 50
#define MAX_CPF 15

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    char cpf[MAX_CPF];
    char nome[MAX_STR];
    Data nascimento;
} Pessoa;

#endif // TIPOS_H