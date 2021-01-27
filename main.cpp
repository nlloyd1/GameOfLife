// SFML Template
#include <iostream>
// Include Needed for SFML
#include <SFML/Graphics.hpp>
// Include Needed for Animations
#include <SFML/Graphics/Rect.hpp>
// Include Needed for Text
#include <SFML/Graphics/Text.hpp>
// Other includes
#include "Life.h"
#include "Cell.h"


// Ensures program will not crash if an improper coordinate set is entered
Cell& getCell(std::vector<std::vector<Cell>>& grid, int x, int y);
Cell& getCell(std::vector<std::vector<Cell>>& grid, int x, int y) {
	if (x < 0) {
		x = GRIDSIZE - 1;
	}
	if (x >= GRIDSIZE) {
		x = 0;
	}
	if (y < 0) {
		y = GRIDSIZE - 1;
	}
	if (y >= GRIDSIZE) {
		y = 0;
	}
	return grid[y][x];
}
// Check each cell's neighbor states
void tickGrid(std::vector<std::vector<Cell>> &grid);
void tickGrid(std::vector<std::vector<Cell>>& grid) {
	for (int row = 0; row < GRIDSIZE; row++) {
		for (int col = 0; col < GRIDSIZE; col++) {
			int current_neighbors = 0;
			const int offsets[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
			for (auto offset : offsets) {
				current_neighbors += getCell(grid, col + offset[0], row + offset[1]).cellstate;
			}
			grid[row][col].neighbors = current_neighbors;
		}
	}
}

/* DEFINE GAMESTATES HERE */
// GRIDSIZE and CELLSIZE variables causes error, replaced with 80 and 10 for now
int main()
{
	// Create a Window to Display Graphics, Define Size and Window Name
	sf::RenderWindow window(sf::VideoMode(GRIDSIZE * CELLSIZE, GRIDSIZE * CELLSIZE), "Conway's Game of Life");
	std::vector<std::vector<Cell>> grid(GRIDSIZE, std::vector<Cell>(GRIDSIZE, Cell()));
	bool paused = true;
	// Run the Program while the Window is Open
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// When X Button Clicked, Close Window
			if (event.type == sf::Event::Closed)
				window.close();
			// Activate cell that user clicks on
			else if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				Cell& cell = getCell(grid, mousePos.x / CELLSIZE, mousePos.y / CELLSIZE);
				cell.onClick();
			}
			// Start and stop the game using the spacebar
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				// Pause button
				if (!paused) {
					paused = true;
				}
				// Play nutton
				else if (paused) {
					paused = false;
				}
			}
			// Update game whenever it isn't paused
			while (!paused) {
				tickGrid(grid);
				for (auto& row : grid) {
					for (auto& cell : row) {
						cell.tickCell();
					}
				}
				// Check for spacebar event (game paused)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					// Pause button
					if (!paused) {
						paused = true;
					}
					// Play nutton
					else if (paused) {
						paused = false;
					}
				}
			}
		}
		// Sets grid based on GRIDSIZE and CELLSIZE
		for (int row = 0; row < GRIDSIZE; row++) {
			for (int col = 0; col < GRIDSIZE; col++) {
				grid[row][col].cellshape.setPosition(col * CELLSIZE, row * CELLSIZE);
			}
		}
		window.clear();
		// Calls the draw function for each cell
		for (auto& row : grid) {
			for (auto& cell : row) {
				cell.drawCell(window);
			}
		}
		/* DRAW OBJECTS HERE */
		window.display();
	}
}