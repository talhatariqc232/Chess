#include <SFML/Graphics.hpp>
#include <cmath>
#include "Queen.h"

class Board;

Queen::Queen(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){}

bool Queen::isLegalMove(Board *board, int x, int y){
    if(checkSelf(board, x, y))
        return false;
    return checkDiagonal(board, x, y) || checkVertical(board, x, y) || checkHorizontal(board, x, y);
}

bool Queen::checkDiagonal(Board *board, int x, int y){
    
    if(abs(x-this->x) != abs(y-this->y))
        return false;
    if(abs(x-this->x) == 1 and abs(y-this->y) == 1)
        return true;

    int offsetx = x-this->x > 0 ? 1 : -1;
    int offsety = y-this->y > 0 ? 1 : -1;
    for(int i = this->x+offsetx, j = this->y+offsety; i != x; i+=offsetx, j += offsety)
        if(board->getPiece(i, j) != nullptr)
            return false;
    return true;
}

bool Queen::checkHorizontal(Board *board, int x, int y){

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

bool Queen::checkVertical(Board *board, int x, int y){

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