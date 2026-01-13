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