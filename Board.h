#pragma once
#include <SFML/Graphics.hpp>

class Piece;

class Board{
    Piece *board[8][8];
    Piece *selected;
    int turn;
    sf::Texture spritesheet;
    sf::Sprite sprites[2][6];
    public:
        Board();
        Piece *getPiece(int x, int y);
        void setPiece(Piece *piece, int x, int y);
        Piece *createPiece(int piece, int x, int y, int color);
        void DrawBackground(sf::RenderWindow &window);
        void DrawPieces(sf::RenderWindow &window);
        void select(int x, int y);
};

