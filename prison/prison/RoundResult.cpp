#include "Header.h"

RoundResult::RoundResult(std::vector<char> simulationroundchoices) 
{
	SetChoice(simulationroundchoices[0], simulationroundchoices[1], simulationroundchoices[2]);
	SetPrisonersPayoff();
};


void RoundResult::SetChoice(int player1_choice_input, int player2_choice_input, int player3_choice_input) 
{
	player1_choice = player1_choice_input;
	player2_choice = player2_choice_input;
	player3_choice = player3_choice_input;
};

void RoundResult::SetPrisonersPayoff() 
{
	if ((player1_choice == 'C') && (player2_choice == 'C') && (player3_choice == 'C')) { player1_pay_off = 7; player2_pay_off = 7; player3_pay_off = 7; }
	else if ((player1_choice == 'C') && (player2_choice == 'C') && (player3_choice == 'D')) { player1_pay_off = 3; player2_pay_off = 3; player3_pay_off = 9; }
	else if ((player1_choice == 'C') && (player2_choice == 'D') && (player3_choice == 'C')) { player1_pay_off = 3; player2_pay_off = 9; player3_pay_off = 3; }
	else if ((player1_choice == 'D') && (player2_choice == 'C') && (player3_choice == 'C')) { player1_pay_off = 9; player2_pay_off = 3; player3_pay_off = 3; }
	else if ((player1_choice == 'C') && (player2_choice == 'D') && (player3_choice == 'D')) { player1_pay_off = 0; player2_pay_off = 5; player3_pay_off = 5; }
	else if ((player1_choice == 'D') && (player2_choice == 'C') && (player3_choice == 'D')) { player1_pay_off = 5; player2_pay_off = 0; player3_pay_off = 5; }
	else if ((player1_choice == 'D') && (player2_choice == 'D') && (player3_choice == 'C')) { player1_pay_off = 5; player2_pay_off = 5; player3_pay_off = 0; }
	else if ((player1_choice == 'D') && (player2_choice == 'D') && (player3_choice == 'D')) { player1_pay_off = 1; player2_pay_off = 1; player3_pay_off = 1; }
};
std::vector<int> RoundResult::GetScore() 
{
	std::vector<int> _score(3);
	_score = { player1_choice,player2_choice,player3_choice };
	return _score;
};
bool PlayersOfNewRounde(int* players_of_this_rounde, int playerscount, int players_count_in_single_game)
{
	int k = players_count_in_single_game;
	for (int i = k - 1; i >= 0; --i)
		if (players_of_this_rounde[i] < playerscount - k + i + 1)
		{
			++players_of_this_rounde[i];
			for (int j = i + 1; j < k; ++j)
				players_of_this_rounde[j] = players_of_this_rounde[j - 1] + 1;
			return true;
		}
	return false;
};