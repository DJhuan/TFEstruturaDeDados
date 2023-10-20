#include <iostream>
#include <fstream>

using namespace std;

struct registroDados{
    char anzsic06[6];
    char area[8];
    int year;
    int geo_count;
    int ec_count; 
};

bool converter(){
    cout << "Por favor, entre com o nome do arquivo a ser convertido: " << endl;
    string nomeArq;
    cin >> nomeArq;

    ifstream entrada;
    entrada.open(nomeArq);
    if (entrada){
        cout << "Otimo, agora escolha o nome do arquivo de saida: " << endl;
        cin >> nomeArq;
        ofstream saida;
        saida.open(nomeArq, ios::binary);

        string header;
        getline(entrada, header, '\n');

        registroDados *aux = new registroDados;
        char lixo;

        while(!entrada.eof()){
            entrada.getline(aux->anzsic06, sizeof(char[6]), ',');
            entrada.getline(aux->area, sizeof(char[8]), ',');
            entrada >> aux->year;
            entrada >> lixo;
            entrada >> aux->geo_count;
            entrada >> lixo;
            entrada >> aux->ec_count;
            entrada.ignore();

            saida.write((char *) aux, int(sizeof(registroDados)));
        }

        delete aux;
        return true;
    }

    cout << "O arquivo de entrada nao foi encontrado!" << endl;
    return false;
}

int main(int argc, char **argv){
    cout << "Bem vindo!" << endl;

    ifstream entrada;
    string nomeArq;
    char comando;
    do{
        cout << "1 - Converter arquivo.\n"
             << "Q - Sair do programa.\n";
        cout << "Comando: ";
        cin >> comando;

        if (comando == '1'){
            cout << "--||--" << endl;
            if (converter()){
                cout << "Coversao de arquivo concluída." << endl;
            } else {
                cout << "Falha na conversão de arquivo." << endl;
            }
            cout << "--||--" << endl;

        } else if (comando == 'Q'){
            // Caso checado no while;
        } else {
            cout << "Comando desconhecido." << endl << endl;
        }
    } while (comando != 'Q');

    cout << "O programa foi finalizado!" << endl;
    return 0;
}