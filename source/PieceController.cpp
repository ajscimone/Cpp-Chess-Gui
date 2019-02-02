#include "PieceController.hpp"

PieceController::PieceController() {

}

bool PieceController::movePiece(Board *B, std::string startCord, std::string endCord, Color player) {

	Piece pieceCheck = B->getPiece(startCord);
	if (pieceCheck.getColor() == player) {
		bool moveCheck = false;
		switch (pieceCheck.getType()) {
		case PAWN:
			moveCheck = movePawn(B, startCord, endCord, player);
			return moveCheck;
		case ROOK:
			moveCheck = moveRook(B, startCord, endCord, player);
			break;
		case KNIGHT:
			break;
		case BISHOP:
			break;
		case QUEEN:
			break;
		case KING:
			break;
		default:
			return false;
		}
	}

	return false;
}

bool PieceController::movePawn(Board* B, std::string startCord, std::string endCord, Color player) {
	if (player == WHITE) {
		Piece moving = B->getPiece(startCord);
		B->setPiece(endCord, moving);
		Piece empty = Piece(NONE, WHITE);
		B->setPiece(startCord, empty);
		return true;
	}

	return false;
};
bool PieceController::attackPawn(Board* B, std::string startCord, std::string endCord, Color player) {
	std::vector<Square> possibleMoves;

	return false;
}
bool PieceController::moveRook(Board* B, std::string startCord, std::string endCord, Color player) {

	//check that either row or column are the same
	int sx, sy, ex, ey;
	int* start = B->getCoords(startCord);
	sx = start[0];
	sy = start[1];
	int* end = B->getCoords(endCord);
	ex = end[0];
	ey = end[1];

	//std::cout << "start to end" << sx << sy << " " << ex << ey;
	if (sx == ex) // moving left and right
	{
		if (sy > ey)
		{
			Piece moving = B->getPiece(startCord);
			B->setPiece(endCord, moving);
			Piece empty = Piece(NONE, WHITE);
			B->setPiece(startCord, empty);
			return true;
		}
		else if(ey > sy)
		{
			Piece moving = B->getPiece(startCord);
			B->setPiece(endCord, moving);
			Piece empty = Piece(NONE, WHITE);
			B->setPiece(startCord, empty);
			return true;
		}
	}
	else if (sy == ey) //moving up an down
	{
		if (sx > ex) // moving up
		{
			for (int i = ex; i < sx; i++) {
				/*
				if (B->getPiece(startCord).getType() != NONE) {
				return false;
				}
				*/
			}
			Piece moving = B->getPiece(startCord);
			B->setPiece(endCord, moving);
			Piece empty = Piece(NONE, WHITE);
			B->setPiece(startCord, empty);
			return true;
		}
		else if (ex > sx) //moving down
		{
			for (int i = sx; i < ex; i++) {
				/*
				if (B->getPiece(startCord).getType() != NONE) {
					return false;
				}
				*/

			}
			Piece moving = B->getPiece(startCord);
			B->setPiece(endCord, moving);
			Piece empty = Piece(NONE, WHITE);
			B->setPiece(startCord, empty);
			return true;
		}
	}

	return false;
}
bool PieceController::moveKnight(Board* B, std::string startCord, std::string endCord, Color player) {
	return false;
}
bool PieceController::moveBishop(Board* B, std::string startCord, std::string endCord, Color player) {
	return false;
}
bool PieceController::moveQueen(Board* B, std::string startCord, std::string endCord, Color player) {
	return false;
}