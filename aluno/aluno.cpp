#include "aluno.hpp"

// Funções getters e setters
string Aluno::getMatricula(){
    return matricula;
};

int Aluno::getTipo(){
    return tipo;
}

void Aluno::setMatricula(string mat){
    this->matricula = mat;
}

Aluno::Aluno(string matricula){
    setMatricula(matricula);
}

void escreveAlunoArquivo(ofstream& arquivo, Pessoa* pessoa){
    Aluno* aluno = static_cast<Aluno*>(pessoa);
    arquivo << aluno->getNome() << endl;
    arquivo << aluno->getCPF() << endl;
    arquivo << aluno->getNascimento().getDia() << endl;
    arquivo << aluno->getNascimento().getMes() << endl;
    arquivo << aluno->getNascimento().getAno() << endl;
    arquivo << aluno->getTipo() << endl;
    arquivo << aluno->getMatricula() << endl;
    arquivo << "-={x}=-" << endl; // Delimitador para separar pessoas no arquivo
}


void Aluno::leiaPessoa(){
    string nome;
    cout << endl << "Insira o nome: ";
    getline(cin, nome);
    setNome(nome);

    setCPF(leiaCPF());

    cout << endl << "Insira a data de nascimento (dd/mm/aaaa): ";
    setNascimento(leData());

    cout << endl << "Insira a matricula: ";
    string matricula;
    cin >> matricula;
    setMatricula(matricula);
}

void Aluno::escrevePessoa(){
    cout << endl << "Nome: " << getNome();
    cout << endl << "CPF: " << getCPF();
    Data nascimento = this->getNascimento();
    cout << endl << "Data de nascimento: "
         << setfill('0') << setw(2) << nascimento.getDia() << "/"
         << setfill('0') << setw(2) << nascimento.getMes() << "/"
         << nascimento.getAno();
    cout << endl << "Matricula: " << getMatricula() << endl;
}

void pesquisaAlunoNome(Pessoa* pessoas[]){
    string chave;
    cout << endl << "Digite o nome a ser encontrado: ";
    getline(cin, chave);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 1){
            if (pessoas[i]->getNome() == chave){
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0){
        cout << "Nenhum aluno encontrado com o nome '" << chave << "'." << endl;
    }
}

void pesquisaAlunoCPF(Pessoa* pessoas[]){
    string supostoCPF;
    cout << endl << "Digite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 1){
            if (pessoas[i]->getCPF() == supostoCPF){
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0){
        cout << "Nenhum aluno encontrado com o CPF '" << supostoCPF << "'." << endl;
    }
}

bool apagarAluno(Pessoa* pessoas[]){
    string cpf;
    bool sucesso = false;
    cout << endl << "CPF para excluir (000.000.000-00): ";
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 1){
            if (pessoas[i]->getCPF() == cpf){
                delete pessoas[i];
                
                for (int j = i; j < Pessoa::TAM - 1; j++){
                    pessoas[j] = pessoas[j + 1];
                }
                Pessoa::TAM--;
                cout << "Pessoa excluida com sucesso!" << endl;
                sucesso = true;
            }
        }
    }

    if(!sucesso){
        cout << endl << "CPF nao encontrado." << endl;
    }

    return sucesso;
}

void apagarTodosAlunos(Pessoa* pessoas[]){
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 1){
            delete pessoas[i];
            
            for (int j = i; j < Pessoa::TAM - 1; j++){
                pessoas[j] = pessoas[j + 1];
            }
            Pessoa::TAM--;
            i--;
        }
    }
    cout << "Alunos excluidos com sucesso!" << endl;
}

void listaAlunos(Pessoa* pessoas[]){
    if (Pessoa::TAM == 0){
        cout << "Nenhuma pessoa cadastrada." << endl;
    }
    else{
        for (int i = 0; i < Pessoa::TAM; i++){
            if (pessoas[i]->getTipo() == 1){
                pessoas[i]->escrevePessoa();
            }
        }
    }
}

void listarAlunosAniversariantes(Pessoa* pessoas[], int mes){
    for (int i = 0; i < Pessoa::TAM; i++){
        Data nascimento = pessoas[i]->getNascimento();
        int mesNiver = nascimento.getMes();
        
        if (pessoas[i]->getTipo() == 1 && mes == mesNiver){
            pessoas[i]->escrevePessoa();
        }
    }
}