all:
	g++ code.cpp Board.cpp Piece.cpp Pawn.cpp Rook.cpp Bishop.cpp Knight.cpp Queen.cpp King.cpp -o game.exe -DSFML_STATIC -I C:\SFML\include -L C:\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype
