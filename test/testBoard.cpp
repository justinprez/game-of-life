#include "../catch/catch.h"
#include "../include/Board.h"

TEST_CASE("Tests for Board.cpp", "[BoardT]") {
	BoardT gameOfLife1("data/start.txt");
	BoardT gameOfLife2("data/still.txt");

	SECTION("Tests for accessor methods and board constructor") {
		std::vector<nat> test_grid1{
			0,0,0,0,0,0,
			0,0,0,0,0,0,
			1,1,0,0,0,1,
			1,0,0,0,1,1,
			0,0,0,0,0,0};
		std::vector<nat> test_grid2{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0};
		REQUIRE(gameOfLife1.get_grid() == test_grid1);
		REQUIRE(gameOfLife1.get_columns() == 6);
		REQUIRE(gameOfLife1.get_rows() == 5);
		REQUIRE(gameOfLife2.get_grid() == test_grid2);
		REQUIRE(gameOfLife2.get_columns() == 4);
		REQUIRE(gameOfLife2.get_rows() == 4);
	}

	SECTION("Tests board constructor exceptions") {
		REQUIRE_THROWS_AS(new BoardT("doesnotexist.txt"), std::invalid_argument);
		REQUIRE_THROWS_AS(new BoardT("data/incorrect.txt"), std::out_of_range);
	}

	SECTION("Tests for next_generation") {
		//Test Oscillator type called Toad (period of 2)
		std::vector<nat> test_grid1 {
			0,0,0,0,0,0,
			1,0,0,0,0,0,
			0,1,0,0,1,0,
			0,1,0,0,1,0,
			0,0,0,0,0,1};
		gameOfLife1.next_generation();
		REQUIRE(gameOfLife1.get_grid() == test_grid1);
		REQUIRE(gameOfLife1.get_columns() == 6);
		REQUIRE(gameOfLife1.get_rows() == 5);
		gameOfLife1.next_generation();
		std::vector<nat> test_grid1_ret	{
			0,0,0,0,0,0,
			0,0,0,0,0,0,
			1,1,0,0,0,1,
			1,0,0,0,1,1,
			0,0,0,0,0,0};
		REQUIRE(gameOfLife1.get_grid() == test_grid1_ret);
		REQUIRE(gameOfLife1.get_columns() == 6);
		REQUIRE(gameOfLife1.get_rows() == 5);

		//Test Still life
		std::vector<nat> test_grid2{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0};
		gameOfLife2.next_generation();
		REQUIRE(gameOfLife2.get_grid() == test_grid2);
		REQUIRE(gameOfLife2.get_columns() == 4);
		REQUIRE(gameOfLife2.get_rows() == 4);	
	}
}