#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../source/Board.hpp"
#include "../source/Game.hpp"

TEST_CASE("Check condition with Scholar's Mate")
{
	Game game;
	Board board; 	// only used for coordinate conversions

	// Neither black nor white is in check
	REQUIRE(game.isInCheck(WHITE) == false);
	REQUIRE(game.isInCheck(BLACK) == false);

	// Neither black nor white is in checkmate
	REQUIRE(game.isInCheckMate(WHITE) == false);
	REQUIRE(game.isInCheckMate(BLACK) == false);

	// Set up a check situation (scholar's mate)
	game.move(board.algebraicToInt("e2"), board.algebraicToInt("e4"));
	game.move(board.algebraicToInt("e7"), board.algebraicToInt("e5"));
	game.move(board.algebraicToInt("f1"), board.algebraicToInt("c4"));
	game.move(board.algebraicToInt("b8"), board.algebraicToInt("c6"));
	game.move(board.algebraicToInt("d1"), board.algebraicToInt("h5"));
	game.move(board.algebraicToInt("g8"), board.algebraicToInt("f6"));
	game.move(board.algebraicToInt("h5"), board.algebraicToInt("f7"));

	// White is not in check nor checkmate
	REQUIRE(game.isInCheck(WHITE) == false);
	REQUIRE(game.isInCheckMate(WHITE) == false);

	// Black is now in check and in checkmate
	REQUIRE(game.isInCheck(BLACK) == true);
	REQUIRE(game.isInCheckMate(BLACK) == true);
}
