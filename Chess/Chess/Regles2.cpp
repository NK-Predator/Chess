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
            char peçaActual = tauler[fila][columna];
            if (pecaDelJugador(peçaActual, rival) == true) {
                if (movimentValidTauler(tauler, rival, fila, columna, filaRei, colRei) == true) {
                    return true;
                }
            }
        }
    }
    return false;
}

void copiarTauler(char origen[MIDA_TAULER][MIDA_TAULER], char desti[MIDA_TAULER][MIDA_TAULER]) {
    int fila, columna;
    for (fila = 0; fila < MIDA_TAULER; fila = fila + 1) {
        for (columna = 0; columna < MIDA_TAULER; columna = columna + 1) {
            desti[fila][columna] = origen[fila][columna];
        }
    }
}


bool esJaqueMate(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador defensor) {
    if (estaEnJaque(tauler, defensor) == false) {
        return false;
    }

    char copia[MIDA_TAULER][MIDA_TAULER];
    int filOrg, colOrg, filDes, colDes;

    // Busquem totes les peces del defensor
    for (filOrg = 0; filOrg < MIDA_TAULER; filOrg = filOrg + 1) {
        for (colOrg = 0; colOrg < MIDA_TAULER; colOrg = colOrg + 1) {
            char peçaActual = tauler[filOrg][colOrg];
            if (pecaDelJugador(peçaActual, defensor) == true) {

                // Per cada peça trobada provem a mourela a qualsevol casella del tauler
                for (filDes = 0; filDes < MIDA_TAULER; filDes = filDes + 1) {
                    for (colDes = 0; colDes < MIDA_TAULER; colDes = colDes + 1) {

                        // Si el moviment és legal
                        if (movimentValidTauler(tauler, defensor, filOrg, colOrg, filDes, colDes) == true) {
                            copiarTauler(tauler, copia);
                            mourePecaTauler(copia, filOrg, colOrg, filDes, colDes);

                            // Si després de moure el Rei ja no està en jaque, no es jaque mate ja que hi ha escapatoria
                            if (estaEnJaque(copia, defensor) == false) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}