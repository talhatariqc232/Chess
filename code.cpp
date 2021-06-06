#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"


#define ROW 8
#define COL 8

#define SIZE 50


void init(Board board){

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(SIZE*COL, SIZE*ROW), "Game of Life");
    Board board;
    init(board);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    int x = position.x/SIZE;
                    int y = position.y/SIZE;
                    if((x >= 0 and x < COL) and (y >= 0 and y < ROW)){
                        board.select(x,y);
                    }
                }
            }
        }
        window.clear();
        board.DrawBackground(window);
        board.DrawPieces(window);
        window.display();
    }

    return 0;
}