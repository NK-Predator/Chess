#include "Regles.hpp"
#include <iostream>

//Es comprova si la casella està buida.
bool esBuida(char p) {
    if (p == CASELLA_BUIDA) {
        return true;
    }
    return false;
}

//Es comprova si la casella és blanca.
bool esBlanca(char p) {
    if (p >= 'A') {
        if (p <= 'Z') {
            return true;
        }
    }
    return false;
}

//Es comprova si la casella és negre.
bool esNegra(char p) {
    if (p >= 'a') {
        if (p <= 'z') {
            return true;
        }
    }
    return false;
}

//Es comprova si la posició es troba dintre del tauler.
bool dintreTauler(int fila, int col) {
    if (fila < 0) return false;
    if (fila >= MIDA_TAULER) return false;
    if (col < 0) return false;
    if (col >= MIDA_TAULER) return false;
    return true;
}

//Comprova si c ccorrespon a una peça del jugador blanc i sino es negre.
bool pecaDelJugador(char c, Jugador j) {
    if (j.color == BLANC) {
        return esBlanca(c);
    }
    else {
        return esNegra(c);
    }
}

//Converteix les peces en minúscula a majúscula per obtenir només el tipus de peça independentment del color.
char tipusPeca(char c) {
    if (c >= 'a') {
        if (c <= 'z') {
            return (char)(c - 'a' + 'A');
        }
    }
    return c;
}

//Aquesta funció valida el moviment de una peça de un lloc a un altre tenint en compte quin tipus de figura és, el color de la peça,
// límits de tauler i el camí lliure per les peçes de torre, alfil i reinaS. 
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
    
  // PECES AMB CAMÍ (TORRE, ALFIL, REINA)
    if (tipus == TORRE_B || tipus == ALFIL_B || tipus == REINA_B) {
        distanciaAbsFila = distaciaFila; if (distanciaAbsFila < 0) distanciaAbsFila = -distanciaAbsFila;
        distanciaAbsColumna = distanciaCol; if (distanciaAbsColumna < 0) distanciaAbsColumna = -distanciaAbsColumna;

        bool recta = false;
        if (filaOrigen == filaDesti) recta = true;
        if (colOrigen == colDesti) recta = true;

        bool diagonal = false;
        if (distanciaAbsFila == distanciaAbsColumna) diagonal = true;

        if (tipus == TORRE_B) { if (recta == false) return false; }
        if (tipus == ALFIL_B) { if (diagonal == false) return false; }
        if (tipus == REINA_B) {
            if (recta == false) {
                if (diagonal == false) return false;
            }
        }

        pasVertical = 0;
        if (filaDesti > filaOrigen) pasVertical = 1;
        else if (filaDesti < filaOrigen) pasVertical = -1;

        pasHoritzontal = 0;
        if (colDesti > colOrigen) pasHoritzontal = 1;
        else if (colDesti < colOrigen) pasHoritzontal = -1;

        filaActual = filaOrigen + pasVertical;
        columnaActual = colOrigen + pasHoritzontal;
        while (filaActual != filaDesti || columnaActual != colDesti) {
            if (esBuida(tauler[filaActual][columnaActual]) == false) return false;
            filaActual = filaActual + pasVertical;
            columnaActual = columnaActual + pasHoritzontal;
        }
        return true;
    }

    if (tipus == CAVALL_B) {
        distanciaAbsFila = distaciaFila; if (distanciaAbsFila < 0) distanciaAbsFila = -distanciaAbsFila;
        distanciaAbsColumna = distanciaCol; if (distanciaAbsColumna < 0) distanciaAbsColumna = -distanciaAbsColumna;
        int producte = distanciaAbsFila * distanciaAbsColumna;
        if (producte == 2) return true;
        return false;
    }

    if (tipus == REI_B) {
        distanciaAbsFila = distaciaFila; if (distanciaAbsFila < 0) distanciaAbsFila = -distanciaAbsFila;
        distanciaAbsColumna = distanciaCol; if (distanciaAbsColumna < 0) distanciaAbsColumna = -distanciaAbsColumna;
        if (distanciaAbsFila <= 1) {
            if (distanciaAbsColumna <= 1) return true;
        }
        return false;
    }
    return false;
}

//S'actulitza el tauler en funció del moviment de la peça de origen a destí deixant l'origen com a casella buida.
void mourePecaTauler(char tauler[MIDA_TAULER][MIDA_TAULER], int filaOrigen, int colOrigen, int filaDesti, int colDesti) {
    tauler[filaDesti][colDesti] = tauler[filaOrigen][colOrigen];
    tauler[filaOrigen][colOrigen] = CASELLA_BUIDA;
}