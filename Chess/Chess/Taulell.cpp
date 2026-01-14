#include "Taulell.hpp"
#include "Definicions.hpp"
#include <iostream>

void inicialitzarTauler(char tauler[MIDA_TAULER][MIDA_TAULER]) {
    int fila;
    int columna;

    // Peces negres (fila 0)
    tauler[0][0] = TORRE_N;
    tauler[0][1] = CAVALL_N;
    tauler[0][2] = ALFIL_N;
    tauler[0][3] = REINA_N;
    tauler[0][4] = REI_N;
    tauler[0][5] = ALFIL_N;
    tauler[0][6] = CAVALL_N;
    tauler[0][7] = TORRE_N;

    // Peons negres (fila 1)
    for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
        tauler[1][columna] = PEO_N;
    }

    // Caselles buides (files 2 a 5)
    for (fila = 2; fila <= 5; fila = fila + 1) {
        for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
            tauler[fila][columna] = CASELLA_BUIDA;
        }
    }

    // Peons blancs (fila 6)
    for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
        tauler[6][columna] = PEO_B;
    }

    // Peces blanques (fila 7)
    tauler[7][0] = TORRE_B;
    tauler[7][1] = CAVALL_B;
    tauler[7][2] = ALFIL_B;
    tauler[7][3] = REINA_B;
    tauler[7][4] = REI_B;
    tauler[7][5] = ALFIL_B;
    tauler[7][6] = CAVALL_B;
    tauler[7][7] = TORRE_B;
}

void imprimirTauler(char tauler[MIDA_TAULER][MIDA_TAULER]) {
    int fila;
    int columna;

    // Imprimir números de columna
    std::cout << "  ";
    for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
        std::cout << columna << " ";
    }
    std::cout << std::endl;

    // Imprimir files
    for (fila = 0; fila < MIDA_TAULER; fila = fila + 1) {
        std::cout << fila << " ";
        for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
            std::cout << tauler[fila][columna] << " ";
        }
        std::cout << std::endl;
    }
}