#include "pessoas/pessoas.hpp"
#include "data/data.hpp"
#include "aluno/aluno.hpp"
#include "professor/professor.hpp"

// Main
int main(){
    Pessoa* pessoas[MAX];
    inicializacao(pessoas); // Inicialização do sistema
    
// g++ main.cpp pessoas/pessoas.cpp data/data.cpp professor/professor.cpp aluno/aluno.cpp -o run

    int opcao, subOpcao, mes;
    string temp;
    Data hoje = dataAtual();

    do{
        system("cls");
        cout << "= Menu =" << endl
             << endl << "0 - Sair"
             << endl << "1 - Cadastrar pessoas"
             << endl << "2 - Listar pessoas"
             << endl << "3 - Pesquisar pessoa por nome"
             << endl << "4 - Pesquisar pessoa por CPF"
             << endl << "5 - Excluir pessoa especifica"
             << endl << "6 - Excluir todas as pessoas cadastradas"
             << endl << "7 - Aniversariante do mes"
             << endl << endl << "Opcao: ";

        cin >> opcao;
        cin.ignore();

        switch(opcao){
            case -1: cout << endl << "= DEBUG =" << endl
                          << Pessoa::TAM << endl
                          << hoje.getDia() << "/" << hoje.getMes() << "/" << hoje.getAno() << endl
                          << endl;
            break;
            
            case 0: system("cls");
                    finalizacao(pessoas);
                break;

            case 1: system("cls");
            
            cout << "= Cadastro de pessoas =" << endl
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Cadastrar professor"
                 << endl << "2 - Cadastrar aluno"
                 << endl << endl << "Opcao: ";
                cin >> subOpcao;
                cin.ignore();
            
            switch (subOpcao){
                case 0:
                    break;

                case 1:
                    if (Pessoa::TAM >= MAX){
                        cout << "Limite maximo de pessoas atingido!" << endl;
                        break;
                    }
                    pessoas[Pessoa::TAM] = new Professor();
                    pessoas[Pessoa::TAM]->leiaPessoa();
                    cout << pessoas[Pessoa::TAM]->getNome() << endl;

                    Pessoa::TAM++;
                    break;

                case 2:
                    if (Pessoa::TAM >= MAX){
                        cout << "Limite maximo de pessoas atingido!" << endl;
                        break;
                    }
                    pessoas[Pessoa::TAM] = new Aluno();
                    pessoas[Pessoa::TAM]->leiaPessoa();
                    cout << pessoas[Pessoa::TAM]->getNome() << endl;

                    Pessoa::TAM++;
                break;

                default:
                    break;
            }

            break;
            
            case 2: system("cls");
            
            cout << "= Listar pessoas =" << endl
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Listar Professor"
                 << endl << "2 - Listar Aluno"
                 << endl << endl << "Opcao: ";
            cin >> subOpcao;   
            cin.ignore();

            switch (subOpcao){
                case 0:
                    break;

                case 1:
                    listaProfessores(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;
                    
                case 2:
                    listaAlunos(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                break;
                    
                default:
                    break;
            }
            
            break;
            
            case 3: system("cls");
            
            cout << "= Pesquisa por nome =" << endl
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Pesquisar Professores por nome"
                 << endl << "2 - Pesquisar Alunos por nome"
                 << endl << endl << "Opcao: ";
            cin >> subOpcao;
            cin.ignore();
            
            switch (subOpcao){
                case 0:
                    break;
                
                case 1:
                    pesquisaProfessorNome(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;
                
                case 2:
                    pesquisaAlunoNome(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                default:
                    break;
            }
                
            break;
                
            case 4: system("cls");

            cout << "= Pesquisar por CPF =" << endl
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Pesquisar Professores por CPF"
                 << endl << "2 - Pesquisar Alunos por CPF"
                 << endl << endl << "Opcao: ";
            cin >> subOpcao;
            cin.ignore();
                
            switch (subOpcao){
                case 0:
                    break;
                    
                case 1:
                    pesquisaProfessorCPF(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                case 2:
                    pesquisaAlunoCPF(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                default:
                    break;
            }

            break;

            case 5: system("cls");

            cout << "= Excluir pessoas =" << endl 
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Excluir Professor (pelo CPF)"
                 << endl << "2 - Excluir Aluno (pelo CPF)"
                 << endl << endl << "Opcao: ";
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao){
                case 0:
                    break;

                case 1:
                    apagarProfessor(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                case 2:
                    apagarAluno(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                default:
                    break;
            }

            break;
            
            case 6: system("cls");
            
            cout << "= Excluir todas as pessoas =" << endl
                 << endl << "0 - Voltar ao menu inicial"
                 << endl << "1 - Excluir todos os Professores"
                 << endl << "2 - Excluir todos os Alunos"
                 << endl << endl << "Opcao: ";
            cin >> subOpcao;
            cin.ignore();

            switch (subOpcao){
                case 0:
                    break;

                case 1:
                    apagarTodosProfessores(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                case 2:
                    apagarTodosAlunos(pessoas);
                    cout << endl << "Pressione 'Enter' para continuar...";
                    cin.get();
                    break;

                default:
                    break;
            }

            break;

        case 7:
            do{
                system("cls");

                cout << "= Aniversariantes do mes =" << endl 
                     << endl << "0 - Voltar ao menu inicial"
                     << endl << "1 - Informar o mes a ser pesquisado"
                     << endl << "2 - Listar os professores aniversariantes do mes"
                     << endl << "3 - Listar os alunos aniversariantes do mes"
                     << endl << endl << "Opcao: ";
                cin >> subOpcao;
                cin.ignore();

                switch (subOpcao){
                    case 0:
                        break;

                    case 1:
                        cout << endl << "Mes a ser pesquisado (01 a 12): ";
                        cin >> mes;
                        cin.ignore();

                        break;
                        
                    case 2:
                        if(mes == 0){
                            cout << endl << "Mes a ser pesquisado (01 a 12): ";
                            cin >> mes;
                            cin.ignore();
                        }
                        
                        listarProfessoresAniversariantes(pessoas, mes);

                        cout << endl << "Pressione 'Enter' para continuar...";
                        cin.get();
                        mes = 0;
                        break;
                        
                    case 3:
                        if(mes == 0){
                            cout << endl << "Mes a ser pesquisado (01 a 12): ";
                            cin >> mes;
                            cin.ignore();
                        }
                        
                        listarAlunosAniversariantes(pessoas, mes);
                    
                        cout << endl << "Pressione 'Enter' para continuar...";    
                        cin.get();
                        mes = 0;
                        break;

                    default:
                        break;
                }
            } while (subOpcao != 0);
            
            break;
            
            default: cout << endl << "Opcao invalida. Tente novamente.";
        }
    } while(opcao != 0);

    return 0;
} // fim main()