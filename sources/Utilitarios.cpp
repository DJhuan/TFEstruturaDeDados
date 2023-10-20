#include <iostream>
#include "../headers/Utilitarios.h"

using namespace std;

registroDados* gerarDado(){
    registroDados* novoDado = new registroDados;
    cout << "+ --- + Gerando novo dado + -- +\n";

    cout << "Entre com o campo anzsic06: ";
    cin.getline((char *) novoDado->anzsic06, sizeof(char[6]), '\n');
    cout << "Agora com o campo area: ";
    cin.getline((char *) novoDado->area, sizeof(char[8]), '\n');
    cout << "Entre com o ano: ";
    cin >> novoDado->year;
    cout << "Agora com o campo geo_count: ";
    cin >> novoDado->geo_count;
    cout << "Agora com o campo ec_count: ";
    cin >> novoDado->ec_count;

    cout << "+ ------ + Dado gerado + ----- +\n";

    return novoDado;
}

void imprimirMenu(){
    cout << "+--------------------------+" << endl;
    cout << "|   Selecione um comando   |" << endl;
    cout << "+--------------------------+" << endl;
    cout << "|[1] Adicionar elemento    |" << endl;
    cout << "|[2] Modificar elemento    |" << endl;
    cout << "|[3] Alternar elementos    |" << endl;
    cout << "|[4] Vizualizar elementos  |" << endl;
    cout << "|[5] Adicionar em posicao  |" << endl;
    cout << "|[Q] Sair                  |" << endl;
    cout << "+--------------------------+" << endl;
}