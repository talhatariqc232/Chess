#include <SFML/Graphics.hpp>
#include <cmath>
#include "Pawn.h"
class Board;

Pawn::Pawn(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){
    first_move = true;
}

bool Pawn::isLegalMove(Board *board, int x, int y){
    Piece *cell = board->getPiece(x, y);
    if(cell == nullptr){
        if(first_move){
            return (this->x == x) and (((this->y-y)*color + 1)/2 == 1);
        }
        return (this->x == x) and (this->y-y == color);
    }
    else if (cell->getColor() != color){
        bool return_val = (abs(this->x-x) == 1) and (this->y-y == color);
        if(return_val)
            first_move = false;
        return return_val;
    }
    return false;
}

void Pawn::setPosition(Board *board, int x, int y){
    Piece::setPosition(board, x, y);
    if(y == (1- (color+1)/2) * 7){
        board->setPiece(board->createPiece(1, x, y, color), x, y);
        delete this;
    }
}