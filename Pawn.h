#pragma once

#include <SFML/Graphics.hpp>
#include "Piece.h"

class Board;

class Pawn : public Piece{
    public:
        Pawn(int x, int y, int color, sf::Sprite sprite);
        bool isLegalMove(Board *board, int x, int y);
        virtual void setPosition(Board *board, int x, int y);
};