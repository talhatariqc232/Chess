#include <SFML/Graphics.hpp>
#include <cmath>
#include "Rook.h"

class Board;

Rook::Rook(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){}

bool Rook::isLegalMove(Board *board, int x, int y){
    if(checkSelf(board, x, y))
        return false;
    return checkVertical(board, x, y) || checkHorizontal(board, x, y);
}

bool Rook::checkHorizontal(Board *board, int x, int y){

    if(y != this->y)
        return false;
    if(abs(x - this->x) == 1)
        return true;
    int offset = x-this->x > 0 ? 1 : -1;
    for(int i = this->x+offset; i != x; i+=offset)
        if(board->getPiece(i, y) != nullptr)
            return false;
    return true;
}

bool Rook::checkVertical(Board *board, int x, int y){

    if(x != this->x)
        return false;
    if(abs(y - this->y) == 1)
        return true;
    int offset = y-this->y > 0 ? 1 : -1;
    for(int i = this->y+offset; i != y; i+=offset)
        if(board->getPiece(x, i) != nullptr)
            return false;
    return true;
}