#include <iostream>
#include <memory>
#include "Board.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"

/* Constructor */
Board::Board()
{
	prepSquares();
	prepPieces();
}

/* Squares are stored in a map which maps coordinates as a pair to a unique_ptr to a Square object. For example, the
 * location that corresponds to a8 in algebraic notation would be at std::pair<0,0>.*/
void Board::prepSquares()
{
	for (int i = 0; i < 8; i++)
	{

		for (int j = 0; j < 8; j++)
		{
			squares.insert(std::pair <std::pair <int, int>, std::unique_ptr<Square>> (std::make_pair(i, j), std::make_unique<Square>()));
		}
	}
}

/* Creates and places the appropriate pieces on the appropriate spots to start a game. */
void Board::prepPieces()
{
	// TODO: Fill out the rest of the pieces.

	// White pawns
	setPiece(std::make_pair(6, 0), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 1), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 2), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 3), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 4), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 5), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 6), std::make_unique<Pawn>(WHITE));
	setPiece(std::make_pair(6, 7), std::make_unique<Pawn>(WHITE));

	// Black pawns
	setPiece(std::make_pair(1, 0), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 1), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 2), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 3), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 4), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 5), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 6), std::make_unique<Pawn>(BLACK));
	setPiece(std::make_pair(1, 7), std::make_unique<Pawn>(BLACK));
}

/* Sets a piece to its appropriate location in the map. */
std::unique_ptr<Piece> Board::setPiece(const std::pair<int, int> &coords, std::unique_ptr<Piece> piece)
{
	return squares[coords]->setPiece(std::move(piece));
}

/* Returns the piece at a given square. Finds the element in the map, then returns the Square part of that element, then
 * gets the piece at that square. */
const Piece* Board::getPiece(const std::pair<int, int> &coords) const
{
	return squares.find(coords)->second->getPiece();
}

/* Print contents of board with black on top and white on bottom by creating a series of coordinates and then finding
 * the pieces at those coordinates. */
void Board::printBoard()
{
	int i = 1;
	for (auto const &[key, val] : squares)								// loop over contents of squares
	{
		const Piece* piece = squares.find(key)->second->getPiece();		// get the piece at the square
		if (piece == nullptr)
		{
			std::cout << "   ";											// no piece here, so print filler
		}
		else
		{
			std::cout << *piece;										// print piece
		}
		std::cout << " ";

		if (i % 8 == 0)
		{
			std::cout << std::endl;										// print newline every 8 columns
		}
		i++;
	}
}

/* Moves a piece at one coordinate to another coordinate. */
bool Board::movePiece(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords)
{
	std::cout << "Attempting to move from "
	<< fromCoords.first << "," << fromCoords.second
	<< " to " << toCoords.first << "," << toCoords.second << std::endl;

	// Check if from and to locations are on the board
	if (!isOnBoard(fromCoords) || !isOnBoard(toCoords))
	{
		std::cout << "Error: Coords are out of bounds" << std::endl;
		return false;
	}

	// Check if from location is occupied
	//this needs to change to is occupied by the same type
	if (!isOccupied(fromCoords))
	{
		std::cout << "Error: Cannot move from "
		<< fromCoords.first << "," << fromCoords.second
		<< " because there's no piece there" << std::endl;
		return false;
	}

	// Check if this is a valid move for this piece
	const Piece *piece = getPiece(fromCoords);
	if (!piece->isValidMove(this, fromCoords, toCoords))
	{
		std::cout << "Error: This is an invalid move for this type of piece" << std::endl;
		return false;
	}

	// All other checks have passed to we can set the piece

	// When the interior setPiece() function is called it sets the piece currently at that location (fromCoords) to
	// nullptr and then returns a pointer to the piece that was previously at that location. That piece is then assigned
	// to the square referenced by the parameter toCoords. Properly handles absence of a piece at a location.
	setPiece(toCoords, setPiece(fromCoords, nullptr));

	return true;
}

std::pair<int, int> Board::algebraicToInt(std::string algebraicCoords) const
{
	// TODO: Implement. Commented out code below may be helpful.
//	const std::string letters = "abcdefgh";
//	for (int i = 8; i >= 1; i--) 	// for iterating over numerals 1 through 8
//	{
//		for (int j = 0; j < 8; j++) // for iterating over letters a through g
//		{
//			std::pair<int,int> coords = std::make_pair(letters[j] - '0', i);// create coordinates
//			const Piece* piece = squares.find(coords)->second->getPiece();	// get piece (or nullptr) at that coordinate
//			if (piece == nullptr) {
//				std::cout << "   ";											// no piece here so print empty space
//			}
//			else
//			{
//				std::cout << *piece;										// print piece
//			}
//			std::cout << " ";												// print spacing to separate pieces
//		}
//		std::cout << std::endl;												// move to next line
//	}
	return std::pair<int, int>();
}

std::string Board::intToAlgebraic(std::pair<int, int> intCoords) const
{
	// TODO: Implement. Commented out code below may be helpful.
//	const std::string letters = "abcdefgh";
//	for (int i = 8; i >= 1; i--) 	// for iterating over numerals 1 through 8
//	{
//		for (int j = 0; j < 8; j++) // for iterating over letters a through g
//		{
//			std::pair<int,int> coords = std::make_pair(letters[j] - '0', i);// create coordinates
//			const Piece* piece = squares.find(coords)->second->getPiece();	// get piece (or nullptr) at that coordinate
//			if (piece == nullptr) {
//				std::cout << "   ";											// no piece here so print empty space
//			}
//			else
//			{
//				std::cout << *piece;										// print piece
//			}
//			std::cout << " ";												// print spacing to separate pieces
//		}
//		std::cout << std::endl;												// move to next line
//	}
//	return std::pair<int, int>();
	return std::string();
}

/* Checks if a given location is on the board */
bool Board::isOnBoard(const std::pair<int, int> &coords)
{
	if (coords.first < 0 || coords.first > 7)
	{
		return false;
	}
	else if (coords.second < 0 || coords.second > 7)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* Checks if a particular square is occupied. Returns true if so, false otherwise. */
bool Board::isOccupied(const std::pair<int, int> &coords) const
{
	return getPiece(coords) != nullptr;
}

/* If the column remains unchanged over the course of the move, then it's a vertical move. */
bool Board::isVerticalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	return fromCoords.second == toCoords.second;
}

/* If the row remains unchanged over the course of the move, then it's a horizontal move. */
bool Board::isHorizontalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	return fromCoords.first == toCoords.first;
}

/* If the (absolute value of the) horizontal movement is equal to the (absolute value of the) vertical movement,
 * then the movement is diagonal. */
bool Board::isDiagonalMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	int verticalDifference = toCoords.first - fromCoords.first;
	int horizontalDifference = toCoords.second - fromCoords.second;

	return abs(verticalDifference) == abs(horizontalDifference);
}

/* Returns the number of steps necessary to complete a move from one locations a to b. If a and b are the same location
 * then it returns 0, if adjacent, 1, etc. Moving up one square and to the right one square (i.e. a diagonal move to
 * the northeast) would return 1, rather than sqrt(2). Let's not get crazy. */
int Board::getMoveLength(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	if (isVerticalMove(fromCoords, toCoords))
	{
		return abs(toCoords.first - fromCoords.first);
	}
	else if (isHorizontalMove(fromCoords, toCoords))
	{
		return abs(toCoords.second - fromCoords.second);
	}
	else if (isDiagonalMove(fromCoords, toCoords))
	{
		// We've already verified that this is a diagonal move, so we can just return the difference along one axis
		return abs(toCoords.first - fromCoords.first);
	}
	else
	{
		// Measuring non-linear distance is essentially undefined, so we'll return -1
		return -1;
	}
}

/* Checks whether there is a clear path between two points. Note that this only checks the intermediate spaces. In
 * other words, if the destination (as recorded in toCoords) is occupied, but all spaces between are empty, then this
 * function will still evaluate to true. The thinking behind this is that for all pieces except the pawn (which has its
 * own rule specificed in the Pawn class) whether a piece occupies its destination doesn't prevent its movement, it only
 * determines whether that movement results in a capture. */
bool Board::isPathClear(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords) const
{
	// Gather some information about the move
	int moveLength = getMoveLength(fromCoords, toCoords);
	bool isVertical = isVerticalMove(fromCoords, toCoords);
	bool isHorizontal = isHorizontalMove(fromCoords, toCoords);
	bool isDiagonal = isDiagonalMove(fromCoords, toCoords);
	bool movingSouth = fromCoords.first < toCoords.first; 			// "south" meaning from white side to black side
	bool movingEast = fromCoords.second < toCoords.first;			// "east" meaning from white left to white right

	// If same or adjacent location, then path is definitely clear
	if (moveLength == 0 || moveLength == 1)
	{
		return true;
	}

	// Check intermediate locations between fromCoords and toCoords for vacancy
	std::pair<int,int> fromTemp = fromCoords;
	std::pair<int,int> toTemp = toCoords;
	if (isVertical)
	{
		// We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
		if (!movingSouth)
		{
			std::swap(fromTemp, toTemp);
		}

		for (int i = fromTemp.first + 1; i < toTemp.first; i++)
		{
			if (isOccupied(std::make_pair(i, fromTemp.second)))
			{
				return false;
			}
		}

		// Checked all intermediate locations and found them to be empty, so can return true
		return true;
	}
	else if (isHorizontal)
	{
		// We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
		if (!movingEast)
		{
			std::swap(fromTemp, toTemp);
		}

		for (int i = fromTemp.second + 1; i < toTemp.second; i++)
		{
			if (isOccupied(std::make_pair(fromTemp.first, i)))
			{
				return false;
			}
		}

		// Checked all intermediate locations and found them to be empty, so can return true
		return true;
	}
	else if (isDiagonal)
	{
		if (movingSouth == movingEast) 			// moving southeast or northwest
		{
			// loop assumes southeast travel, swap if that's not the case
			if (!movingSouth && !movingEast)
			{
				std::swap(fromTemp, toTemp);
			}

			for (int i = fromTemp.first + 1; i < toTemp.first; i++)
			{
				if (isOccupied(std::make_pair(i, i)))
				{
					return false;
				}
			}

			// Checked all intermediate locations and found them to be empty, so can return true
			return true;

		}
		else if (movingSouth != movingEast)		// moving northeast or southwest
		{
			// loop assumes northeast travel, swap if that's not the case
			if (movingSouth && !movingEast)
			{
				std::swap(fromTemp, toTemp);
			}

			for (int i = fromTemp.first + 1; i < toTemp.first; i++)
			{
				if (isOccupied(std::make_pair(i, 7 - i)))
				{
					return false;
				}
			}

			// Checked all intermediate locations and found them to be empty, so can return true
			return true;
		}
	}

	// path is neither vertical, horizontal, nor diagonal, so it's not a clear path
	return false;
}

/* Determines, based on a piece's color, whether a particular move represents forward movement for that piece. Note that
 * the move does not have to be vertical - diagonal moves can be forward too as long as they are not diagonally backward. */
bool Board::isForwardMove(const std::pair<int, int> &fromCoords, const std::pair<int, int> &toCoords, const Piece *piece) const
{
	Color pieceColor = piece->getColor();
	if (pieceColor == BLACK && fromCoords.first < toCoords.first)
	{
		return true;
	}
	else if (pieceColor == WHITE && fromCoords.first > toCoords.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Destructor */
Board::~Board() = default;
