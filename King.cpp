#include <SFML/Graphics.hpp>
#include <cmath>
#include "King.h"

class Board;

King::King(int x, int y, int color, sf::Sprite sprite) : Piece(x, y, color, sprite){}

bool King::isLegalMove(Board *board, int x, int y){

    if(checkSelf(board, x, y))
        return false;
    return (abs(this->x - x) <= 1 and abs(this->y - y) <= 1);
}