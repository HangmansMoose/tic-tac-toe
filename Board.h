#pragma once
#include <vector>

const int default_board_size = 3;

class Board {
private:

	// Using vectors so that later it will be easier to allow dynamic board sizes
	std::vector<std::vector<char>> board = {};

public:
	Board();
	~Board(): 
	
	
	void drawBoard(const Board*);
	bool newPosition(const int,const int);




};