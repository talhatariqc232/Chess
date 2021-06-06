#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

#define SIZE 50

#define KING 0
#define QUEEN 1
#define BISHOP 2
#define KNIGHT 3
#define ROOK 4
#define PAWN 5

int order[8] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};


Board::Board(){
   
   turn = 1;
   selected = nullptr;

   for(int i = 0; i < 8; i++)
      for(int j = 0; j < 8; j++)
         board[i][j] = nullptr;

   float scale = ((float)SIZE)/((float)320);  
   for(int i = 0; i < 6; i++){
      sprites[0][i].setTexture(spritesheet);
      sprites[0][i].setTextureRect(sf::IntRect(320*i, 320*0, 320, 320));
      sprites[0][i].setScale(scale, scale);
      
      sprites[1][i].setTexture(spritesheet);
      sprites[1][i].setTextureRect(sf::IntRect(320*i, 320*1, 320, 320));
      sprites[1][i].setScale(scale, scale);
   }

   spritesheet.loadFromFile("spritesheet.png");
   for(int i = 0; i < 8; i++){
      board[i][0] = createPiece(order[i], i, 0, -1);
      board[i][1] = createPiece(PAWN, i, 1, -1);
      board[i][6] = createPiece(PAWN, i, 6, 1);
      board[i][7] = createPiece(order[i], i, 7, 1);
   }
}  

Piece *Board::createPiece(int piece, int x, int y, int color){
   if(piece == PAWN)
      return new Pawn(x, y, color, sprites[1-(color+1)/2][piece]);
   if(piece == ROOK)
      return new Rook(x, y, color, sprites[1-(color+1)/2][piece]);
   if(piece == BISHOP)
      return new Bishop(x, y, color, sprites[1-(color+1)/2][piece]);
   if(piece == KNIGHT)
      return new Knight(x, y, color, sprites[1-(color+1)/2][piece]);
   if(piece == QUEEN)
      return new Queen(x, y, color, sprites[1-(color+1)/2][piece]);
   if(piece == KING)
      return new King(x, y, color, sprites[1-(color+1)/2][piece]);
   return nullptr;
}


Piece *Board::getPiece(int x, int y){
   return board[x][y];
}

void Board::setPiece(Piece *piece, int x, int y){
   board[x][y] = piece;
}


void Board::DrawBackground(sf::RenderWindow &window){

   for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
         sf::RectangleShape cell;
         cell.setSize(sf::Vector2f(SIZE, SIZE));
         cell.setPosition(sf::Vector2f(SIZE*i, SIZE*j));
         sf::Color color;
         if((i+j)%2 == 0)
            color = sf::Color(243,222,198);
         else
            color = sf::Color(179,134,108);
         cell.setFillColor(color);
         window.draw(cell);

         if(selected != nullptr){
            if(selected->isLegalMove(this, i, j)){
               float size = ((float)(SIZE))/6.0f;
               sf::CircleShape circle(size);
               circle.setFillColor(sf::Color(17,70,17,180));
               circle.setPosition(sf::Vector2f(SIZE*i+size*2, SIZE*j+size*2));
               window.draw(circle);
            }
         }
      }
   }
}

void Board::DrawPieces(sf::RenderWindow &window){

   for(int i = 0; i < 8; i++){
      for(int j = 0; j < 8; j++){
         if(board[i][j] != nullptr){
            sf::Sprite sprite = board[i][j]->getSprite();
            sprite.setPosition(sf::Vector2f(i*SIZE, j*SIZE));
            window.draw(sprite);
         }
      }
   }
}


void Board::select(int x, int y){
   std::cout << turn << " " << x << " " << y << std::endl;
   if(selected == nullptr){
      if(board[x][y] != nullptr and board[x][y]->getColor() == turn)
         selected = board[x][y];
   }
   else{
      if(selected->isLegalMove(this, x, y)){
         if(board[x][y] != nullptr){
            delete board[x][y];
         }
         selected->setPosition(this, x, y);
         turn *= -1;
      }
      selected = nullptr;
   }
}