#include "pessoas.hpp"
#include "../data/data.hpp"

// Variaveis globais
int TAM = 0;

// Funções
void inicializacao(Pessoa pessoas[]){
    cout << endl << "= Trabalho Pratico ="
         << endl << "Luiz Felipe Volpe Pinheiro Brandao" << endl;
    TAM = tamanho();
    carregaPessoasArquivo(pessoas);
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

void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setCPF(string cpf){
    this->cpf = cpf;
}

void Pessoa::setNascimento(Data nascimento){
    this->nascimento = nascimento;
}

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
    nascimento.dia = stoi(dia); // Transforma o string dia em int para salvar no tipo Data
    getline(arquivo, mes);
    nascimento.mes = stoi(mes);
    getline(arquivo, ano);
    nascimento.ano = stoi(ano);

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

/*
 * void gravaPessoasArquivo(Pessoa pessoas[]){
 *     FILE* arquivo = fopen("pessoas.txt", "w");
 *     if(arquivo){
 *         fwrite(pessoas, sizeof(Pessoa), TAM, arquivo);
 *         fclose(arquivo);
 *     }
 * }
*/

void escrevePessoasArquivo(ofstream& arquivo, Pessoa& pessoa){
    arquivo << pessoa.getNome() << endl;
    arquivo << pessoa.getCPF() << endl;
    arquivo << pessoa.getNascimento().dia << endl;
    arquivo << pessoa.getNascimento().mes << endl;
    arquivo << pessoa.getNascimento().ano << endl;
    arquivo << "-={x}=-" << endl; // Delimitador para separar pessoas no arquivo
}

void gravaTamanhoArquivo(){
    FILE* tamanho = fopen("tamanho.dat", "w");
     if(tamanho){
        fprintf(tamanho, "%d", TAM);
    } 
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
    cout << "Insira a data de nascimento: ";
    Data nascimento;
    pessoas[TAM].setNascimento(leData());

    TAM++;
}

/*
 * void cadastroPessoa(Pessoa pessoas[]){
 *     int c;
 *     while ((c = getchar()) != '\n' && c != EOF);
 *
 *     printf("\nInsira o nome da pessoa: ");
 *     fgets(pessoas[TAM].nome, MAX_STR, stdin);
 *
 *     fflush(stdin);
 *     printf("Insira o CPF (xxx.xxx.xxx-xx): ");
 *     fgets(pessoas[TAM].cpf, MAX_CPF, stdin);
 *
 *     printf("Insira a data de nacimento da pessoa (DD/MM/AAAA): ");
 *     scanf("%d/%d/%d",
 *         &pessoas[TAM].nascimento.dia,
 *         &pessoas[TAM].nascimento.mes,
 *         &pessoas[TAM].nascimento.ano
 *     );
 *
 *     printf("\n= Pessoa cadastrada =\n");
 *
 *     TAM++;
 * } // fim cadastroPessoa()
*/

void listaPessoa(Pessoa pessoas[]){
    for(int i=0; i<TAM; i++){
        cout << i;
        cout << endl << pessoas[i].getNome();
        cout << endl << pessoas[i].getCPF();
        
        Data nascimento = pessoas[i].getNascimento();
        cout << endl 
             << setfill('0') << setw(2) << nascimento.dia << "/"
             << setfill('0') << setw(2) << nascimento.mes << "/"
             << nascimento.ano << endl;
    }
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

/*
 * void listaPessoa(Pessoa pessoas[]){
 *     for(int i=0; i<TAM; i++){
 *         printf("\n%s", pessoas[i].nome);
 *         printf("%s", pessoas[i].cpf);
 *         printf("\n%0d/%0d/%0d",
 *             pessoas[i].nascimento.dia,
 *             pessoas[i].nascimento.mes,
 *             pessoas[i].nascimento.ano
 *         );
 *         printf("\n");
 *     }
 * } // fim listaPessoa()
*/

void apagarTodasPessoas(Pessoa pessoas[]){
    TAM = 0;
    printf("\n= Todas as pessoas cadastradas foram removidas =\n");
}