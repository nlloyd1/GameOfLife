// INCLUDES
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include "Life.h"

// Cell constructor
Cell::Cell()
{
	cellshape = sf::RectangleShape(sf::Vector2f(CELLSIZE, CELLSIZE));
	cellshape.setOutlineColor(sf::Color(0, 0, 0));
	cellshape.setOutlineThickness(1.0f);
	cellstate = 0;
}

//Draw the cell
void Cell::drawCell(sf::RenderWindow& window)
{
	// If the cell is dead (0), it is white
	if (cellstate == 0) {

		cellshape.setFillColor(sf::Color(255, 255, 255));
	}
	// If the cell is alive (1), the cell is black
	else {

		cellshape.setFillColor(sf::Color(0, 0, 0));
	}
	// Draw the cell to the window
	window.draw(cellshape);
}

// When a cell is clicked, its state is switched between zero and one
void Cell::onClick()
{
	if (cellstate == 0) {
		cellstate = 1;
	}
	else {
		cellstate = 0;
	}
}
// Update cell's state once neighbors are counted
void Cell::tickCell()
{
	// If there are three neighbors, bring the cell to life
	if (neighbors == 3) {
		cellstate = 1;
	}
	// Cell dies due to underpopulation
	else if (neighbors < 2) {
		cellstate = 0;
	}
	// Cell dies due to overpopulation
	else if (neighbors > 3) {
		cellstate = 0;
	}
}



