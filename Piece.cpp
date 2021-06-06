#include <utility>
#include "Piece.h"

Piece::Piece(int x, int y, int color, sf::Sprite sprite){
    this->x = x;
    this->y = y;
    this->color = color;
    this->sprite = sprite;
}

int Piece::getColor(){
    return color;
}

sf::Sprite Piece::getSprite(){
    return sprite;
}

void Piece::setPosition(Board *board, int x, int y){

    board->setPiece(nullptr, this->x, this->y);
    board->setPiece(this, x, y);
    
    first_move = false;
    this->x = x;
    this->y = y;
}
        
std::pair<int,int> Piece::getPosition(){
    return std::make_pair(x, y);
}

bool Piece::checkSelf(Board *board, int x, int y){
    Piece *piece = board->getPiece(x, y);
    if(piece != nullptr and piece->getColor() == color)
        return true;
    return (x == this->x) and (y == this->y);
}
