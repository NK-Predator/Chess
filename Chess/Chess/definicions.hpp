#pragma once
#include <string>

// Mida i colors
const int MIDA_TAULER = 8;
enum Color { BLANC, NEGRE, CAP_COLOR };

// Estructures
struct Jugador {
    std::string nom;
    Color color;
};

// Constants de peces
const char REI_B = 'K', REINA_B = 'Q', TORRE_B = 'R', ALFIL_B = 'B', CAVALL_B = 'N', PEO_B = 'P';
const char REI_N = 'k', REINA_N = 'q', TORRE_N = 'r', ALFIL_N = 'b', CAVALL_N = 'n', PEO_N = 'p';
const char CASELLA_BUIDA = '*';