#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct registroDados{
    char anzsic06[6];
    char area[8];
    int year;
    int geo_count;
    int ec_count; 
};

void imprimirRegistro(const registroDados& valores){
    cout << setfill(' ');
    cout << setw(5);
    cout << valores.anzsic06;
    cout << setw(8);
    cout << valores.area;
    cout << setw(5);
    cout << valores.year;
    cout << setw(4);
    cout << valores.geo_count;
    cout << setw(3);
    cout << valores.ec_count;
    cout << endl;
}

int main(int argc, char **argv){
    string nomeArq;
    cout << "Entre com o nome do arquivo binario: ";
    cin >> nomeArq;

    ifstream entrada(nomeArq, ios::binary);
    if (entrada.good()){
        int contador = 0;
        registroDados* aux = new registroDados;
        while (!entrada.eof()){
            entrada.read((char *) aux, sizeof(registroDados));
            cout << setw(4) << left << contador;
            imprimirRegistro(*aux);

            contador++;
        }

    } else {
        cout << "Houveram problemas na abertura do arquivo!" << endl;
    }

    return 0;
}