#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board;

class Rook : public Piece{
    public:
        Rook(int x, int y, int color, sf::Sprite sprite);
        bool isLegalMove(Board *board, int x, int y);
        bool checkHorizontal(Board *board, int x, int y);
        bool checkVertical(Board *board, int x, int y);
};