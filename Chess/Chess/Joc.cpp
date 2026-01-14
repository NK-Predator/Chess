#include "Taulell.hpp"
#include "Regles.hpp"
#include "Regles2.hpp"
#include <iostream>
#include <string>

void jugarPartida() {
    char tauler[MIDA_TAULER][MIDA_TAULER];
    Jugador jugadorBlanc, jugadorNegre, jugadorActual, jugadorDefensor;
    bool esTornBlancs = true;
    std::string nomEntrat;

    inicialitzarTauler(tauler);

    // Configuració de jugadors
    std::cout << "Nom jugador blanques: ";
    std::getline(std::cin, nomEntrat);
    if (nomEntrat.empty()) {
        jugadorBlanc.nom = "Blanques";
    }
    else {
        jugadorBlanc.nom = nomEntrat;
    }
    jugadorBlanc.color = BLANC;

    std::cout << "Nom jugador negres: ";
    std::getline(std::cin, nomEntrat);
    if (nomEntrat.empty()) {
        jugadorNegre.nom = "Negres";
    }
    else {
        jugadorNegre.nom = nomEntrat;
    }
    jugadorNegre.color = NEGRE;


    while (true) {

        if (esTornBlancs) {
            jugadorActual = jugadorBlanc;
            jugadorDefensor = jugadorNegre;
        }
        else {
            jugadorActual = jugadorNegre;
            jugadorDefensor = jugadorBlanc;
        }


        imprimirTauler(tauler);


        bool movimentFet = false;
        int filaOrigen, colOrigen, filaDesti, colDesti;

        while (!movimentFet) {
            std::cout << "Torn de " << jugadorActual.nom;
            if (jugadorActual.color == BLANC) {
                std::cout << " (blanques)";
            }
            else {
                std::cout << " (negres)";
            }
            std::cout << std::endl;

            std::cout << "Introdueix origen (fila columna) i desti (fila columna): ";

            if (!(std::cin >> filaOrigen >> colOrigen >> filaDesti >> colDesti)) {
                std::cout << "Entrada invalida. Posa numeros." << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            // Validar si el moviment és possible segons la peça
            if (movimentValidTauler(tauler, jugadorActual, filaOrigen, colOrigen, filaDesti, colDesti)) {
                char taulerCopia[MIDA_TAULER][MIDA_TAULER];
                copiarTauler(tauler, taulerCopia);
                mourePecaTauler(taulerCopia, filaOrigen, colOrigen, filaDesti, colDesti);

                // Validar que el moviment no ens deixi en escac
                if (!estaEnJaque(taulerCopia, jugadorActual)) {
                    mourePecaTauler(tauler, filaOrigen, colOrigen, filaDesti, colDesti);
                    movimentFet = true;
                }
                else {
                    std::cout << "Moviment ilegal: El teu rei queda en perill!" << std::endl;
                }
            }
            else {
                std::cout << "Aquest moviment no segueix les regles de la peça." << std::endl;
            }
        }

        promocionarSiCal(tauler);

      if (esJaqueMate(tauler, jugadorDefensor)) {
          imprimirTauler(tauler);
          std::cout << "ESCAC I MAT! Guanya " << jugadorActual.nom << "!" << std::endl;
          break;
      }

      if (!existeixRei(tauler, jugadorDefensor)) {
          std::cout << "El rei de " << jugadorDefensor.nom << " ha estat capturat!" << std::endl;
          break;
      }


        esTornBlancs = !esTornBlancs;
    }
}