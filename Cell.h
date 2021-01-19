#pragma once
// INCLUDES
#include <SFML/Graphics.hpp>
#include "Life.h"

class Cell
{
public:
	int cellstate = 0;
	sf::RectangleShape cellshape;
	Cell();
	// Functions
	void drawCell(sf::RenderWindow& window);
	void onClick();
	int neighbors = 0;
	void tickCell();
};

