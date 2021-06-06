#include <SFML/Graphics.hpp>
#include <cmath>
#include "Bishop.h"

class Board;

Bishop::Bishop(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){}

bool Bishop::isLegalMove(Board *board, int x, int y){
    if(checkSelf(board, x, y))
        return false;
    return checkDiagonal(board, x, y);
}

bool Bishop::checkDiagonal(Board *board, int x, int y){
    
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
