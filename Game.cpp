#include "Game.h"


//They player has so little I am not sure there is a point in making a class
//am I wrong in thinking this?
struct Player{
	char piece;
	bool human;
	bool winner;
};

Game::Game() {
	/*This is where the game loop will happen
	 * First question the user as to whether it is 2 player or vs cpu
	 * Then ask whether the player wants to be x or o. Once that has 
	 * happened then the first player object can be made and either
	 * the player2 or cpu player can be constructed.
	 * Once we have all this a new board can be made, then the two players
	 * and the board can be passed into the game loop. 
	 */

	//Create players

	Player player1();
	Player player2();

	player1.human = true;
	player2.human = false;

	//create board

	Board board();

	//Game Loop


}