#pragma once
#include "Definicions.hpp"

//Declaració de totes les funcions 
bool esBuida(char p);
bool esBlanca(char p);
bool esNegra(char p);
bool dintreTauler(int fila, int col);
bool pecaDelJugador(char c, Jugador j);
char tipusPeca(char c);
bool movimentValidTauler(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j, int fo, int co, int fd, int cd);
void mourePecaTauler(char tauler[MIDA_TAULER][MIDA_TAULER], int fo, int co, int fd, int cd);