/**
 * \file Write.h
 * \author Justin Prez, prezj
 * \date 2019/04/08
 * \brief Header module that contains the functions used to write the board simulation to the terminal or text file.
*/

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

//Libraries
#include <vector>
#include <string>
typedef unsigned int nat;

/**
 * \brief Function to write the game board to the terminal console.
 */
void write_to_terminal(std::vector<nat> grid, nat rows, nat columns);

/**
 * \brief Function to write the game board to a specified text file.
 */
void write_to_file(std::vector<nat> grid, nat rows, nat columns, std::string filename);

#endif