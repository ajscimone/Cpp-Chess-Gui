#include <iostream>
#include "Board.hpp"

// Constructor
Board::Board()
{
	// TODO: This is just a proposal of how the constructor for this class might be used. The two choices, as I see them,
	//  would be to either assign the pieces their starting positions and colors in this constructor or to have a separate
	//  function which initializes these things which is then called from the Board constructor or from the game class.
	squares = {};
	Piece p{};
	p.setColor(WHITE);
	p.setType(KING);
	Board::setPiece("e1", p);
}


// Print board
void Board::printBoard()
{
	for (int i = 0; i < squares.size(); ++i)
	{
		if (i % 8 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
		std::cout << squares[i].getPiece() << " ";
	}
}

/* Treats the passed string as algebraic chess coordinates ("a1" or "e7") and then uses the integer values of chars and
 * digits to convert the coordinates to the appropriate position in the the squares array. A map would probably be more
 * straightforward than what I've written here, but this is more concise and serves our purposes for now. */
int Board::coordsToElement(const std::string &coords)
{
	char col = coords[0];
	char row = coords[1];
	col -= 41; // convert from ASCII letter
	row -= 49; // convert from ASCII number
	int element = col - (row * 8);
	return element;
}

/* Uses the integer values of chars and digits to convert the element position to the appropriate algebraic chess
 * notation ("a1" or "e7"). A map would probably be more straightforward than what I've written here, but this is more
 * concise and serves our purposes for now. */
std::string Board::elementToCoords(int element)
{
	auto col = static_cast<char>((element % 8) + 97);   // convert integer to ASCII letter
	auto row = static_cast<char>(56 - (element / 8));   // convert integer to ASCII digit
	std::string coords = std::string() + col + row;     // form string from chars
	return coords;
}

/* Converts the given coordinates to an element and then places the given piece at that element. */
void Board::setPiece(const std::string &coords, Piece piece)
{
	int element = coordsToElement(coords);
	squares[element].setPiece(piece);
}

/* Returns the piece at a given square. */
Piece Board::getPiece(const std::string &coords)
{
	int element = coordsToElement(coords);
	return squares[element].getPiece();
}

void Board::setBoard()
{
	//White Rook Placement
	Piece wr1{ ROOK, WHITE };
	Board::setPiece("a1", wr1);

	//White Knight Placement
	Piece wn1{ KNIGHT , WHITE };
	Board::setPiece("b1", wn1);

	//White Bishop Placement
	Piece wb1{ BISHOP , WHITE };
	Board::setPiece("c1", wb1);

	//White King Placement
	Piece wk{ KING , WHITE };
	Board::setPiece("d1", wk);

	//White Queen Placement
	Piece wq{ QUEEN ,WHITE };
	Board::setPiece("e1", wq);

	//White Bishop Placement
	Piece wb2{ BISHOP , WHITE };
	Board::setPiece("f1", wb2);

	//White Knight Placement
	Piece wn2{ KNIGHT, WHITE };
	Board::setPiece("g1", wn2);

	//White Rook Placement
	Piece wr2{ ROOK , WHITE };
	Board::setPiece("h1", wr2);

	//White Pawn Placement
	Piece wp1{ PAWN , WHITE };
	Board::setPiece("a2", wp1);
	Piece wp2{ PAWN , WHITE };
	Board::setPiece("b2", wp2);
	Piece wp3{ PAWN , WHITE };
	Board::setPiece("c2", wp3);
	Piece wp4{ PAWN , WHITE };
	Board::setPiece("d2", wp4);
	Piece wp5{ PAWN , WHITE };
	Board::setPiece("e2", wp5);
	Piece wp6{ PAWN , WHITE };
	Board::setPiece("f2", wp6);
	Piece wp7{ PAWN , WHITE };
	Board::setPiece("g2", wp7);
	Piece wp8{ PAWN , WHITE };
	Board::setPiece("h2", wp8);

	//Black Rook Placement
	Piece br1{ ROOK , BLACK };
	Board::setPiece("a8", br1);

	//Black Knight Placement
	Piece bn1{ KNIGHT , BLACK };
	Board::setPiece("b8", bn1);

	//Black Bishop Placement
	Piece bb1{ BISHOP , BLACK };
	Board::setPiece("c8", bb1);

	//Black King Placement
	Piece bk{ KING , BLACK };
	Board::setPiece("d8", bk);

	//Black Queen Placement
	Piece bq{ QUEEN , BLACK };
	Board::setPiece("e8", bq);

	//Black Bishop Placement
	Piece bb2{ BISHOP , BLACK };
	Board::setPiece("f8", bb2);

	//Black Knight Placement
	Piece bn2{ KNIGHT , BLACK };
	Board::setPiece("g8", bn2);

	//Black Rook Placement
	Piece br2{ ROOK , BLACK };
	Board::setPiece("h8", br2);

	//Black Pawn Placement
	Piece bp1{ PAWN , BLACK };
	Board::setPiece("a7", bp1);
	Piece bp2{ PAWN , BLACK };
	Board::setPiece("b7", bp2);
	Piece bp3{ PAWN , BLACK };
	Board::setPiece("c7", bp3);
	Piece bp4{ PAWN , BLACK };
	Board::setPiece("d7", bp4);
	Piece bp5{ PAWN , BLACK };
	Board::setPiece("e7", bp5);
	Piece bp6{ PAWN , BLACK };
	Board::setPiece("f7", bp6);
	Piece bp7{ PAWN , BLACK };
	Board::setPiece("g7", bp7);
	Piece bp8{ PAWN , BLACK };
	Board::setPiece("h7", bp8);
}

// Destructor
Board::~Board() = default;