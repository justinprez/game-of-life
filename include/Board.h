/**
 * \file Board.h
 * \author Justin Prez, prezj
 * \date 2019/04/08
 * \brief Header module that contains the template for the board simulating Conway's Game of Life.
*/

#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

//Libraries
#include <vector>
#include <string>
typedef unsigned int nat;

/**
 * \brief Template for Board type.
 */
class BoardT {
    private:
    	std::vector<nat> grid;
    	nat rows;
    	nat columns;
    	nat count_neighbors(nat x, nat y);

    public:
    	BoardT(std::string filename);
    	void next_generation();
    	std::vector<nat> get_grid();
    	nat get_rows();
    	nat get_columns();
};

#endif