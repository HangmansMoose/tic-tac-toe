#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

// I know global variables are yuck but I could not think of a more elegant solution 
// Without abstracting everything out to classes, which seemed ridiculous on such a small code
// base
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();
char askYesNo(std::string question);
int askNumber(std::string question, int high, int low = 0);
char opponent(char piece);
char player();
void announceWinner(char winner, char human, char computer);
void displayBoard(const std::vector<char>& board);
// I don't know why VS thinks winner is different from all the other functions???
char winner(const std::vector<char>& board);
bool isLegal(const std::vector<char>& board, int move);
int playerMove(const std::vector<char>& board, char human);
int computerMove(const std::vector<char> board, char computer);
