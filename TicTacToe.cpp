#include "TicTacToe.h"



int main(int argc, char *argv[])
{
	int move;
	const int NUM_SQUARES = 9;

	std::vector<char> board(NUM_SQUARES, EMPTY);
	instructions();
	char human = humanPiece();
	//what ever the player picked the cpu will be opposite
	char computer = opponent(human);
	char turn = X;

	displayBoard(board);

	// Game Loop
	while (winner(board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(board);
		turn = opponent(turn);
	}
	announceWinner(winner(board), computer, human);

	
	return 0; 
}



void instructions()
{
	std::cout << "Board is represented by numbers 0-8, to make a move input the square number that you wish to occupy\n";
	std::cout << " 0 | 1 | 2 \n";
	std::cout << "-----------\n";
	std::cout << " 3 | 4 | 5 \n";
	std::cout << "-----------\n";
	std::cout << " 6 | 7 | 8 \n";

}


int askNumber(std::string question, int high, int low)
{
	int number;

	do {
		std::cout << question << "(" << low << " - " << high << "): ";
		std::cin >> number;

	} while (number > high || number < low);

	return number;
}

char askYesNo(std::string question)
{
	char response;

	do
	{
		std::cout << question << " (y/n): ";
		std::cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}


char humanPiece()
{
	char go_first = askYesNo("Would you like to go first?: ");

	if (go_first == 'y')
	{
		std::cout << "\nThen you will move first\n";
		return X;

	}
	else
	{
		std::cout << "\n very well second it is\n";
		return O;
	}

}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}



void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		std::cout << "You lost.\n";
	}
	else if (winner == human)
	{
		std::cout << "Winnnnnerrrrrr\n";
	}
	else
	{
		std::cout << "Match was a tie\n";
	}
}

void displayBoard(const std::vector<char>& board)
{
	std::cout << "\n\t" << board[0] << board[1] << board[2];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[3] << board[4] << board[5];
	std::cout << "\n\t" << "---------";
	std::cout << "\n\t" << board[6] << board[7] << board[8];

}


char winner(const std::vector<char>& board)
{
	const int TOTAL_ROWS = 8;

	const int winningPositions[8][3] =
	{
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6},
	};

	for (int row = 0; row < TOTAL_ROWS; row++)
	{
		if ((board[winningPositions[row][0]] != EMPTY) &&
			(board[winningPositions[row][0] == board[winningPositions[row][1]]]) &&
			(board[winningPositions[row][0]] == board[winningPositions[row][2]]))
		{
			return board[winningPositions[row][0]];
		}

		if (std::count(board.begin(), board.end(), EMPTY) == 0)
		{
			return TIE;
		}

		return NO_ONE;

	}

}

inline bool isLegal(const std::vector<char>& board, int move)
{
	return (board[move] == EMPTY);
}

int humanMove(const std::vector<char>& board, char human)
{
	int move = askNumber("Position? ", (board.size() - 1));

	while (!isLegal(board, move))
	{
		std::cout << "\n Illegal move, square is occupied\n";
		move = askNumber("Position? ", (board.size() - 1));
	}

	return move;
}


int computerMove(std::vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	if (isLegal(board, move))
	{
		board[move] = computer;
		found = winner(board) == computer;
		board[move] = EMPTY;

	}

	if (!found)
	{
		++move;
	}

	if (!found)
	{
		move = 0;

		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (isLegal(board, move))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}



	}

	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(board, move))
			{
				found = true;
			}
			i++;
		}

	}
	return move;
}
