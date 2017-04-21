/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
*/

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief checks if the positions i,j are on the field
 * @param i position i on field
 * @param j position j on field
 * @return true if i,j are on the field
 */
bool onField(int i,int j)
{
	if(i < 0 || i > 7) return false;
	if(j < 0 || j > 7) return false;
	return true;
}

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		};//for i
		std::cout << std::endl;
	}//for j
}

/**
 * @brief Checks who is the winner of the game
 * @param field
 * @return the winner or 0 if drawn
 *
 * This function checks who is the winner of the game.
 * It return 0 for drawn 1 for player 1 and 2 for player 2
 *
 */
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0;
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			if(field[j][i] == 1) count_p1++;
			else if(field[j][i] == 2) count_p2++;
		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p2 > count_p1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Chechs if a turn is valid
 * @param field the field with the current state
 * @param player the active player
 * @param pos_x turn position
 * @param pos_y turn position
 * @return true if the turn is valid
 *
 * This function checks if the turn a player wants to make is valid
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{
	// Process all possible directions
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
							   // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	//take a look at the field arround the turn position
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//is it a opponent field?
			if(field[pos_y+i][pos_x+j] == opponent)
			{
				int stepsI = i+i;
				int stepsJ = j+j;
				int nextField = 0;

				//Follow the stones until you leave the field
				while(onField(pos_y+stepsI,pos_x+stepsJ))
				{
					nextField = field[pos_y+stepsI][pos_x+stepsJ];

					//is the row finished with a players stone
					if(nextField == player) return true;

					//is there a break in the row of opponent stones
					if(nextField == 0) break;

					stepsI += i;
					stepsJ += j;
				}
			}
		}
	}
	return false;
}

/**
 * @brief Checks if two fields are equal
 * @param field
 * @param field2
 * @return true if the fields are equal
 */
bool areFieldsEqual(const int field[SIZE_Y][SIZE_X],int field2[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			if(field[i][j] != field2[i][j]) return false;
		}
	}
	return true;
}

/**
 * @brief executes a turn
 * @param field the field
 * @param player the number of the active player
 * @param pos_x x position of the turn
 * @param pos_y y position of the turn
 *
 * This function places a stone of the player at the position (pos_y pos_y)
 * and changes all opponent stones witch are between this stone an another of the player
 */
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y)
{

	int opponent = 3 - player;

	field[pos_y][pos_x] = player;

	//take a look at the field arround the turn position
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			//is it a opponent field?
			if(field[pos_y+i][pos_x+j] == opponent)
			{
				int stepsI = i+i;
				int stepsJ = j+j;
				int nextField = 0;
				bool changeStones = false;

				//Follow the stones until you leave the field
				while(onField(pos_y+stepsI,pos_x+stepsJ))
				{
					nextField = field[pos_y+stepsI][pos_x+stepsJ];

					//is the row finished with a players stone
					if(nextField == player) changeStones = true;

					//is there a break in the row of opponent stones
					if(nextField == 0) break;
						stepsI += i;
					stepsJ += j;
				}
				if(changeStones)
				{
					//Reset steps
					stepsI = i;
					stepsJ = j;

					//Follow the stones until you leave the field
					while(onField(pos_y+stepsI,pos_x+stepsJ))
					{
						nextField = field[pos_y+stepsI][pos_x+stepsJ];

						//is the row finished with a players stone
						if(nextField == player) break;

						//Change the stones
						field[pos_y+stepsI][pos_x+stepsJ] = player;

						stepsI += i;
						stepsJ += j;
					}
				}
			}
		}
	}
}

/**
 * @brief returns the number of possible turns for a given player
 * @param field the field
 * @param player the active player
 * @return the number of turns
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int turns = 0;
	for (int j = 0; j < SIZE_Y; j++)
		{
		for (int i = 0; i < SIZE_X; i++)
		{
			if(turn_valid(field,player,i,j)) turns++;
		}
	}
	return turns;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	int px;
	int py;
	bool repeat=false;

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move (e.g. A1): " ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Invalid input !" << std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}
/**
 * @brief makes a human or computer turn depending on the playerType
 * @param playerType indicates the type of turn
 * @param field the field to play on
 * @param player the active player
 * @return returns the number of possible turns before the player mad his turn
 */
int autoTurn(int playerType ,int field[SIZE_Y][SIZE_X], const int player)
{
	int turnsPlayer = 0;
	if(playerType == HUMAN)
	{
		turnsPlayer = possible_turns(field,player);
		if(turnsPlayer > 0)
		{
			human_turn(field,player);
			show_field(field);
		}
	}
	else if(playerType == COMPUTER)
	{
		turnsPlayer = possible_turns(field,player);
		if(turnsPlayer > 0)
		{
			computer_turn(field,player);
			show_field(field);
		}
	}
	return turnsPlayer;
}

void game(const int player_typ[2])
{

	int field[SIZE_Y][SIZE_X];

	//Create starting pattern
	initialize_field(field);

	int current_player = 1;
	show_field(field);
	while(true)
	{
		//Let them play
		int turnsPlayer1 = autoTurn(player_typ[0],field,1);
		int turnsPlayer2 = autoTurn(player_typ[1],field,2);

		//No more turns for both
		if(turnsPlayer1 == 0 && turnsPlayer2 == 0) break;
	}

	switch (winner(field))
	{
	case 0:
		std::cout  << "Drawn" << std::endl;
		break;
	case 1:
		std::cout  << "Player 1 wins" << std::endl;
		break;
	case 2:
		std::cout  << "Player 2 wins" << std::endl;
		break;
	}
}

int main(void)
{
	//Test stuff
	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	//Ask for the player typs
	std::cout  << "The first player should be a COMPUTER: 2 , HUMAN: 1 :" << std::endl;
	int player1 = 1;
	std::cin >> player1;

	std::cout  << "The second player should be a COMPUTER: 2 , HUMAN: 1 :" << std::endl;
	int player2 = 1;
	std::cin >> player2;

	int player_type[2] = { COMPUTER, COMPUTER };  //Contains information wether players are HUMAN(=1) or COPMUTER(=2)
	player_type[0] = player1;
	player_type[1] = player2;

	//Start the game
	game(player_type);
	return 0;
}
