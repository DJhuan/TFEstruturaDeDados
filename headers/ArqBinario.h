#pragma once

#include <iostream>

using namespace std;

class Binario{
private:
    string nomeArq;
    bool boaIntegridade;

    int qtdRegistros();
    bool checarAmplitude(int pos1, int pos2);
    bool checarAmplitude(int pos1);
    bool atualizarIntegridade();

public:
    Binario(string nome);
    inline bool verIntegridade(){
        return boaIntegridade;
    }
    void inserirEmPosicao(int pos0);
};