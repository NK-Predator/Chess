#pragma once
#include "Definicions.hpp"
/* Revisa les files extremes del tauler per si un peó ha arribat al final.
   Si un peó blanc arriba a la fila 0 o un de negre a la fila 7, es transforma en Reina. */
void promocionarSiCal(char tauler[MIDA_TAULER][MIDA_TAULER]);

/* Recorre tot el tauler buscant si la peça del Rei d'un jugador concret encara hi és.
   Retorna cert si el troba i fals si el Rei ha estat capturat. */
bool existeixRei(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j);

/* Comprova si el Rei del jugador està amenaçat per alguna peça del rival.
   Primer localitza el Rei i després mira si qualsevol peça enemiga pot moure's fins a la seva posició. */
bool estaEnJaque(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador j);

/* Determina si el jugador defensor ha perdut la partida.
   Si està en escac, prova TOTS els moviments possibles amb TOTES les seves peces.
   Si troba un moviment que el tregui de l'escac, retorna fals. Si no, és mat (cert). */
bool esJaqueMate(char tauler[MIDA_TAULER][MIDA_TAULER], Jugador defensor);


   /* Copia exactament l'estat d'un tauler a un altre. 
   S'utilitza per fer una especie de simulacions de moviments sense alterar la partida real. */
void copiarTauler(char origen[MIDA_TAULER][MIDA_TAULER], char desti[MIDA_TAULER][MIDA_TAULER]);