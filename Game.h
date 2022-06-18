#pragma once
#include "Board.h"
#include "Player.h"
#include "ComputerPlayer.h"



class Game {
public:
	//Board, players, win state
	Game();
	~Game();
	void gameLoop();
	

private:
	bool checkWin();
};