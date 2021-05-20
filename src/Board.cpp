/**
 * \file Board.cpp
 * \author Justin Prez, prezj
 * \date 2019/04/08
 * \brief This module defines the board simulating Conway's Game of Life.
*/

//Libraries
#include "../include/Board.h"
#include <stdexcept>
#include <fstream>

/**
 * \brief BoardT Constructor method that creates the board from a text file.
 * \param filename - string representing the name of the text file that holds the requried information.
 * \return self.
 * \throw out_of_range - if the size values indicated in the first line of the text file are incorrect.
 * \throw invalid_argument - if the filename string does not correspond to an existing text file.
*/
BoardT :: BoardT(std :: string filename) {
	std::ifstream inFile;
	inFile.open(filename);

	if (inFile.is_open()) {
		inFile >> rows >> columns;
		
		int x;
		nat size = rows * columns;
		for (nat i = 0; i < size; i++) {
			if (!(inFile >> x)) {
				throw std::out_of_range("Incorrect number of columns and rows specified");
			}
			grid.push_back(x);
		}
		inFile.close();
	}
	else
		throw std::invalid_argument("Input file name does not exist");

}

/**
 * \brief Updates the grid to the next generation obeying the rules of Conway's Game of Life (found at https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).
*/
void BoardT :: next_generation() {
	std::vector<nat> next = grid;

	for (nat i = 0; i < rows; i++) {
		for (nat j = 0; j < columns; j++) {
			int neighbors = count_neighbors(j, i);
			int state = grid.at(i * columns + j);

			if (state == 0 && neighbors == 3) {
				next.at(i * columns + j) = 1;
			}
			else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
				next.at(i * columns + j) = 0;
			}
			else {
				next.at(i * columns + j) = grid.at(i * columns + j);	
			}
		}
	}
	grid = next;
}

/**
 * \brief Accessor method to get the current grid state.
 * \return grid - current grid state as a vector of integers (0s and 1s).
 */
std::vector<nat>  BoardT :: get_grid() {
	return grid;
}

/**
 * \brief Accessor method to get the number of rows.
 * \return rows - number of rows.
 */
nat BoardT :: get_rows() {
	return rows;
}

/**
 * \brief Accessor method to get the number of columns.
 * \return columns - number of columns.
 */
nat BoardT :: get_columns() {
	return columns;
}

/**
 * \brief Method to count the number of live neighbors for a given cell.
 * \param x - integer value representing the current figurative x position of the cell in the grid.
 * \param y - integer value representing the current figurative y position of the cell in the grid.
 * \return count - the number of live neighbors of the given cell.
 */
nat BoardT :: count_neighbors(nat x, nat y) {
	nat count = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j ++) {
			int col = (x + i + columns) % columns;
			int row = (y + j + rows) % rows;
			count += grid.at(col + row * columns);
		}
	}
	count -= grid.at(x + y * columns);
	return count;
}