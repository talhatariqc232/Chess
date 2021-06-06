#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board;

class Queen : public Piece{
    public:
        Queen(int x, int y, int color, sf::Sprite sprite);
        bool isLegalMove(Board *board, int x, int y);
        
        bool checkHorizontal(Board *board, int x, int y);
        bool checkVertical(Board *board, int x, int y);
        bool checkDiagonal(Board *board, int x, int y);
};