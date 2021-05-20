/**
 * \file Write.cpp
 * \author Justin Prez, prezj
 * \date 2019/04/08
 * \brief This module define functions used to write the current board grid to the terminal console or a text file.
*/

//Libraries
#include "../include/Write.h"
#include <stdexcept>
#include <fstream>
#include <iostream>


/**
 * \brief Function to write the game board to the terminal console.
 * \param grid - the vector of integers (0s and 1s) that represents the current grid state.
 * \param rows - the number of rows in the grid.
 * \param columns - the number of columns in the grid.
*/
void write_to_terminal(std::vector<nat> grid, nat rows, nat columns) {
	std::cout << rows << " " << columns << "\n";
	for (nat i = 0; i < rows; i++) {
		for (nat j = 0; j < columns; j++) {
			std::cout << grid.at(j + i * columns) << " ";
		}
		std::cout << "\n";
	}
}

/**
 * \brief Function to write the game board to a specified text file.
 * \param grid - the vector of integers (0s and 1s) that represents the current grid state.
 * \param rows - the number of rows in the grid.
 * \param columns - the number of columns in the grid.
 * \throw invalid_argument - error opening the outFile.
*/
void write_to_file(std::vector<nat> grid, nat rows, nat columns, std::string filename) {
	std::ofstream outFile;
	outFile.open(filename);
	if (outFile.is_open()) {
		outFile << rows << " " << columns << "\n";
		for (nat i = 0; i < rows; i++) {
			for (nat j = 0; j < columns; j++) {
				outFile << grid.at(j + i * columns) << " ";
			}
			outFile << "\n";
		}
		outFile.close();
	}
	else {
		throw std::invalid_argument("Unable to open outFile");
	}
}