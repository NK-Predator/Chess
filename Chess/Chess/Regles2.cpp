#include "Regles2.hpp"
#include "Regles.hpp"
#include <iostream>

void promocionarSiCal(char tauler[MIDA_TAULER][MIDA_TAULER]) {
    int c;
    for (c = 0; c < MIDA_TAULER; c = c + 1) {
        if (tauler[0][c] == PEO_B) {
            tauler[0][c] = REINA_B;
        }
        if (tauler[7][c] == PEO_N) {
            tauler[7][c] = REINA_N;
        }
    }
}

bool existeixRei(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j) {
    char k;
    int f, c;
    if (j.color == BLANC) {
        k = REI_B;
    }
    else {
        k = REI_N;
    }

    for (f = 0; f < MIDA_TAULER; f = f + 1) {
        for (c = 0; c < MIDA_TAULER; c = c + 1) {
            if (tauler[f][c] == k) {
                return true;
            }
        }
    }
    return false;
}

bool estaEnJaque(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j) {
    int filaRei = -1;
    int colRei = -1;
    int fila, columna;
    char pecaReiBuscada;
    Jugador rival;

    if (j.color == BLANC) {
        pecaReiBuscada = REI_B;
        rival.color = NEGRE;
    }
    else {
        pecaReiBuscada = REI_N;
        rival.color = BLANC;
    }

    for (fila = 0; fila < MIDA_TAULER; fila = fila + 1) {
        for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
            if (tauler[fila][columna] == pecaReiBuscada) {
                filaRei = fila;
                colRei = columna;
            }
        }
    }
    
 if (filaRei == -1) return false;

     for (fila = 0; fila < MIDA_TAULER; fila = fila + 1) {
        for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
        }
    }
//Falta continuar, pensant com fer aquesta merda