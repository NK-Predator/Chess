#include "Regles.hpp"
#include <iostream>

bool esBuida(char p) {
    if (p == CASELLA_BUIDA) {
        return true;
    }
    return false;
}

bool esBlanca(char p) {
    if (p >= 'A') {
        if (p <= 'Z') {
            return true;
        }
    }
    return false;
}

bool esNegra(char p) {
    if (p >= 'a') {
        if (p <= 'z') {
            return true;
        }
    }
    return false;
}

bool dintreTauler(int fila, int col) {
    if (fila < 0) return false;
    if (fila >= MIDA_TAULER) return false;
    if (col < 0) return false;
    if (col >= MIDA_TAULER) return false;
    return true;
}

bool pecaDelJugador(char c, Jugador j) {
    if (j.color == BLANC) {
        return esBlanca(c);
    }
    else {
        return esNegra(c);
    }
}

char tipusPeca(char c) {
    if (c >= 'a') {
        if (c <= 'z') {
            return (char)(c - 'a' + 'A');
        }
    }
    return c;
}
bool movimentValidTauler(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j, int filaOrigen, int colOrigen, int filaDesti, int colDesti) {
    char origen, desti, tipus;
    int distaciaFila, distanciaCol, direccioMoviment, filaInicialPeo, filaIntermediaPeo, distanciaAbsFila, distanciaAbsColumna, pasVertical, pasHoritzontal, filaActual, columnaActual;

    if (dintreTauler(filaOrigen, colOrigen) == false) return false;
    if (dintreTauler(filaDesti, colDesti) == false) return false;

    origen = tauler[filaOrigen][colOrigen];
    desti = tauler[filaDesti][colDesti];

    if (esBuida(origen) == true) return false;
    if (pecaDelJugador(origen, j) == false) return false;
    if (pecaDelJugador(desti, j) == true) return false;

    distaciaFila = filaDesti - filaOrigen;
    distanciaCol = colDesti - colOrigen;
    tipus = tipusPeca(origen);
    // PEÓ
    if (tipus == PEO_B) {
        if (j.color == BLANC) {
            direccioMoviment = -1;
            filaInicialPeo = 6;
        }
        else {
            direccioMoviment = 1;
            filaInicialPeo = 1;
        }

        // Moviment normal 1 casella
        if (distanciaCol == 0) {
            if (distaciaFila == direccioMoviment) {
                if (esBuida(desti) == true) {
                    return true;
                }
            }
        }

        // Moviment inicial 2 caselles
        if (distanciaCol == 0) {
            int dSaltDoble = 2 * direccioMoviment;
            if (distaciaFila == dSaltDoble) {
                if (filaOrigen == filaInicialPeo) {
                    filaIntermediaPeo = filaOrigen + direccioMoviment;
                    if (esBuida(tauler[filaIntermediaPeo][colOrigen]) == true) {
                        if (esBuida(desti) == true) {
                            return true;
                        }
                    }
                }
            }
        }

        // Captura
        bool capturaDreta = (distanciaCol == 1);
        bool capturaEsquerra = (distanciaCol == -1);
        if (capturaDreta == true || capturaEsquerra == true) {
            if (distaciaFila == direccioMoviment) {
                if (esBuida(desti) == false) {
                    if (j.color == BLANC) {
                        if (esNegra(desti) == true) return true;
                    }
                    else {
                        if (esBlanca(desti) == true) return true;
                    }
                }
            }
        }
        return false;
    }
