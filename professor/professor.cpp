#include "professor.hpp"

void Professor::setEspecializacao(string esp){
    this->especializacao = esp;
};

Professor::Professor(string esp){
    setEspecializacao(esp);
}

string Professor::getEspecializacao(){
    return especializacao;
};

void escreveProfessorArquivo(ofstream& arquivo, Pessoa* pessoa){
    Professor* professor = static_cast<Professor*>(pessoa);
    arquivo << professor->getNome() << endl;
    arquivo << professor->getCPF() << endl;
    arquivo << professor->getNascimento().getDia() << endl;
    arquivo << professor->getNascimento().getMes() << endl;
    arquivo << professor->getNascimento().getAno() << endl;
    arquivo << professor->getTipo() << endl;
    arquivo << professor->getEspecializacao() << endl;
    arquivo << "-={x}=-" << endl; // Delimitador para separar pessoas no arquivo
}

void Professor::leiaPessoa(){
    string nome;
    cout << endl << "Insira o nome: ";
    getline(cin, nome);
    setNome(nome);

    setCPF(leiaCPF());

    cout << endl << "Insira a data de nascimento: (dd/mm/aaaa)";
    setNascimento(leData());

    cout << endl << "Insira a especializacao: ";
    string especializacao;
    cin >> especializacao;
    setEspecializacao(especializacao);
}

void Professor::escrevePessoa(){
    cout << endl << "Nome: " << getNome();
    cout << endl << "CPF: " << getCPF();
    Data nascimento = this->getNascimento();
    cout << endl << "Data de nascimento: "
         << setfill('0') << setw(2) << nascimento.getDia() << "/"
         << setfill('0') << setw(2) << nascimento.getMes() << "/"
         << nascimento.getAno();
    cout << endl << "Especializacao: " << getEspecializacao() << endl;
}

void pesquisaProfessorNome(Pessoa* pessoas[]){
    string chave;
    cout << endl << "Digite o nome a ser encontrado: ";
    getline(cin, chave);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 2){
            if (pessoas[i]->getNome() == chave){
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0){
        cout << "Nenhum professor encontrado com o nome '" << chave << "'." << endl;
    }
}

void pesquisaProfessorCPF(Pessoa* pessoas[]){
    string supostoCPF;
    cout << endl << "Digite o CPF a ser encontrado (000.000.000-00): ";
    getline(cin, supostoCPF);

    int encontradas = 0;
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 2){
            if (pessoas[i]->getCPF() == supostoCPF){
                pessoas[i]->escrevePessoa();
                encontradas++;
            }
        }
    }

    if (encontradas == 0){
        cout << "Nenhum professor encontrado com o CPF '" << supostoCPF << "'." << endl;
    }
}

bool apagarProfessor(Pessoa* pessoas[]){
    string cpf;
    bool sucesso = false;
    cout << endl << "CPF para excluir (000.000.000-00): ";
    getline(cin, cpf);

    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 2){
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

void apagarTodosProfessores(Pessoa* pessoas[]){
    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i]->getTipo() == 2){
            // Delete the object from memory first
            delete pessoas[i];
            
            for (int j = i; j < Pessoa::TAM - 1; j++){
                pessoas[j] = pessoas[j + 1]; // Faz o "shift"
            }
            Pessoa::TAM--;
            i--; // Stay at the same index since we shifted
        }
    }
    cout << "Professores excluidos com sucesso!" << endl;
}

void listaProfessores(Pessoa* pessoas[]){
    if (Pessoa::TAM == 0){
        cout << "Nenhuma pessoa cadastrada." << endl;
    }
    else{
        for (int i = 0; i < Pessoa::TAM; i++){
            if (pessoas[i]->getTipo() == 2){
                pessoas[i]->escrevePessoa();
            }
        }
    }
}

void listarProfessoresAniversariantes(Pessoa* pessoas[], int mes){
    for (int i = 0; i < Pessoa::TAM; i++){
        Data nascimento = pessoas[i]->getNascimento();
        int mesNiver = nascimento.getMes();
        
        if (pessoas[i]->getTipo() == 2 && mes == mesNiver){
            pessoas[i]->escrevePessoa();
        }
    }
}