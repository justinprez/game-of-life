#include "../catch/catch.h"
#include "../include/Board.h"
#include "../include/Write.h"
#include <fstream>

void write_to_file(std::vector<nat> grid, nat rows, nat columns, std::string filename);

TEST_CASE("Tests for Write.cpp") {
	BoardT gameOfLife1("data/start.txt");

	SECTION("Tests for write_to_file") {
		write_to_file(gameOfLife1.get_grid(),gameOfLife1.get_rows(),gameOfLife1.get_columns(),"data/out2.txt");
		
		nat temp_row;
		nat temp_col;
		std::vector<nat> temp_grid;
		std::ifstream inFile;
		inFile.open("data/out2.txt");
		if (inFile.is_open()) {
			inFile >> temp_row >> temp_col;
		
			int x;
			nat size = temp_row * temp_col;
			for (nat i = 0; i < size; i++) {
				inFile >> x;
				temp_grid.push_back(x);
			}
		inFile.close();
		}
		REQUIRE(temp_col == 6);
		REQUIRE(temp_row == 5);
		std::vector<nat> check{
			0,0,0,0,0,0,
			0,0,0,0,0,0,
			1,1,0,0,0,1,
			1,0,0,0,1,1,
			0,0,0,0,0,0};
		REQUIRE(temp_grid == check);	
	}
}