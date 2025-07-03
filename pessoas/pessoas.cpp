#include "pessoas.hpp"
#include "../data/data.hpp"
#include "../aluno/aluno.hpp"
#include "../professor/professor.hpp"

// Variaveis globais
int Pessoa::TAM = 0;

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

// Funções de construtores e destrutores
Pessoa::Pessoa(){
    nome = "";
    cpf = "";
}

Pessoa::Pessoa(string nome){
    this->nome = nome;
    cpf = "";
}

Pessoa::Pessoa(string nome, int dia, int mes, int ano){
    this->nome = nome;
    this->cpf = "";
    this->nascimento = Data(dia, mes, ano);
}

Pessoa::Pessoa(string nome, string cpf, int dia, int mes, int ano){
    this->nome = nome;
    this->cpf = cpf;
    this->nascimento = Data(dia, mes, ano);
}

void Pessoa::leiaPessoa(){
    cin.ignore();
    cout << endl << "Insira o nome: ";
    getline(cin, nome);
    
    cpf = leiaCPF();

    cout << "Insira a data de nascimento (dd/mm/aaaa): ";
    nascimento = leData();
}

void Pessoa::escrevePessoa(){
    cout << endl << "Nome: " << this->nome;
    cout << endl << "CPF: " << this->getCPF();
    Data nascimento = this->getNascimento();
    cout << endl << "Nascimento: "
         << setfill('0') << setw(2) << nascimento.getDia() << "/"
         << setfill('0') << setw(2) << nascimento.getMes() << "/"
         << nascimento.getAno() << endl;
}

// Funções de inicialização e finalização
void inicializacao(Pessoa* pessoas[]){
    cout << endl << "= Trabalho Pratico ="
         << endl << "Luiz Felipe Volpe Pinheiro Brandao" << endl;
    Pessoa::TAM = tamanho();
    carregaPessoasArquivo(pessoas);
}

void finalizacao(Pessoa* pessoas[]){
    cout << endl << "= Obrigado por usar o programa =" << endl << endl;

    gravaPessoasArquivo(pessoas);
    gravaTamanhoArquivo();

    for (int i = 0; i < Pessoa::TAM; i++){
        if (pessoas[i] != nullptr){
            delete pessoas[i];
        }
    }
}

int tamanho(){
    FILE* tamanhoArq = fopen("tamanho.dat", "r");

    if(tamanhoArq == NULL){
        tamanhoArq = fopen("tamanho.dat", "w");
        Pessoa::TAM = 0;
        fprintf(tamanhoArq, "%d", Pessoa::TAM);
        fclose(tamanhoArq);
    } else{
        fscanf(tamanhoArq, "%d", &Pessoa::TAM);
        fclose(tamanhoArq);
    }
    
    return Pessoa::TAM;
}

void gravaTamanhoArquivo(){
    FILE* tamanho = fopen("tamanho.dat", "w");
     if(tamanho){
        fprintf(tamanho, "%d", Pessoa::TAM);
    } 
}

// Funções gerais
string leiaCPF(){
    string cpf;
    getline(cin, cpf);
    int formatoValido = 0;
    if (cpf.length() == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-'){
        formatoValido = 1;
    }
    while (!formatoValido){
        cout << endl << "Insira o CPF (000.000.000-00): ";

        getline(cin, cpf);

        if (cpf.length() == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-'){
            formatoValido = 1;
        }
        else{
            cout << "Formato incorreto!" << endl;
        }
    }
    return cpf;
}

void carregaPessoasArquivo(Pessoa* pessoas[]){
    ifstream arquivo("pessoas.txt");
    if(arquivo.is_open()){
        for(int i=0; i<Pessoa::TAM; i++){
            lePessoasArquivo(arquivo, pessoas[i]);
        }
        arquivo.close();
    } else {
        cout << endl << "Arquivo \"pessoas.txt\" nao encontrado";
    }
} // fim carregaPessoasArquivo()

void lePessoasArquivo(ifstream& arquivo, Pessoa*& pessoa){
    string nome, cpf, dia_s, mes_s, ano_s, tipo, matricula, especializacao;
    int dia, mes, ano;
    Pessoa* nova_pessoa = nullptr;

    // Lê o nome do usuário do arquivo
    getline(arquivo, nome);
    
    // Lê o CPF do usuário do arquivo
    getline(arquivo, cpf);

    // Lê a data de nascimento do usuário do arquivo
    getline(arquivo, dia_s);
    dia = (stoi(dia_s)); // Transforma o string dia em int para salvar no tipo Data
    getline(arquivo, mes_s);
    mes = (stoi(mes_s));
    getline(arquivo, ano_s);
    ano = (stoi(ano_s));


    getline(arquivo, tipo);
    if(tipo == "1"){
        getline(arquivo, matricula);
        pessoa = new Aluno(nome, cpf, dia, mes, ano, matricula);
    }
    else if(tipo == "2"){
        getline(arquivo, especializacao);
        pessoa = new Professor(nome, cpf, dia, mes, ano, especializacao);
    }

    // Lê o delimitador entre pessoas "-={x}=-"
    // Importante para separar pessoas
    string delimitador;
    getline(arquivo, delimitador);
} // fim lePessoasArquivo()

void gravaPessoasArquivo(Pessoa* pessoas[]){
    // Abre o arquivo e escreve truncando(escreve por cima), tipo o "w" de C
    ofstream arquivo("pessoas.txt", ios::trunc);

    if(arquivo.is_open()){
        for(int i=0; i<Pessoa::TAM; i++){
            escrevePessoasArquivo(arquivo, pessoas[i]);
        }
        arquivo.close();
    } else {
        cerr << "Erro: Nao foi possivel abrir \"pessoas.txt\" para a gravacao." << endl;
    }
} // fim carregaPessoasArquivo()

void escrevePessoasArquivo(ofstream& arquivo, Pessoa* pessoa){
    if(pessoa->getTipo() == 1){
        escreveAlunoArquivo(arquivo, pessoa);
    }
    else if(pessoa->getTipo() == 2){
        escreveProfessorArquivo(arquivo, pessoa);
    }
}

// void Pessoa::escrevePessoa(){
//     cout << endl << this->nome;
//     cout << endl << this->getCPF();

//     Data nascimento = this->getNascimento();
//     cout << endl
//          << setfill('0') << setw(2) << nascimento.getDia() << "/"
//          << setfill('0') << setw(2) << nascimento.getMes() << "/"
//          << nascimento.getAno() << endl;
// }

// void cadastroPessoa(Pessoa* pessoas[]){
//     if(Pessoa::TAM >= MAX){
//         cout << endl << "Limite maximo de pessoas atingido" << endl;
//         return;
//     }

//     cin.ignore(); // Limpar o buffer
    
//     // Nome
//     cout << endl << "Insira o nome: ";
//     string nome;
//     getline(cin, nome);
//     pessoas[Pessoa::TAM].setNome(nome);
    
//     // CPF
//     cout  << "Insira o CPF (000.000.000-00): ";
//     string cpf;
//     getline(cin, cpf);
//     pessoas[Pessoa::TAM].setCPF(cpf);

//     // Nascimento
//     cout << "Insira a data de nascimento (dd/mm/aaaa): ";
//     pessoas[Pessoa::TAM].setNascimento(leData());

//     Pessoa::TAM++;
// }

void listaPessoa(Pessoa* pessoas[], int n){
    if(n>0){
        listaPessoa(pessoas, n-1);
        cout << endl << pessoas[n-1]->getNome();
        cout << endl << pessoas[n-1]->getCPF();
        
        Data nascimento = pessoas[n-1]->getNascimento();
        cout << endl 
        << setfill('0') << setw(2) << nascimento.getDia() << "/"
        << setfill('0') << setw(2) << nascimento.getMes() << "/"
        << nascimento.getAno() << endl;
    }
}

void pesquisaPessoaNome(Pessoa* pessoas[]){
    cin.ignore(); // Limpa o buffer

    string chave;
    cout << endl << "Insira o nome para pesquisa: ";
    getline(cin, chave);

    bool encontrado = pesquisaPessoaNomeRec(pessoas, chave, Pessoa::TAM);

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

bool pesquisaPessoaNomeRec(Pessoa* pessoas[], string chave, int n){
    bool encontrado = false;
    if(n>0 && !encontrado){
        if(pessoas[n-1]->getNome() == chave){
            pessoas[n-1]->escrevePessoa();
            encontrado = true;
        } else {
            encontrado = pesquisaPessoaNomeRec(pessoas, chave, n-1);
        }
    }
    return encontrado;
}

void pesquisaPessoaCPF(Pessoa* pessoas[]){
    cin.ignore(); // Limpa o buffer
    
    string chave;
    cout << endl << "Insira o cpf para pesquisa (000.000.000-00): ";
    getline(cin, chave);
    
    int i = 0;
    bool encontrado = false;
    while(!encontrado && i < Pessoa::TAM){
        if(pessoas[i]->getCPF() == chave){
            pessoas[i]->escrevePessoa();
            encontrado = true;
        }
        i++;
    }
    
    if(!encontrado){
        cout << endl << "Nenhuma pessoa com o cpf \"" << chave << "\" foi encontrada" << endl;
    }
}

bool excluirPessoa(Pessoa* pessoas[]){
    cin.ignore(); // Limpa o buffer

    string chave;
    cout << endl << "Insira o CPF da pessoa que deseja excluir (000.000.000-00): ";
    getline(cin, chave);

    for(int i=0; i < Pessoa::TAM; i++){
        if(pessoas[i]->getCPF() == chave){
            cout << endl << pessoas[i]->getNome() << " foi excluido(a)" << endl;
            for(int j=i; j < Pessoa::TAM-1; j++){
                pessoas[j] = pessoas[j + 1]; // shift -1
            }
            Pessoa::TAM--;
            return true;
        }
    }
    
    cout << endl << "Pessoa nao encontrada" << endl;
    return false;
}

void apagarTodasPessoas(Pessoa* pessoas[]){
    Pessoa::TAM = 0;
    cout << endl << "= Todas as pessoas cadastradas foram removidas =" << endl;
}