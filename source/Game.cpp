#include "Game.hpp"

void Game::run()
{
	std::cout << "Starting board for move testing" << std::endl;
	board.printBoard();

	std::cout << "Testing white knights" << std::endl;
	board.movePiece(std::make_pair(7,1), std::make_pair(5, 2));
	board.printBoard();
	board.movePiece(std::make_pair(5,2), std::make_pair(3, 3));
	board.printBoard();
	board.movePiece(std::make_pair(7,6), std::make_pair(5, 7));
	board.printBoard();

	std::cout << "Testing captures by white knight" << std::endl;
	board.movePiece(std::make_pair(3, 3), std::make_pair(1, 2));
	board.printBoard();
	board.movePiece(std::make_pair(1, 2), std::make_pair(0, 0));
	board.printBoard();

	std::cout << "Testing friendly capture (should fail)" << std::endl;
	board.movePiece(std::make_pair(0, 6), std::make_pair(1, 4));
	board.printBoard();

	//std::cout << "Testing King movement" << std::endl;
	//board.movePiece(std::make_pair(7, 4), std::make_pair(6, 4));
	//board.printBoard();

	//board.movePiece(std::make_pair(6, 4), std::make_pair(6, 3));
	//board.printBoard();

	//board.movePiece(std::make_pair(6, 3), std::make_pair(5, 4));
	//board.printBoard();

	//board.movePiece(std::make_pair(5, 4), std::make_pair(6, 5));
	//board.printBoard();

	//board.movePiece(std::make_pair(6, 5), std::make_pair(7, 6));
	//board.printBoard();
}