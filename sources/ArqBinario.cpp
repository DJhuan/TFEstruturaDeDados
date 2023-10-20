#include "../headers/ArqBinario.h"
#include "../headers/Utilitarios.h"
#include <fstream>
#include <exception>


Binario::Binario(string nome){
    nomeArq = "../basesDeDados/" + nome;
    boaIntegridade = atualizarIntegridade();
}

int Binario::qtdRegistros(){
    ifstream arquivo(nomeArq, ios::binary | ios::ate);
    int tamanho = arquivo.tellg() / sizeof(registroDados);
    arquivo.close();
    return tamanho;
}

bool Binario::checarAmplitude(int pos1, int pos2){
    // Retorna true se as posiçẽos escolhidas são válidas;
    int limite = qtdRegistros();
    if (pos1 != pos2){
        if (pos1 >= 0 and pos2 >= 0){
            if (pos1 < limite and pos2 < limite)
                return true;
        }
    }

    return false;
}

bool Binario::checarAmplitude(int pos1){
    // Retorna true se a posição escolhida é válida;
    int limite = qtdRegistros();
    if (pos1 >= 0){
        if (pos1 < limite)
            return true;
    }

    return false;
}

bool Binario::atualizarIntegridade(){
    ifstream entrada(nomeArq, ios::binary | ios::in | ios::out);
    if (entrada.good()){
        entrada.close();
        return true;
    } else {
        entrada.close();
        return false;
    }
}

void Binario::inserirEmPosicao(int pos){
    if (checarAmplitude(pos)){
        registroDados* novoDado = gerarDado();
        registroDados* aux = new registroDados;
        int marcadorPos = 0;
        int qtdDados = qtdRegistros();
        int qtdPredec = 0;
        int qtdSuces = 0;


        fstream arqPrincipal(nomeArq, ios::binary|ios::in);
        fstream arqPredecessor("temp/predecessor", ios::binary|fstream::out);
        fstream arqSucessor("temp/sucessor", ios::binary|fstream::out);


        // Separação dos arquivos -------------------------------------
        while (!arqPrincipal.eof() and marcadorPos < qtdDados){
            arqPrincipal.read((char *) aux, sizeof(registroDados));
            if (marcadorPos < pos){
                arqPredecessor.write((char *) aux, sizeof(registroDados));
                qtdPredec++;
            } else {
                arqSucessor.write((char *) aux, sizeof(registroDados));
                qtdSuces++;
            }
            marcadorPos++;
        }
        // -------------------------------------------------------------

        arqPrincipal.close();
        arqPredecessor.close();
        arqSucessor.close();

        arqPrincipal.open(nomeArq, ios::binary|ios::out);
        arqPredecessor.open("temp/predecessor", ios::binary|ios::in);
        arqSucessor.open("temp/sucessor", ios::binary|ios::in);

        // Reescrita dos dados ----------------------------------------
        while (qtdPredec > 0){
            arqPredecessor.read((char *) aux, sizeof(registroDados));
            arqPrincipal.write((char *) aux, sizeof(registroDados));
            qtdPredec--;
        }

        arqPrincipal.write((char *) novoDado, sizeof(registroDados));

        while (qtdSuces > 0){
            arqSucessor.read((char *) aux, sizeof(registroDados));
            arqPrincipal.write((char *) aux, sizeof(registroDados));
            qtdSuces--;
        }
        // Reescrita dos dados ----------------------------------------

        arqPrincipal.close();
        arqPredecessor.close();
        arqSucessor.close();

        remove("temp/predecessor");
        remove("temp/sucessor");


        cout << "Novo dado posicionado!\n";

    } else {
        throw runtime_error("A posicao escolhida e invalida.");
    }
}