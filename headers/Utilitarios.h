#pragma once

struct registroDados{
    char anzsic06[6];
    char area[8];
    int year;
    int geo_count;
    int ec_count; 
};

registroDados* gerarDado();

void imprimirMenu();