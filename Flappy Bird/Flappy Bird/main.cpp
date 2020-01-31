#include <iostream>
#include "mainLoop.hpp"
#define Width 800
#define Height 600
#define Name "Flappy Bird"

int main() {
	fp::game(Width,Height,Name);
	return EXIT_SUCCESS;
}