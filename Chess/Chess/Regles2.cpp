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