#include "pessoas.hpp"
#include "../data/data.hpp"

// Variaveis globais
int TAM = 0;

// Funções para coletar/alterar os dados privados
void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setCPF(string cpf){
    this->cpf = cpf;
}

void Pessoa::setNascimento(Data nascimento){
    this->nascimento = nascimento;
}

string Pessoa::getNome(){
    return this->nome;
}

string Pessoa::getCPF(){
    return this->cpf;
}

Data Pessoa::getNascimento(){
    return this->nascimento;
}

// Funções de inicialização e finalização
void inicializacao(Pessoa pessoas[]){
    cout << endl << "= Trabalho Pratico ="
         << endl << "Luiz Felipe Volpe Pinheiro Brandao" << endl;
    TAM = tamanho();
    carregaPessoasArquivo(pessoas);
}

void finalizacao(Pessoa pessoas[]){
    cout << endl << "= Obrigado por usar o programa =" << endl;

    gravaPessoasArquivo(pessoas);
    gravaTamanhoArquivo();
}

int tamanho(){
    FILE* tamanhoArq = fopen("tamanho.dat", "r");

    if(tamanhoArq == NULL){
        tamanhoArq = fopen("tamanho.dat", "w");
        TAM = 0;
        fprintf(tamanhoArq, "%d", TAM);
        fclose(tamanhoArq);
    } else{
        fscanf(tamanhoArq, "%d", &TAM);
        fclose(tamanhoArq);
    }
    
    return TAM;
}

void gravaTamanhoArquivo(){
    FILE* tamanho = fopen("tamanho.dat", "w");
     if(tamanho){
        fprintf(tamanho, "%d", TAM);
    } 
}

// Funções gerais
void carregaPessoasArquivo(Pessoa pessoas[]){
    ifstream arquivo("pessoas.txt");
    if(arquivo.is_open()){
        for(int i=0; i<TAM; i++){
            lePessoasArquivo(arquivo, pessoas[i]);
        }
        arquivo.close();
    } else {
        cout << endl << "Arquivo \"pessoas.txt\" nao encontrado";
    }
} // fim carregaPessoasArquivo()

void lePessoasArquivo(ifstream& arquivo, Pessoa& pessoa){
    string nome, cpf, dia, mes, ano;
    Data nascimento;

    // Lê o nome do usuário do arquivo
    getline(arquivo, nome);
    pessoa.setNome(nome);
    
    // Lê o CPF do usuário do arquivo
    getline(arquivo, cpf);
    pessoa.setCPF(cpf);

    // Lê a data de nascimento do usuário do arquivo
    getline(arquivo, dia);
    nascimento.setDia(stoi(dia)); // Transforma o string dia em int para salvar no tipo Data
    getline(arquivo, mes);
    nascimento.setMes(stoi(mes));
    getline(arquivo, ano);
    nascimento.setAno(stoi(ano));

    pessoa.setNascimento(nascimento);

    // Lê o delimitador entre pessoas "-={x}=-"
    // Importante para separar pessoas
    string delimitador;
    getline(arquivo, delimitador);
} // fim lePessoasArquivo()

void gravaPessoasArquivo(Pessoa pessoas[]){
    // Abre o arquivo e escreve truncando(escreve por cima), tipo o "w" de C
    ofstream arquivo("pessoas.txt", ios::trunc);

    if(arquivo.is_open()){
        for(int i=0; i<TAM; i++){
            escrevePessoasArquivo(arquivo, pessoas[i]);
        }
        arquivo.close();
    } else {
        cerr << "Erro: Nao foi possivel abrir \"pessoas.txt\" para a gravacao." << endl;
    }
} // fim carregaPessoasArquivo()

void escrevePessoasArquivo(ofstream& arquivo, Pessoa& pessoa){
    arquivo << pessoa.getNome() << endl;
    arquivo << pessoa.getCPF() << endl;
    arquivo << pessoa.getNascimento().getDia() << endl;
    arquivo << pessoa.getNascimento().getMes() << endl;
    arquivo << pessoa.getNascimento().getAno() << endl;
    arquivo << "-={x}=-" << endl; // Delimitador para separar pessoas no arquivo
}

void Pessoa::escrevePessoa(){
    cout << endl << this->nome;
    cout << endl << this->getCPF();

    Data nascimento = this->getNascimento();
    cout << endl
         << setfill('0') << setw(2) << nascimento.getDia() << "/"
         << setfill('0') << setw(2) << nascimento.getMes() << "/"
         << nascimento.getAno() << endl;
}

void cadastroPessoa(Pessoa pessoas[]){
    if(TAM >= MAX){
        cout << endl << "Limite maximo de pessoas atingido" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpar o buffer
    
    // Nome
    cout << endl << "Insira o nome: ";
    string nome;
    getline(cin, nome);
    pessoas[TAM].setNome(nome);
    
    // CPF
    cout  << "Insira o CPF (000.000.000-00): ";
    string cpf;
    getline(cin, cpf);
    pessoas[TAM].setCPF(cpf);

    // Nascimento
    cout << "Insira a data de nascimento (dd/mm/aaaa): ";
    pessoas[TAM].setNascimento(leData());

    TAM++;
}

void listaPessoa(Pessoa pessoas[], int n){
    if(n>0){
        listaPessoa(pessoas, n-1);
        cout << endl << pessoas[n-1].getNome();
        cout << endl << pessoas[n-1].getCPF();
        
        Data nascimento = pessoas[n-1].getNascimento();
        cout << endl 
        << setfill('0') << setw(2) << nascimento.getDia() << "/"
        << setfill('0') << setw(2) << nascimento.getMes() << "/"
        << nascimento.getAno() << endl;
        
    }
}

void pesquisaPessoaNome(Pessoa pessoas[]){
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer

    string chave;
    cout << endl << "Insira o nome para pesquisa: ";
    getline(cin, chave);

    bool encontrado = pesquisaPessoaNomeRec(pessoas, chave, TAM);

    /*
     * Função iterativa substituida por recursiva
     * for(int i=0; i < TAM; i++){
     *     if(pessoas[i].getNome() == chave){
     *         pessoas[i].escrevePessoa();
     *         encontrado = true;
     *     }
     * }
    */

    if(!encontrado){
        cout << endl << "Nenhuma pessoa encontrado com o nome: " << chave << endl;
    }
}

bool pesquisaPessoaNomeRec(Pessoa pessoas[], string chave, int n){
    bool encontrado = false;
    if(n>0 && !encontrado){
        if(pessoas[n-1].getNome() == chave){
            pessoas[n-1].escrevePessoa();
            encontrado = true;
        } else {
            encontrado = pesquisaPessoaNomeRec(pessoas, chave, n-1);
        }
    }
    return encontrado;
}

void pesquisaPessoaCPF(Pessoa pessoas[]){
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
    
    string chave;
    cout << endl << "Insira o cpf para pesquisa (000.000.000-00): ";
    getline(cin, chave);
    
    bool encontrado = false;
    for(int i=0; i < TAM; i++){
        if(pessoas[i].getCPF() == chave){
            pessoas[i].escrevePessoa();
            encontrado = true;
        }
    }
    
    if(!encontrado){
        cout << endl << "Nenhuma pessoa com o cpf \"" << chave << "\" foi encontrada" << endl;
    }
}

bool excluirPessoa(Pessoa pessoas[]){
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer

    string chave;
    cout << endl << "Insira o CPF da pessoa que deseja excluir (000.000.000-00): ";
    getline(cin, chave);

    for(int i=0; i<TAM; i++){
        if(pessoas[i].getCPF() == chave){
            cout << endl << pessoas[i].getNome() << " foi excluido(a)" << endl;
            for(int j=i; j < TAM-1; j++){
                pessoas[j] = pessoas[j + 1]; // shift -1
            }
            TAM--;
            return true;
        }
    }
    
    cout << endl << "Pessoa nao encontrada" << endl;
    return false;
}

void apagarTodasPessoas(Pessoa pessoas[]){
    TAM = 0;
    cout << endl << "= Todas as pessoas cadastradas foram removidas =" << endl;
}