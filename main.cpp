#include <iostream>
#include "headers/Utilitarios.h"
#include "headers/ArqBinario.h"

using namespace std;

void acao1(){}
void acao2(){}

void acao4(){}

int main(){
    string nomeArq;
    cout << "Entre com o nome da base de dados (binario): ";
    cin >> nomeArq;

    Binario arqBinario(nomeArq);


    if (arqBinario.verIntegridade()){
        cout << "O arquivo nao pode ser encontrado ou sua integridade esta comprometida." << endl;
        cout << "--- FINALIZANDO ---" << endl;
        exit(EXIT_FAILURE);
    }

    string opcao;
    do{
        try {
            imprimirMenu();
            cin >> opcao;
            switch (opcao[0]){
                case '1':
                    acao1();
                    break;
                case '2':
                    acao2();
                    break;
                case '3':
                    break;
                case '4':
                    acao4();
                    break;
                case '5':
                    int pos;
                    cout << "Informe a posicao inserida: ";
                    cin >> pos;
                    cin.ignore();
                    arqBinario.inserirEmPosicao(pos);
                    break;

                case 'Q':
                case 'q':
                    // Caso verificado no while;
                    break;
            
                default:
                    cout << "Comando desconheccido!" << endl;
                    break;
            }
            cout << endl;
        } catch (runtime_error& e){
            cout << e.what() << endl;
        }

    } while (!(opcao[0] == 'Q' or opcao[0] == 'q'));
    

    return 0;
}