#pragma once
#include "Definicions.hpp"

void promocionarSiCal(char tauler[MIDA_TAULER][MIDA_TAULER]);
bool existeixRei(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j);
bool estaEnJaque(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j);
bool esJaqueMate(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador defensor);
void copiarTauler(char origen[MIDA_TAULER][MIDA_TAULER], char desti[MIDA_TAULER][MIDA_TAULER]);