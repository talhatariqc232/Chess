#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board;

class Knight : public Piece{
    public:
        Knight(int x, int y, int color, sf::Sprite sprite);
        bool isLegalMove(Board *board, int x, int y);
};