#ifndef ALUNO_HPP
#define ALUNO_HPP

// Bibliotecas
#include "../pessoas/pessoas.hpp"

class Aluno : public Pessoa{
private:
    int matricula;


public:
    void setMatricula(int matricula);
    


};

#endif // ALUNO_HPP