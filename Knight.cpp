#include <SFML/Graphics.hpp>
#include <cmath>
#include "Knight.h"

class Board;

Knight::Knight(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){}

bool Knight::isLegalMove(Board *board, int x, int y){
    
    if(checkSelf(board, x, y))
        return false;

    if(abs(this->y-y) == 2)
        return abs(this->x-x) == 1;
    if(abs(this->x-x) == 2)
        return abs(this->y-y) == 1;
    
    return false;
}