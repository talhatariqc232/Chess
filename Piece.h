#pragma once

#include <SFML/Graphics.hpp>
#include <utility>
#include "Board.h"
class Board;

class Piece{
    protected:
        int x;
        int y;
        int color;  //1 for white -1 for black
        bool first_move;
        sf::Sprite sprite;
    public:
        Piece(int x, int y, int color, sf::Sprite sprite);
        virtual bool isLegalMove(Board *board, int x, int y) = 0;
        virtual void setPosition(Board *board, int x, int y);
        std::pair<int,int> getPosition();
        bool checkSelf(Board *board, int x, int y);

        int getColor();
        sf::Sprite getSprite();
};
