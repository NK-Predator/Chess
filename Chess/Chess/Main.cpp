#include <iostream>
#include <string>
#include <locale.h>
#include <list>
#include <stdlib.h>
#include <vector>
#include <time.h>

char taulell[8][8];

void createTaulell() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i > 1 && i < 6) {
				taulell[i][j] = '*';
			}
			else {
				taulell[i][j] = ' ';
			}
		}
		std::cout << std::endl;
	}
}

void printTaulell() {
	std::cout << "  1 2 3 4 5 6 7 8\n";
	for (int i = 0; i < 8; ++i) {
		std::cout << 8 - i << ' ';          
		for (int j = 0; j < 8; ++j) {
			std::cout << taulell[i][j] << ' ';
		}
		std::cout << '\n';
	}

}


int main() {
	createTaulell();
	printTaulell();
	return 0;
}
