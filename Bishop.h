#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board;

class Bishop : public Piece{
    public:
        Bishop(int x, int y, int color, sf::Sprite sprite);
        bool isLegalMove(Board *board, int x, int y);
        bool checkDiagonal(Board *board, int x, int y);

};